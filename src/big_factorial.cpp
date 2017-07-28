#include <iostream>
#include "polynomial_operation.cc"


using namespace std;

Poly format_number(int num,int base);
Poly factorial_cal(int num);

int main()
{
    int len=5;
    int ind[5]={1,2,3,1,3}, coef[5]={11,22,33,11,33};
    int ind2[4]={2,3,1,2}, coef2[4]={24,3,64,8};
    int base=10;
    Poly poly1(ind,coef,len,base);
    Poly poly2(ind2,coef2,4,base);
    poly1.print();
    poly1.mergerpoly();
    poly1.print();

    poly2.print();
    poly2.formatpoly();


    int ind3[1]={0}, coef3[1]={2};
    Poly poly4(ind3,coef3,1,10);
    poly4.print();
    int ind4[2]={0,1}, coef4[2]={2,1};
    Poly poly5(ind4,coef4,2,10);
    poly5.print();
    Poly poly6;
    poly6 = poly4*poly5;
    poly6.print();
    poly6.print_number();

    cout<<"FOrmat 100"<<endl;
    poly6=format_number(4,10);
    poly6.print();
    poly6.print_number();

    factorial_cal(20170).print_number();

    return 0;
}

Poly format_number(int num,int base)
{
    vector<int> temp_index,temp_coef;
    temp_coef = split_number(num,base);
    for(int j=0;j<temp_coef.size();j++)
        temp_index.push_back(j);
    Poly temp_poly(temp_index,temp_coef,base);
    return temp_poly;
}

Poly factorial_cal(int num)
{
    int tindex[1]={0},tcoef[1]={1};
    Poly sum_poly(tindex,tcoef,1,10);
    for(int i=num;i>0;i--)
    {
        Poly temp;
        temp = format_number(i,10);
        sum_poly = sum_poly*temp;
    }
    return sum_poly;
}

