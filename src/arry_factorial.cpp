#include <iostream>  
#define N 3000         
#include<cstring>  
#include <stdio.h>

using namespace std;  

int a[N];     //定义数组  
int main( )  
{  
     int n,i,j,c,s;  
     cin>>n;  
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
     return 0;  
}  
