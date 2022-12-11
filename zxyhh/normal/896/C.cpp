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
#define REP(a,b) for (set<node> :: iterator it=L;it!=R;++it)
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
    int l,r;
    ll s;
    bool operator < (const node &B) const{return l<B.l;}
};
#define maxn 100005
pair<ll,int> t[maxn];
int tot;
int n,seed,m,mxv;
inline int qpow(int x,int k,int mod)
{
    int ans=1;
    for(;k;k>>=1,x=1ll*x*x%mod) if (k&1) ans=1ll*ans*x%mod;
    return ans;
}
inline int rnd()
{
    int ret=seed;
    seed=(1ll*seed*7+13)%1000000007;
    return ret;
}
set<node> st;
inline void split(int w)
{
    set<node>::iterator x=st.lower_bound(node{w,w,0});
    if ((*x).l!=w) x--;
    node now=*x;
    if (w>now.r){
        ++x;
        return ;
    }
    st.erase(x);
    if (now.l!=w) st.insert(node{now.l,w-1,now.s});
    st.insert(node{w,now.r,now.s});
}
set<node> :: iterator L,R;
inline void get(int l,int r)
{
    split(l),split(r+1);
    L=st.lower_bound(node{l,l,0});
    if ((*L).l>l) --L;
    R=st.lower_bound(node{r+1,r+1,0});
}
inline void Add(int l,int r,int val)
{
    get(l,r);
    REP(L,R){
        node x=*it;
        x.s+=val;
        st.erase(it);
        it=st.insert(x).first;
    }
}
inline ll kth(int l,int r,int val)
{
    get(l,r);
    tot=0;
    REP(L,R) t[++tot]=make_pair((*it).s,(*it).r-(*it).l+1);
    sort(t+1,t+1+tot);
    rep(i,1,tot){
        if (t[i].second>=val) return t[i].first;
        val-=t[i].second;
    }
}
inline int Sum(int l,int r,int x,int mod)
{
    get(l,r);
    int ans=0;
    REP(L,R)
        ans=(ans+1ll*qpow((*it).s%mod,x,mod)*((*it).r-(*it).l+1))%mod;
    return ans;
}
inline void debug()
{
    for(set<node>::iterator it=st.begin();it!=st.end();++it)
        printf("%d %d %I64d\n",(*it).l,(*it).r,(*it).s);
    putchar('\n');
}
int hje;
#define HJE_AK_IOI hje++;
#define HJE_Au {if (hje==101) debug(),printf("%d %d %d %d %d\n",op,l,r,val,_val);}
int main()
{
   // freopen("test.in","r",stdin);
   // freopen("test.out","w",stdout);
    n=rd(),m=rd(),seed=rd(),mxv=rd();
    rep(i,1,n) st.insert(node{i,i,rnd()%mxv+1});
    rep(i,1,m){
        int op=(rnd()&3)+1,l=rnd()%n+1,r=rnd()%n+1,val,_val=0;
        if (l>r) swap(l,r); 
        if (op==1){
            val=rnd()%mxv+1;
            Add(l,r,val);
        }
        else if (op==2){
            val=rnd()%mxv+1;
            get(l,r),st.erase(L,R);
            st.insert(node{l,r,val});
        }
        else if (op==3){
            int val=rnd()%(r-l+1)+1;
            wrt(kth(l,r,val),'\n');
            #ifdef hje_is_huge
            HJE_AK_IOI
            HJE_Au
            #endif
        }
        else if (op==4){
            int val=rnd()%mxv+1,_val=rnd()%mxv+1;
            wrt(Sum(l,r,val,_val),'\n');
            #ifdef hje_is_huge
            HJE_AK_IOI
            HJE_Au
            #endif
        }
        //debug();
    }
}