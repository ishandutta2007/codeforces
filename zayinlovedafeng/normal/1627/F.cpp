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


#define maxn 505
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

int n,m;
map<int,int> G1[maxn*maxn];

int getid(int i,int j)  {
    return (i-1)*(n+1)+j;
}

int dis[maxn*maxn];

void join(int u,int v)  {
    G1[u][v]+=1;
    G1[v][u]+=1;

    int nu=(n+1)*(n+1)-u+1;
    int nv=(n+1)*(n+1)-v+1;
    G1[nu][nv]+=1;
    G1[nv][nu]+=1;
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int _;
    read(_);
    while (_--) {
        cin>>m>>n;
        for (int i=1;i<=(n+1)*(n+1);++i) dis[i]=-1,G1[i].clear();
        for (int i=1;i<=m;++i)  {
            int r1,c1,r2,c2;
            cin>>r1>>c1>>r2>>c2;
            if (r1==r2) {
                if (c1>c2) swap(c1,c2);
                int u=getid(r2,c2);
                int v=getid(r2+1,c2);
                join(u,v);
            } else {
                if (r1>r2) swap(r1,r2);
                int u=getid(r2,c2);
                int v=getid(r2,c2+1);
                join(u,v);
            }
        }

        priority_queue<pair<LL,int>> q;
        for (int i=1;i<=(n+1)*(n+1);++i) dis[i]=1e9;
        for (int i=1;i<=n+1;++i)
            for (int j=1;j<=n+1;++j)
                if (i==1||i==n+1||j==1||j==n+1) {
                    int k=getid(i,j);
                    dis[k]=0;
                    q.emplace(-dis[k],k);
                }
        
        int all=(n+1)*(n+1)+1;
        while (q.size())    {
            auto pr=q.top(); q.pop();
            int k=pr.second;
            if (dis[k]!=-pr.first) continue;
            // dbg(k,dis[k]);
            int i=(k-1)/(n+1)+1,j=(k-1)%(n+1)+1;
            for (int dx:{-1,0,1})
                for (int dy:{-1,0,1})   {
                    if (dx&&dy) continue;
                    int ni=i+dx,nj=j+dy;
                    if (ni<=0||ni>n+1||nj<=0||nj>n+1) continue;
                    int nk=getid(ni,nj);
                    int w=G1[nk][k];
                    // if (G1[k].count(nk)||~dis[nk]) continue;
                    if (dis[nk]<=dis[k]+w) continue;
                    // dbg(k,nk);
                    dis[nk]=dis[k]+w;
                    q.emplace(-dis[nk],nk);
                }
        }
        // int now=0;
        // queue<int> q[2];
        // for (int i=1;i<=n+1;++i)
        //     for (int j=1;j<=n+1;++j)
        //         if (i==1||i==n+1||j==1||j==n+1) {
        //             int k=getid(i,j);
        //             dis[k]=0;
        //             q[now].push(k);
        //         }
        // while (1)    {
        //     if (!q[now].size()) break;
        //     vector<int> vq;

        //     while (q[now].size())   {
        //         int k=q[now].front(); q[now].pop();
        //         dbg(k,dis[k],G1[k]);
        //         vq.push_back(k);
        //         int i=(k-1)/(n+1)+1,j=(k-1)%(n+1)+1;
        //         for (int dx:{-1,0,1})
        //             for (int dy:{-1,0,1})   {
        //                 if (dx&&dy) continue;
        //                 int ni=i+dx,nj=j+dy;
        //                 if (ni<=0||ni>n+1||nj<=0||nj>n+1) continue;
        //                 int nk=getid(ni,nj);
        //                 if (G1[k].count(nk)||~dis[nk]) continue;
        //                 dbg("0",k,nk);
        //                 dis[nk]=dis[k];
        //                 q[now].push(nk);
        //             }
        //     }

        //     now^=1;
        //     for (int k:vq)  {
        //         for (int nk:G1[k])  {
        //             if (~dis[nk]) continue;
        //             dbg("1",k,nk);
        //             dis[nk]=dis[k]+1;
        //             q[now].push(nk);
        //         }
        //     }
        // }

        // dbg(getid(n/2+1,n/2+1));
        cout<<m-dis[getid(n/2+1,n/2+1)]<<endl;
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/