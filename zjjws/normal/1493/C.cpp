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
const int M=998244353;
inline int prpr(int x,int y){return 1LL*x*y%M;}
inline int ksm(int x,int y){int ans=1;for(;y;y>>=1){if(y&1)ans=prpr(ans,x);x=prpr(x,x);}return ans;}

int a[N];
char c[N];
int vl[27][N];

int n,k;
inline void work()
{
    n=rin();k=rin();if(n%k){puts("-1");return;}
    cin>>(c+1);
    for(int i=1;i<=n;i++){for(int j=0;j<26;j++)vl[j][i]=vl[j][i-1];vl[c[i]-'a'][i]++;}
    bool tag=false;
    for(int i=n;i>=0;i--)
    {
        int cutt=0;
        for(int j=0;j<26;j++)cutt+=(a[j]=((k-vl[j][i]%k)%k+k)%k);
        if(i==n&&!cutt){for(int j=1;j<=n;j++)putchar(c[j]);puts("");tag=true;break;}
        if(cutt>n-i)continue;
        for(int j=c[i+1]+1;j<='z';j++)
        {
            if(a[j-'a'])a[j-'a']--;else a[j-'a']=k-1,cutt+=k;cutt--;
            if(cutt+i+1<=n)
            {
                for(;cutt+i<n-1;cutt+=k)a[0]+=k;
                // puts("El");
                for(int _=1;_<=i;_++)putchar(c[_]);putchar(j);
                for(int _='a';_<='z';_++)for(;a[_-'a'];a[_-'a']--)putchar(_);
                puts("");tag=true;
                break;
            }
            cutt-=k-1;a[j-'a']=0;
        }
        if(tag)break;
    }
    if(!tag)puts("-1");
    return;
}
int main()
{
    for(int T=rin();T;T--)work();
    return 0;
}

//vjudge 