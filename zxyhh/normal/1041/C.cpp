#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <string>
#include <queue>
#include <cmath>
#include <set>
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
int n,m,d;
int a[maxn],ans[maxn];
int b[maxn];
set<pair<int,int>> st;
set<pair<int,int>>::iterator it;
int main()
{
    n=rd();m=rd(),d=rd()+1;
    rep(i,1,n) a[i]=rd();
    rep(i,1,n) st.insert(make_pair(a[i],i));
    int Ans=0;
    while(!st.empty()){
        ++Ans;
        it=st.lower_bound(make_pair(0,1));
        int ti=(*it).first,ti2=(*it).second;
        while(it!=st.end()){
            ans[ti2]=Ans,ti+=d,st.erase(it),it=st.lower_bound(make_pair(ti,0));
            if (it!=st.end()) ti=((*it).first); 
            ti2=(*it).second;
        }
    }
    wrt(Ans,'\n');
    rep(i,1,n) wrt(ans[i],' ');
}