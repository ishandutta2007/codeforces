#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 990010
using namespace std;
int main()
{
    int n,sum;
    char str[maxn];
     scanf("%s",str);
     int len=strlen(str);
     int a;
     if(len>=2)  a=(int)((str[len-2]-'0')*10+str[len-1]-'0');
     else   a=(int)(str[0]-'0');

     int b=(a+5)%4;
     if(b==1) cout<<"4"<<endl;
     else cout<<"0"<<endl;
    return 0;
}