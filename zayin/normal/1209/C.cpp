#include<bits/stdc++.h>
#define maxn 200050
using namespace std;

int n;
char s[maxn],t[maxn];

bool judge(int c)   {
    int c1=0,x1=-1;
    int c2=n+1,x2=10;
    for (int i=1;i<=n;++i)
        if (s[i]<c) {
            if (s[i]<x1)    return 0;
            t[i]='1';
            c1=i,x1=s[i];
        }
    for (int i=n;i;--i) 
        if (s[i]>c) {
            if (s[i]>x2)    return 0;
            t[i]='2';
            c2=i,x2=s[i];
        }
    for (int i=1;i<=n;++i)  {
        if (s[i]!=c)    continue;
        if (i<c2)   t[i]='2';
        else
        if (i>c1)   t[i]='1';
        else
        return 0;
    }
    return 1;
}

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%s",&n,s+1);
        for (int i=1;i<=n;++i)  s[i]-='0';

        bool flag=0;
        for (int c=0;c<=9;++c)  {
            if (judge(c))   {
                flag=1;
                for (int i=1;i<=n;++i)  putchar(t[i]);
                puts("");
                break;
            }
        }
        if (!flag)
            puts("-");
    }
    return 0;
}