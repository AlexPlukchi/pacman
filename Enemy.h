#ifndef Enemy_h
#define Enemy_h

class Enemy : public Character
{
    sf::Texture texture;
public:
    Enemy();
    void init(int _xi, int _yi);
    void draw(sf::RenderWindow* window);
    int Lee(int i_beg, int j_beg, int i_end, int j_end); // Lee algorithm for walk()
    void walk(Pacman* p);
    void rand_walk(Pacman* p);
    bool check_fail(class Pacman* p);
};

Enemy::Enemy()
{
    dir = 0;
    ds = (double)X/120;
    texture.loadFromFile(resourcePath() + "res/ghost.png", sf::IntRect(0, 0, 500, 500));
}

void Enemy::init(int _xi, int _yi)
{
    x = _xi*X + X/2;
    y = _yi*X + X/2;
}

void Enemy::draw(sf::RenderWindow* window)
{
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(X, X));
    shape.setPosition(x, y);
    shape.setOrigin(X/2, X/2);
    shape.setTexture(&texture);
    window -> draw(shape);
}

struct List // just for Lee()
{
    int i;
    int j;
    List* next;
    ~List() {
        delete next;
    }
    void insert(int i_, int j_, List** list) {
        if(*list == NULL) {
            List* temp;
            temp = new List;
            temp -> i = i_;
            temp -> j = j_;
            temp -> next = NULL;
            *list = temp;
        }
        else
            insert(i_, j_, &((*list) -> next));
    }
};

int Enemy::Lee(int i_beg, int j_beg, int i_end, int j_end) // поиск в ширину по факту
{
    int field[N][N];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            field[i][j] = (MAP[i][j] == 1 ? -1 : N*N); // надежда, что N*N больше любого пути
    field[i_beg][j_beg] = 0;
    
    List* list = NULL;
    list -> insert(i_beg, j_beg, &list);
    List* next_list = NULL;
    bool eq = false;
    while(!eq) { // работает, только если путь существует!!!
        List* cur = list;
        while(cur != NULL) {
            int i_cur = cur -> i;
            int j_cur = cur -> j;
            for(int k = 0; k < 4; k++) {
                int i_near = i_cur + (k - 1)%2; // neighbour
                int j_near = j_cur + (k - 2)%2;
                if(field[i_cur][j_cur] + 1 < field[i_near][j_near]) {
                    field[i_near][j_near] = field[i_cur][j_cur] + 1;
                    next_list -> insert(i_near, j_near, &next_list);
                }
                if(i_near == i_end && j_near == j_end) {eq = true; break;}
            }
            cur = cur -> next;
        }
        delete list;
        list = next_list;
        next_list = NULL;
    }
    
    int len = field[i_end][j_end]; // lenght of way
    int* arr = new int[len]; // array with way
    while(len != 0) {
        for(int k = 0; k < 4; k++) {
            int i_near = i_end - (k - 1)%2; // neighbour
            int j_near = j_end + (k - 2)%2;
            if(field[i_end][j_end] - 1 == field[i_near][j_near]) {
                i_end = i_near;
                j_end = j_near;
                arr[len - 1] = k + 1; // 1 - left, 2 - down, 3 - right, 4 - up
                len--;
                break;
            }
        }
    }
    int _dir = arr[0];
    delete[] arr;
    return _dir;
}

void Enemy::walk(Pacman* p)
{
    int i_beg = (int)floor(x/X);
    int j_beg = (int)floor(y/X);
    int i_end = (int)floor(p->x/X);
    int j_end = (int)floor(p->y/X);
    go(Lee(i_beg, j_beg, i_end, j_end));
}

void Enemy::rand_walk(Pacman* p) // random
{
    
    int _dir = rand()%4 + 1;
    if((_dir + dir)%2 != 0)
        go(_dir);
    else
        go(dir);
}

bool Enemy::check_fail(Pacman* p)
{
    if(pow(p -> x - x, 2) + pow(p -> y - y, 2) < X*X)
        return true;
    return false;
}

#endif /* Enemy_h */
