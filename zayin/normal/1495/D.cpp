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

void printr(ostream& os){os<<endl;}
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


#define maxn 650
#define modu 998244353
typedef long long LL;

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

int n,m;
vector<int> G[maxn];

int cnt[maxn];

LL g[maxn][maxn];
LL res[maxn][maxn];

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    read(n,m);
    rep(i,1,n+1)
        rep(j,1,n+1)
            g[i][j]=maxn*(i!=j);

    while (m--) {
        int u,v;
        read(u,v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
        g[u][v]=g[v][u]=1;
    }

    rep(k,1,n+1)
        rep(i,1,n+1)
            rep(j,1,n+1)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);

    rep(i,1,n+1)
        rep(j,1,n+1)    {
            auto calc=[&]()->LL {
                rep(k,0,g[i][j]+1) cnt[k]=0;
                rep(k,1,n+1)
                    if (g[k][i]+g[k][j]==g[i][j])
                        ++cnt[g[k][i]];
                // dbg(i,j);
                // rep(k,0,g[i][j]+1) cout<<cnt[k]<<" "; cout<<endl;
                rep(k,0,g[i][j]+1)
                    if (cnt[k]>1)
                        return 0;
                LL ans=1;
                rep(k,1,n+1)
                    if (g[k][i]+g[k][j]>g[i][j])    {
                        int cnt=0;
                        for (int x:G[k])
                            if (g[i][k]==g[i][x]+1&&g[j][k]==g[j][x]+1)
                                ++cnt;
                        // dbg(k,cnt);
                        ans=ans*cnt%modu;
                    }
                return ans;
            };
            res[i][j]=calc();
        }
    
    rep(i,1,n+1)    {
        rep(j,1,n+1)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}