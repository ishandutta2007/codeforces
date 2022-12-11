#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <string>
#include <queue>
#include <cmath>
#define rep(x,a,b) for (int x=int(a);x<=(int)(b);x++)
#define drp(x,a,b) for (int x=int(a);x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];x;x=nx[x])
#define ll long long
#define ldb long double
#define maxn 200005
using namespace std;
inline ll rd(){
    ll x=0;int ch=getchar(); bool f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=0;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return f?x:-x;
}
void write(ll x){ if (x>=10) write(x/10),putchar(x%10+'0'); else putchar(x+'0'); }
inline void wrt(ll x,int p){if (x<0) putchar('-'),x=-x; write(x); if (p) putchar(p);}
int l[maxn],r[maxn],n,m,Ans;
int main()
{
    n=rd();m=rd();
    rep(i,1,n) l[i]=rd(),r[i]=rd();
    int x=m,w=1;
    while(x>l[w+1]-r[w]&&w<n) x-=l[w+1]-r[w],w++;
    Ans=r[w]+x-l[1];
    rep(i,2,n){
        x+=l[i]-r[i-1];
        while(x>l[w+1]-r[w]&&w<n) x-=l[w+1]-r[w],w++;
        if(r[w]+x-l[i]>Ans) Ans=r[w]+x-l[i];
    }
    wrt(Ans,'\n');
}