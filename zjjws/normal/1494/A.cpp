#include <queue>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
inline LL rin()
{
    LL s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)return -s;
    return s;
}
inline void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x^y)x^=y^=x^=y;return;}
const int N=3e5+3;

LL n;
string a;
inline void work()
{
    cin>>a;n=a.length();
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                int cutt=0;
                for(int _=0;_<n;_++)
                {
                    int now;
                    if(a[_]=='A')now=i;
                    if(a[_]=='B')now=j;
                    if(a[_]=='C')now=k;
                    if(now==0)cutt--;
                    else cutt++;
                    if(cutt<0)break;
                }
                if(cutt==0){puts("Yes");return;}
            }
        }
    }
    puts("No");
    return;
}
int main()
{
    for(int T=rin();T;T--)work();
    return 0;
}