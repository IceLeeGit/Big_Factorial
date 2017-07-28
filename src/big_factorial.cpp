#include <iostream>
#include "polynomial_operation.cc"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


using namespace std;

Poly format_number(int num,int base);
Poly factorial_cal(int num);

int main(int argc,char** argv)
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

    if(argc>1)
    {
        int num = atoi(argv[1]);
        clock_t time_start,time_end;
        time_start = clock();
        factorial_cal(num).print_number();
        time_end = clock();
        cout<<"Run times are "<<double(time_end-time_start)/CLOCKS_PER_SEC <<"s."<<endl;
    }
    else
        cout<<"Not found the integer."<<endl;

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

