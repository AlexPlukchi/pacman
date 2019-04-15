#ifndef Map_h
#define Map_h

class Map
{
public:
    const int wall = 1, pass = 0;
    const int height = N, width = N;
    
    
    int** MAP1;
    
    
    int map[N][N];
    Map();
    void draw(sf::RenderWindow* window);
    
    void createmaze(int ) {
        
    }
    
    void mazemake(int height, int width){
        int x, y, c, a;
        //bool b;
        
        MAP1 = new int*[height];
        for(int i = 0; i < height; i++)
            MAP1[i] = new int[width];
        //
        for(int i = 0; i < height; i++) // ћассив заполн€етс€ ноликами
            for(int j = 0; j < width; j++)
                MAP1[i][j] = wall;
        //
        x = 3; y = 3; a = 0; // “очка начала и счетчик
        while(a < 10000){ // ???????костыль
            MAP1[y][x] = pass;
            a++;
            while(1){ // Ѕесконечный цикл, который прерываетс€ только тупиком
                c = rand()%4; //  алгоритм проходит
                switch(c){  // по две клетки в одном направлении за прыжок
                    case 0: if(y != 1)
                        if(MAP1[y-2][x] == wall){ // ¬верх
                            MAP1[y-1][x] = pass;
                            MAP1[y-2][x] = pass;
                            y-=2;
                        }
                    case 1: if(y != height-2)
                        if(MAP1[y+2][x] == wall){ // ¬низ
                            MAP1[y+1][x] = pass;
                            MAP1[y+2][x] = pass;
                            y+=2;
                        }
                    case 2: if(x != 1)
                        if(MAP1[y][x-2] == wall){ // Ќалево
                            MAP1[y][x-1] = pass;
                            MAP1[y][x-2] = pass;
                            x-=2;
                        }
                    case 3: if(x != width-2)
                        if(MAP1[y][x+2] == wall){ // Ќаправо
                            MAP1[y][x+1] = pass;
                            MAP1[y][x+2] = pass;
                            x+=2;
                        }
                }
                if(deadend(x,y,MAP1,height,width))
                    break;
            }
            
            if(deadend(x,y,MAP1,height,width)) // ¬ытаскиваем алгоритм из тупика
                do {
                    x = 2*(rand()%((width-1)/2))+1;
                    y = 2*(rand()%((height-1)/2))+1;
                }
            while(MAP1[y][x] != pass);
        }
        
    };
    
    
    bool deadend(int x, int y, int** maze, int height, int width){
        int a = 0;
        
        if(x != 1){
            if(maze[y][x-2] == pass)
                a+=1;
        }
        else a+=1;
        
        if(y != 1){
            if(maze[y-2][x] == pass)
                a+=1;
        }
        else a+=1;
        
        if(x != width-2){
            if(maze[y][x+2] == pass)
                a+=1;
        }
        else a+=1;
        
        if(y != height-2){
            if(maze[y+2][x] == pass)
                a+=1;
        }
        else a+=1;
        
        if(a == 4)
            return 1;
        else
            return 0;
    }
};



Map::Map()
{
    //int** MAP1 = mazemake(<#int height#>, <#int width#>);
    //    for(int i = 0; i < N; i++)
    //    {
    //        for(int j = 0; j < N; j++)
    //        {
    //            MAP1[i][j] = **(mazemake(height, width));
    //        }
    //    }
    
    
    mazemake(height,width);
    
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            MAP0[i][j] = MAP1[i][j];
            map[i][j] = MAP1[i][j];
        }
    }
}

void Map::draw(sf::RenderWindow* window)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(map[i][j] == 1)
            {
                sf::RectangleShape shape;
                shape.setSize(sf::Vector2f(X - 1, X - 1));
                shape.setFillColor(sf::Color::Blue);
                shape.setPosition(X*i, X*j);
                window -> draw(shape);
            }
        }
    }
}
#endif /* Map_h */
