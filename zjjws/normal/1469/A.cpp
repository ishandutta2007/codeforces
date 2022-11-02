#include <stdio.h>
#include <string>
#include <iostream>
#define LL long long
using namespace std;
const int N=1e2+3;
inline LL rin()
{
    LL s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)s=-s;
    return s;
}

string a;
int us[N];
inline bool work()
{
    cin>>a;
    int n=a.length();
    if(n&1)return false;
    int s=0;
    int cts=0;
    for(int i=0;i<n;i++)
    {
        us[i]=us[i-1]+1;
        if(a[i]=='(')s++;
        if(a[i]==')')
        {
            s--;
            if(s<0)
            {
                if(cts==0)return false;
                cts--;
                us[i]++;
                s=0;
            }
        }
        if(a[i]=='?')cts++;
    }
    cts=0;
    s=0;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]==')')s++;
        if(a[i]=='(')
        {
            s--;
            if(s<0)
            {
                if(!cts)return false;
                cts--;
                s=0;
            }
        }
        if(a[i]=='?')cts++;
    }
    return true;
}
int main()
{
    int i,j;
    for(int T=rin();T;T--)if(work())puts("YES");else puts("NO");
    return 0;
}