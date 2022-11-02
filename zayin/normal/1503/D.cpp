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
// min
template<class T>
T min(const vector<T>& v) { return *min_element(v.begin(),v.end()); }
// max
template<class T>
T max(const vector<T>& v) { return *max_element(v.begin(),v.end()); }

LL pw(LL a,LL k=modu-2) {
    LL ans=1;
    for (a%=modu;k;k>>=1)   {
        if (k&1)
            ans=ans*a%modu;
        a=a*a%modu;
    }
    return ans;
}

#define NO {    print("-1"); exit(0);   }

int n,a[maxn],b[maxn];

int vis[maxn];
int f[maxn],g[maxn];

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    read(n);
    rep(i,0,n)  {
        read(a[i],b[i]);
        if (a[i]<=n&&b[i]<=n)
            return print("-1"),0;
        f[a[i]]=b[i],g[a[i]]=0;
        f[b[i]]=a[i],g[b[i]]=1;
    }

    // print("???");

    int ans=0;
    int cnt0=0,cnt1=0,lim=0,lastf=maxn;
    vector<int> unplaced;
    rep(i,n+1,n*2+1) unplaced.push_back(i);
    auto upd=[&](int num) {
        while (unplaced.size()) {
            int x=unplaced.back(); 
            // cout<<"to place:"<<x<<endl;
            if (x<=num) break;
            unplaced.pop_back();
            if (vis[x]) continue;
            if (lim>f[x]) NO;
            lim=f[x];
            // cout<<"second:"<<f[x]<<" "<<x<<" ~ "<<g[x]<<endl;
            cnt0+=g[x],cnt1+=!g[x];
            vis[x]=vis[f[x]]=1;
        }
    };
    rep(i,1,n+1)    {
        if (vis[f[i]]) continue;
        if (lim<i)  {
            // cout<<"---------------"<<endl;
            ans+=min(cnt0,cnt1);
            cnt0=cnt1=0;
        }
        assert(lim!=i);
        if (lastf<f[i])
            return print("-1"),0;
        // cout<<"first:"<<i<<" "<<f[i]<<" "<<g[i]<<endl;
        lastf=f[i];
        cnt0+=g[i],cnt1+=!g[i];
        upd(f[i]);
        vis[i]=vis[f[i]]=1;
    }
    ans+=min(cnt0,cnt1);
    print(ans);
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/