#define _VIPCustomer_h
#include "Customer.h"


class VIPCustomer : public Customer{
    protected:
        int level;
    public:
        void input(ifstream& inputFile);
        void output(ofstream& outputFile);

}