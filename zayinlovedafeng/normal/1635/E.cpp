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

int n,m;
int op[maxn],u[maxn],v[maxn];
vector<int> G1[maxn],G2[maxn];

int dir[maxn];

bool dfs(int i) {
    for (int j:G1[i])    {
        if (!dir[j])    {
            dir[j]=-dir[i];
            if (!dfs(j)) return 0;
        } else {
            if (dir[i]==dir[j]) return 0;
        }
    }
    return 1;
}

int in[maxn];
int x[maxn];

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i)  {
        cin>>op[i]>>u[i]>>v[i];
        G1[u[i]].push_back(v[i]);
        G1[v[i]].push_back(u[i]);
    }

    for (int i=1;i<=n;++i)  {
        if (dir[i]) continue;
        dir[i]=1;
        if (!dfs(i)) return cout<<"NO"<<endl,0;
    }

    for (int i=1;i<=m;++i)  {
        assert(dir[u[i]]!=dir[v[i]]);
        if (dir[u[i]]!=1) swap(u[i],v[i]);
        if (op[i]==1)   {
            ++in[v[i]];
            G2[u[i]].push_back(v[i]);
        } else {
            ++in[u[i]];
            G2[v[i]].push_back(u[i]);
        }
    }

    int X=n;
    int cnt=0;
    queue<int> q;
    for (int i=1;i<=n;++i)
        if (!in[i])
            q.push(i);
    while (q.size())    {
        ++cnt;
        int i=q.front(); q.pop();
        x[i]=X--;
        for (int j:G2[i])   {
            --in[j];
            if (!in[j])
                q.push(j);
        }
    }

    if (cnt!=n) return cout<<"NO"<<endl,0;
    cout<<"YES"<<endl;
    for (int i=1;i<=n;++i)  {
        cout<<(dir[i]==1?"R":"L")<<" "<<x[i]<<endl;
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/