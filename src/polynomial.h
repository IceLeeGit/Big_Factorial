#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED

#include <vector>
    
using std::vector;

class Poly {
    public:
        Poly();
        Poly(int [],int [],int length,int base);
        Poly(vector<int> ,vector<int> ,int base);
        ~Poly();
        void print();
        void print_number();
        Poly operator + (Poly p1);
        void operator = (Poly p1);
        Poly operator * (Poly p1);
        void mergerpoly();
        void formatpoly();

    private:
        vector<int> index;
        vector<int> coefficient;
        int base_number;
};

#endif // POLYNOMIAL_H_INCLUDED
