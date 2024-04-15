#ifndef _RegularCustomer_h
#define _RegularCustomer_h
#include "Customer.h"



class RegularCustomer : public Customer{
    public:
        RegularCustomer();
        void Input(ifstream &inputFile);
        void Output(ofstream &outputFile);

};

#endif