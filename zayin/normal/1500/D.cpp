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


#define maxn 1505
#define modu 998244353
#define inf 1e9
typedef long long LL;
typedef pair<int,int> pii;

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


int n,q;
int a[maxn][maxn];

vector<pii> nearby[maxn][maxn];

bool vis[maxn*maxn];

inline void merge(vector<pii>& a,const vector<pii>& b)    {
    vector<pii> res;
    int i=0,j=0;
    while (i<a.size()&&j<b.size()&&res.size()<=q)  {
        if (a[i].second<=b[j].second)
            res.emplace_back(a[i]),vis[a[i++].first]=1;
        else
            res.emplace_back(b[j].first,b[j].second+1),vis[b[j++].first]=1;
        while (i<a.size()&&vis[a[i].first]) ++i;
        while (j<b.size()&&vis[b[j].first]) ++j;
    }
    for (;i<a.size()&&res.size()<=q;++i)
        if (!vis[a[i].first])
            res.emplace_back(a[i]);
    for (;j<b.size()&&res.size()<=q;++j)
        if (!vis[b[j].first])
            res.emplace_back(b[j].first,b[j].second+1);

    for (auto p:a) vis[p.first]=0;
    for (auto p:b) vis[p.first]=0;
    swap(a,res);
}

int res[maxn];

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    read(n,q);
    rep(i,1,n+1)
        rep(j,1,n+1)
            read(a[i][j]);
    
    rep(j,n,0)    
        rep(i,n,0)  {
            nearby[i][j]={mp(a[i][j],1)};
            if (i<n) merge(nearby[i][j],nearby[i+1][j]);
            if (j<n) merge(nearby[i][j],nearby[i][j+1]);
            if (i<n&&j<n) merge(nearby[i][j],nearby[i+1][j+1]);

            int len=min(n-i+1,n-j+1);
            if (nearby[i][j].size()==q+1)
                len=min(len,nearby[i][j][q].second-1);
            // dbg(i,j,len,nearby[i][j]);
            ++res[len];
        }
        
    rep(i,n,0) res[i]+=res[i+1];
    rep(i,1,n+1) print(res[i]);
    cerr<<clock()<<endl;
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/