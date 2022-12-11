#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<string>
#include<queue>
#include<cmath>
#define rep(x,a,b) for (int x=int(a);x<=(int)(b);x++)
#define drp(x,a,b) for (int x=int(a);x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];x;x=nx[x])
#define ll long long
#define ldb long double
using namespace std;
inline ll max(ll zxy_FIR,ll zxy_SEC){return zxy_FIR>zxy_SEC?zxy_FIR:zxy_SEC; }
inline ll min(ll zxy_FIR,ll zxy_SEC){return zxy_FIR>zxy_SEC?zxy_SEC:zxy_FIR; }
inline ll rd(){
    ll x=0;int ch=getchar(); bool f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=0;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return f?x:-x;
}
void write(ll prt_x){ if (prt_x>=10) write(prt_x/10),putchar(prt_x%10+'0'); else putchar(prt_x+'0'); }
inline void wrt(ll prt_x,char prt_c){if (prt_x<0) putchar('-'),prt_x=-prt_x; write(prt_x); if (prt_c) putchar(prt_c);}
int n,m;
char s[105];
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    n=rd();
    scanf("%s",s+1);
    int Ans1=0,Ans2=n/11;
    rep(i,1,n)
        if (s[i]=='8') Ans1++;
    wrt(min(Ans1,Ans2),'\n');
}