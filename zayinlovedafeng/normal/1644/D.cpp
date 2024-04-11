#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define mt make_tuple
#define rep(i,begin,end) for (__typeof(begin) i=(begin),_end=(end),_step=1-2*((begin)>(end));i!=_end;i+=_step)

// OUTPUT
template<class a, class b>
ostream& operator << (ostream& os, const pair<a,b>& p)  {
    os<<"("<<p.first<<","<<p.second<<")";
    return os;
}
template<class T>
ostream& operator << (ostream& os, const vector<T>& v)  {
    os<<"[";
    if (!v.size()) 
        os<<"]"; 
    else
        for (int i=0;i<v.size();++i)
            os<<v[i]<<",]"[i==v.size()-1];
    return os;
}
template<class T>
ostream& operator << (ostream& os, const set<T>& s)  {
    os<<"{";
    if (!s.size()) 
        os<<"}"; 
    else
        for (auto x:s)
            os<<x<<",}"[x==*s.rbegin()];
    return os;
}

void printr(ostream& os){os<<'\n';}
template<class T, class... Args>
void printr(ostream& os, const T& t, const Args&... args){
    os<<t; if (sizeof...(args)) os<<" ";
    printr(os,args...);
}
#define print(args...) printr(cout,##args)

// INPUT
template<class T>
void read(T& x) {cin>>x;}
template<class T, class... Args>
void read(T& t, Args&... args){
    read(t),read(args...);
}
template<class T>
void readarray(T* A,int n)  {
    rep(i,0,n) read(A[i]);
}


// DEBUG
void dbgr(ostream& os) { os<<endl; }
template<class T, class... Args>
void dbgr(ostream& os, const T& t, const Args&... args) {
    os<<t; if (sizeof...(args)) os<<", ";
    dbgr(os,args...); 
}
#define dbg(args...) cout<<#args<<" = ", dbgr(cout,##args) //cout can be changed


#define maxn 500050
#define modu 998244353
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

// COMMON FUNCTION
// random LL
LL randll(LL a,LL b)    {
    uniform_int_distribution<int> u(a,b);
    static mt19937 e(time(0));
    return u(e);
}

LL pw(LL a,LL k=modu-2) {
    LL ans=1;
    for (a%=modu;k;k>>=1)   {
        if (k&1)
            ans=ans*a%modu;
        a=a*a%modu;
    }
    return ans;
}

int n,m,k,q;
int x[maxn],y[maxn];
int row[maxn],col[maxn];

bool vis[maxn];

int main()  {
    int _;
    scanf("%d",&_);
    while (_--) {
        scanf("%d%d%d%d",&n,&m,&k,&q);
        map<int,int> R,C;
        R[0]=n,C[0]=m;
        for (int i=1;i<=q;++i)  {
            vis[i]=0;
            scanf("%d%d",x+i,y+i);
            --R[row[x[i]]];
            --C[col[y[i]]];
            row[x[i]]=col[y[i]]=i;
            ++R[i],++C[i];
        }
        int mnr=q,mnc=q;
        for (auto pr:R)
            if (pr.second)
                mnr=min(mnr,pr.first);
        for (auto pr:C)
            if (pr.second)
                mnc=min(mnc,pr.first);
                
        for (auto pr:R)
            if (pr.second&&pr.first>=mnc)
                vis[pr.first]=1;
        for (auto pr:C)
            if (pr.second&&pr.first>=mnr)
                vis[pr.first]=1;
                
        LL ans=1;
        for (int i=1;i<=q;++i)
            if (vis[i])
                ans=ans*k%modu;
        printf("%lld\n",ans);

        for (int i=1;i<=q;++i)
            row[x[i]]=col[y[i]]=0;
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/