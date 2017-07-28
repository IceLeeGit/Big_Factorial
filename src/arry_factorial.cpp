#include <iostream>  
#include<cstring>  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;  

int main(int argc,char** argv)  
{  
    int num;  
    if (argc==0)
    {
        cout<<"You need enter a integer: ";
        cin>>num;  
    }
    else
        num = atoi(argv[1]);

    vector<int> sum;
    int count,temp;
    clock_t time_start,time_end;
    time_start = clock();

    cout<<"The "<<num<<" number's factorial is: ";
    sum.push_back(1);
    for(int i=2;i<=num;i++)
    {
        count = 0;
        for(int j=0;j<sum.size();j++)
        {
            temp = sum[j]*i+count;
            sum[j] = temp%10;
            count = temp/10;
        }

        if(0<count && count<10)
        {
            sum.push_back(count);
        }
        else if(count>=10)
        {
            int divisor = count;
            do
            {
                sum.push_back(divisor%10);
                divisor = divisor/10;
            }while(divisor>=10);
            sum.push_back(divisor);
        }
    }

    for(vector<int>::reverse_iterator it=sum.rbegin();it!=sum.rend();it++)
        cout<<*it;
      
    cout<<endl;  
    time_end = clock();
    cout<<"Run times are "<<(long)(time_end-time_start)/CLOCKS_PER_SEC<<"s."<<endl;
    return 0;  
}  
