/*
    >Author: zxy_hhhh
    >blog: zxy-hhhh.cn
    >date: 2018/12/24
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<set>
#define rep(x,a,b) for (int x=int(a);x<=(int)(b);x++)
#define drp(x,a,b) for (int x=int(a);x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];x;x=nx[x])
#define ll long long
using namespace std;
inline ll rd()
{
    ll _x=0;int _ch=getchar(),_f=1;
    for(;!isdigit(_ch)&&(_ch!='-')&&(_ch!=EOF);_ch=getchar());
    if (_ch=='-'){_f=0;_ch=getchar();}
    for(;isdigit(_ch);_ch=getchar()) _x=_x*10+_ch-'0';
    return _f?_x:-_x;
}
void write(ll _x){if (_x>=10) write(_x/10),putchar(_x%10+'0'); else putchar(_x+'0'); }
inline void wrt(ll _x,char _p){if (_x<0) putchar('-'),_x=-_x; write(_x); if (_p) putchar(_p);}
struct node
{
    int l,r,s;
    bool operator < (const node &B) const{return l<B.l;}
};
int n,q;
set<node> st;
set<node>::iterator L,R;
set<node>::iterator split(int w)
{
    set<node>::iterator x=st.lower_bound(node{w,w,0});
    if ((*x).l!=w) x--;
    node now=*x;
    if (w>now.r){
        set<node>::iterator it=x;
        return ++it;
    }
    st.erase(x);
    if (now.l!=w) st.insert(node{now.l,w-1,now.s});
    st.insert(node{w,now.r,now.s});
}
int ans=0;
inline void debug()
{
    for(set<node>::iterator it=st.begin();it!=st.end();++it)
        printf("%d %d %d\n",(*it).l,(*it).r,(*it).s);
    putchar('\n');
}
void update(int l,int r,int s)
{
    split(l),split(r+1);
    L=st.lower_bound(node{l,l,0});
    if ((*L).l>l) --L;
    R=st.lower_bound(node{r+1,r+1,0});
    ans=ans+(r-l+1)*s;
    for(set<node>::iterator it=L;it!=R;++it) ans-=((*it).r-(*it).l+1)*(*it).s;
    //R--;
    if ((*L).l>(*R).l) return ;
    st.erase(L,R);
    st.insert(node{l,r,s});
}
int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    n=rd()+1,q=rd();
    ans=n-1;
    st.insert(node{1,n,1});
    //debug();
    rep(i,1,q){
        int l=rd(),r=rd(),s=rd()-1;
        update(l,r,s);
        //debug();
        //return 0;
        wrt(ans,'\n');
    }
}