#include<iostream>
#include<cmath>
using namespace std;


class ToaDo{
    private:    
        

    float x, y;
    public:
            ToaDo(){

            }

            float getX(){
                return x;
            }

            float getY(){
                return y;
            }

            void SetterX(float x){
                this->x = x;
            }

            void SetterY(float y){
                this->y = y;
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

class TamGiac{
    private:
        ToaDo A;
        ToaDo B;
        ToaDo C;
    public:
        TamGiac(){};
        void input(){
            A.input();
            B.input();
            C.input();
        }   
        void output(){
            A.output();
            B.output();
            C.output();
        }

        bool check(){
            float a = A.distance(B);
            float b = B.distance(C);
            float c = C.distance(A);
            if(a + b > c && a + c > b && b + c > a){
                return true;
            }
            return false;
        }

        float chuvi(){
            float a = A.distance(B);
            float b = B.distance(C);
            float c = C.distance(A);
            
            return (a + b + c);
        }

        float dientich(){
            float a = A.distance(B);
            float b = B.distance(C);
            float c = C.distance(A);
            float p = chuvi()/2;
            return sqrt(p*(p-a)*(p-b)*(p-c));
        }

        ToaDo trongtam(){
            float x = (A.getX() + B.getX() + C.getX())/3;
            float y = (A.getY() + B.getY() + C.getY())/3;
            ToaDo O;
            O.SetterX(x);
            O.SetterY(y);
            return O;
        }
};


int main(){
    TamGiac a;
    a.input();
    if(a.check()){
        cout << "Trong tam ne: ";
        a.trongtam();
        a.trongtam().output();
    
        cout << "Chu vi: " << a.chuvi() << endl;
        cout << "Dien tich: " << a.dientich() << endl;
    }
    else{
        cout << "Khong ton tai" << endl;
    }
    return 0;
}