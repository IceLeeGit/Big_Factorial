#include <iostream>

#include <cassert>
#include <math.h>
#include "polynomial.h"


using namespace std;



//int * split_number(int number,int base)
//{
//    int *ret;
//    if (number<base)
//    {
//        ret = new int [1];
//        ret[0]=base;
//    }
//    else
//    {
//        int i=0,len,divisor;
//        len = floor(log10(number)/log10(base))+1;
//        ret = new int [len];
//
//        divisor = number;
//        while(divisor>=base)
//        {
//            ret[i] = divisor%base;
//            divisor = divisor/base;
//            i++;
//        }
//        ret[i] = divisor;
//    }
//    return ret;
//}
vector<int> split_number(int number,int base)
{
    vector<int> ret;
    if (number<base)
    {
        ret.push_back(number);
    }
    else
    {
        int divisor = number;
        do
        {
            ret.push_back(divisor%base);
            divisor = divisor/base;
        }while(divisor>=base);
        ret.push_back(divisor%base);
    }
    return ret;
}


Poly::Poly()
{
    index.push_back(0);
    coefficient.push_back(0);
    base_number=10;
}

Poly::Poly(int ind[], int coef[], int length,int base)
{
    for(int i=0;i<length;i++)
    {
        index.push_back(ind[i]);
        coefficient.push_back(coef[i]);
        base_number = base;
    }
}

Poly::Poly(vector<int> ind,vector<int> coef,int base)
{
    index = ind;
    coefficient = coef;
    base_number = base;
}

Poly::~Poly()
{
}

void Poly::print()
{
    int count = 0;
    cout<<"The polynomial is: ";
    for(int i=0;i<index.size();i++)
    {
        if (coefficient[i]==0)
        {
            count++;
            continue;
        }
        if (i>count)
            cout<<" + ";
        cout<<coefficient[i]<<"*"<<base_number<<"^"<<index[i];
    }
    cout<<endl;

}

void Poly::print_number()
{
    mergerpoly();
    vector<int> sum;
    int max_index=0;
    for(int i=0;i<index.size();i++)
    {
        if (index[i]>=max_index)
        {
            sum.resize(index[i]+1,0);
            max_index=index[i];
        }
        sum[index[i]] = coefficient[i];
    }

    cout<<"The polynomial number is:  ";
    for(vector<int>::reverse_iterator it=sum.rbegin();it!=sum.rend();it++)
    {
        cout<<*it;
    }
    cout<<endl;
}


void Poly::mergerpoly()
{
    //for (std::vector<int>::iterator it = index.begin(); it != index.end(); ++it)
    int index_len,surplus_len;
    index_len = index.size();
    for (int i=0;i<index_len;i++)
    {
        if(coefficient[i]==0)
        {
            coefficient.erase(coefficient.begin()+i);
            index.erase(index.begin()+i);
            index_len -=1;
            continue;
        }

        for(int j=i+1;j<index_len;j++)
        {
            if (index[i]==index[j])
            {
                coefficient[i]+=coefficient[j];
                coefficient.erase(coefficient.begin()+j);
                index.erase(index.begin()+j);
                index_len -=1;
            }
        }
    }
}


void Poly::formatpoly()
{
    int length = index.size();
    for (int i=0;i<length;i++)
    {
        if(coefficient[i]>=base_number)
        {
            vector<int> temp_index,temp_coef;
            temp_coef = split_number(coefficient[i],base_number);
            for(int j=0;j<temp_coef.size();j++)
            {
                temp_index.push_back(j+index[i]);
            }

            coefficient.erase(coefficient.begin()+i);
            index.erase(index.begin()+i);
            length--;
            i--;
            index.insert(index.end(),temp_index.begin(),temp_index.end());
            coefficient.insert(coefficient.end(),temp_coef.begin(),temp_coef.end());
        }
    }
    mergerpoly();
}

void Poly::operator = (Poly p1)
{
    index.clear();
    coefficient.clear();
    index.insert(index.end(),p1.index.begin(),p1.index.end());
    coefficient.insert(coefficient.end(),p1.coefficient.begin(),p1.coefficient.end());
    mergerpoly();
    base_number = p1.base_number;
}

Poly Poly::operator + (Poly p1)
{
    if(base_number==p1.base_number)
    {
        p1.index.insert(p1.index.end(),index.begin(),index.end());
        p1.coefficient.insert(p1.coefficient.end(),coefficient.begin(),coefficient.end());
        p1.mergerpoly();
        return p1;
    }
    else
    {
        cout<<"The base_number is not equals."<<endl;
        assert(0);
    }
}

Poly Poly::operator * (Poly p1)
{
    if(base_number!=p1.base_number)
    {
        cout<<"The base_number is not equals."<<endl;
        assert(0);
    }
    vector<int> temp_index,temp_coef;
    int length = index.size();
    int p1_length = p1.index.size();
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<p1_length;j++)
        {
            temp_index.push_back(index[i] + p1.index[j]);
            temp_coef.push_back(coefficient[i]*p1.coefficient[j]);
        }
    }
    Poly sum_poly(temp_index,temp_coef,base_number);
    sum_poly.formatpoly();
    return sum_poly;
}

