#include <iostream>


using namespace std;

class monomial{
    private:
        int coefficient;
        int exponent;
    public:
        monomial(int coefficient, int exponent){
            this->coefficient = coefficient;
            this->exponent = exponent;
        }
        void input(){
            cout << "Enter coefficient: ";
            cin >> coefficient;
            cout << "Enter exponent: ";
            cin >> exponent;
        }

        void output(){
            cout << coefficient << "x^" << exponent;
        }

        int getExponent(){
            return exponent;
        }

        int getCoefficient(){
            return coefficient;
        }

        bool operator>(monomial& m){
            if(m.coefficient > coefficient && m.exponent > exponent){
                return true;
            }
            return false;
        }

        bool operator<(monomial& m){
            if(m.coefficient < coefficient && m.exponent < exponent){
                return true;
            }
            return false;
        }

        monomial operator~(){
            monomial temp(coefficient, exponent);
            temp.coefficient = -temp.coefficient;
            return temp;
        }
}