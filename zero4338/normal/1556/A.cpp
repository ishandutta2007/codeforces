#include<iostream>
#include<cstdio>
using namespace std;
int read()
{
    int ret=0;char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
    return ret;
}
int T;
int main()
{
    T=read();
    while(T--)
    {
        int c=read(),d=read();
        if(c==0&d==0)printf("0\n");
        else if((c+d)&1)printf("-1\n");
        else if(c==d)printf("1\n");
        else printf("2\n");
    }
    return 0;
}