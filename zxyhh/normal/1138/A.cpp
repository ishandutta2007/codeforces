/*
    >Author: zxy_hhhh
    >blog: zxy-hhhh.cn
    >date: 2019/03/08
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<ctime>
#define rep(x,a,b) for (int x=int(a);x<=(int)(b);x++)
#define drp(x,a,b) for (int x=int(a);x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];x;x=nx[x])
#define ll long long
using namespace std;
inline ll rd() {
    ll _x=0;int _ch=getchar(),_f=1;
    for(;!isdigit(_ch)&&(_ch!='-')&&(_ch!=EOF);_ch=getchar());
    if (_ch=='-'){_f=-1;_ch=getchar();}
    for(;isdigit(_ch);_ch=getchar()) _x=_x*10+_ch-'0';
    return _f*_x;
}
void write(ll _x){if (_x>=10) write(_x/10),putchar(_x%10+'0'); else putchar(_x+'0'); }
inline void wrt(ll _x,char _p){if (_x<0) putchar('-'),_x=-_x; write(_x); if (_p) putchar(_p);}
int n;
int a[100005],dp[100005],dp1[100005];
int main() {
    n=rd();
    rep(i,1,n)  {
        a[i]=rd();
        dp[i]=a[i-1]==a[i]?dp[i-1]+1:1;
    }
    drp(i,n,1) {
        dp1[i]=a[i+1]==a[i]?dp1[i+1]+1:1;
    }
    int x=0;
    rep(i,1,n)
        if (a[i]!=a[i+1])
            x=max(x,min(dp[i],dp1[i+1])*2);
    wrt(x,'\n');
}