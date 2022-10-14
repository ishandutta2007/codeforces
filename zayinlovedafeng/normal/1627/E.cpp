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

int n,m,q;
vector<int> row[maxn];
vector<pair<int,LL>> G[maxn],G2[maxn];
LL x[maxn];

int a[maxn],b[maxn],c[maxn],d[maxn],h[maxn];

int N;
map<pair<int,int>,int> id;

void join(int u,int v,LL w)    {
    G[u].emplace_back(v,w);
    G[v].emplace_back(u,w);
}

LL dis[maxn];

// void spfa(int vs,int vt)    {
//     for (int i=1;i<=N;++i) dis[i]=1e18;
//     dis[vs]=0;
//     priority_queue<pair<LL,int>> q;
//     q.emplace(dis[vs],vs);
//     while (q.size())    {
//         auto pr=q.top(); q.pop();
//         int i=pr.second;
//         if (dis[i]!=-pr.second) continue;
//         for (auto [j,w]:G[i])   {
//             if (dis[j]<=dis[i]+w) continue;
//             for (int i
//         }
//     }
// }

int getid(int i,int j)  {
    auto p=mp(i,j);
    if (id.count(p))
        return id[p];
    dis[N]=1e18;
    G[N].clear();
    G2[N].clear();
    return id[p]=N++;
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int _;
    read(_);
    while (_--) {
        cin>>n>>m>>q;
        for (int i=1;i<=n;++i) row[i].clear();
        N=1,id.clear();

        for (int i=1;i<=n;++i) cin>>x[i];
        getid(1,1),row[1].push_back(1);
        getid(n,m),row[n].push_back(m);
        for (int i=1;i<=q;++i)  {
            cin>>a[i]>>b[i]>>c[i]>>d[i]>>h[i];
            int u=getid(a[i],b[i]);
            int v=getid(c[i],d[i]);
            G2[u].emplace_back(v,-h[i]);
            row[a[i]].push_back(b[i]);
            row[c[i]].push_back(d[i]);
        }

        dis[getid(1,1)]=0;
        for (int i=1;i<=n;++i)  {
            sort(row[i].begin(),row[i].end());
            row[i].resize(unique(row[i].begin(),row[i].end())-row[i].begin());
            for (int k=1;k<row[i].size();++k)   
                join(getid(i,row[i][k]),getid(i,row[i][k-1]),x[i]*(row[i][k]-row[i][k-1]));
            
            priority_queue<pair<LL,int>> q;
            for (int j:row[i])  {
                int k=getid(i,j);
                q.emplace(-dis[k],k);
            }
            while (q.size())    {
                auto pr=q.top(); q.pop();
                int i=pr.second;
                // dbg(dis[i],pr,G[i].size());
                if (dis[i]!=-pr.first) continue;
                // dbg(i,dis[i],G[i].size());
                for (auto [j,w]:G[i])   {
                    // dbg(i,"->",j);
                    if (dis[j]<=dis[i]+w) continue;
                    dis[j]=dis[i]+w;
                    q.emplace(-dis[j],j);
                }
            }

            for (int j:row[i])  {
                int k=getid(i,j);
                // dbg(i,j,dis[k]);
                for (auto [v,w]:G2[k])
                    dis[v]=min(dis[v],dis[k]+w);
            }
        }

        #define endl '\n'
        int vt=getid(n,m);
        if (dis[vt]>1e17) 
            cout<<"NO ESCAPE"<<endl;
        else
            cout<<dis[vt]<<endl;
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/