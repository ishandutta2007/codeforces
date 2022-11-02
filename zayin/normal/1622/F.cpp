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
#define dbg(args...) cerr<<#args<<" = ", dbgr(cerr,##args) //cout can be changed


#define maxn 1000050
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

LL h[maxn];
map<LL,int> mph;

bool noprime[maxn];
int p[maxn],pnum;

void predo()    {
    mt19937_64 rd(time(0));
    for (int i=2;i<maxn;++i)    {
        if (!noprime[i])
            p[pnum++]=i,h[i]=rd();
        for (int j=0;j<pnum&&i*p[j]<maxn;++j)   {
            int k=i*p[j];
            noprime[k]=1;
            h[k]=h[i]^h[p[j]];
            if (i%p[j]==0)
                break;
        }
    }
}

int n;
bool del[maxn];

void output(int c)   {
    cout<<c<<endl;
    for (int i=1;i<=n;++i)
        if (!del[i])
            cout<<i<<" ";
    exit(0);
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    predo();
    cin>>n;
    LL hs=0;
    for (int i=2;i<=n;++i)  {
        h[i]^=h[i-1];
        mph[h[i]]=i;
        hs^=h[i];
    }

    if (!hs) output(n);

    if (mph.count(hs))   {
        del[mph[hs]]=1;
        output(n-1);
    }

    for (int i=2;i<=n;++i)  {
        LL t=hs^h[i];
        if (mph.count(t))  {
            dbg(i,h[i]);
            dbg(mph[t],h[mph[t]]);
            del[i]=del[mph[t]]=1;
            output(n-2);
        }
    }

    assert(n%4==3);
    del[2]=del[n/2]=del[n]=1;
    output(n-3);
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/