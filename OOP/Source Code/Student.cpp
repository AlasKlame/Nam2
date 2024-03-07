#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class ToaDo{
    private:
        float x;
        float y;
    public:
        ToaDo(){
            
        }

        void input(){
            cin >> x >> y;
        }
        void output(){
            cout << x << " " << y << endl;
        }
        float distance( ToaDo& b){
            return sqrt((x - b.x)* (x - b.x) + (y - b.y)* (y - b.y));
        }
};

int main(){
    ToaDo a;
    ToaDo b;
    
    a.input();
    b.input();
    
    cout << a.distance(b) << endl;
}