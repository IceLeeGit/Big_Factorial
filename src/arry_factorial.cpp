#include <iostream>  
#define N 3000         
#include<cstring>  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;  

int a[N];     //定义数组  
int main(int argc,char** argv)  
{  
    int n,i,j,c,s;  
    if (argc==0)
    {
        cout<<"You need enter a integer: ";
        cin>>n;  
    }
    else
        n = atoi(argv[1]);

    clock_t time_start,time_end; 
    time_start = clock();

    cout<<"The "<<n<<" number's factorial is: ";
    memset(a,0,sizeof(a));      //数组清零  
    a[0]=1;                             //a[0]赋值为1  
    for(j=2;j<=n;j++)   //乘以j  
    {  
       c=0;                    //是否进位  
       for(i=0;i<N;i++)  
       {  
           s=a[i]*j+c;  
           a[i]=s%10;  
           c=s/10;  
       }  
    }  
    for(i=N-1;i>=0;i--)  
       if(a[i])break;             //忽略前导零  
    for(j=i;j>=0;j--)      //倒序输出  
       cout<<a[j];  
      
    cout<<endl;  
    time_end = clock();
    cout<<"Run times are "<<(double)(time_end-time_start)/CLOCKS_PER_SEC<<"s."<<endl;
    return 0;  
}  
