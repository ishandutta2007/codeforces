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

#define maxc 26
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

int n;
char s[maxn],t[maxn];


vector<int> pos[maxc];
LL fir[maxc];

int T[maxn];

int lowbit(int x)   {
    return x&-x;
}

void change(int x,int d)  {
    // dbg("change",x,d);
    for (;x<=n;x+=lowbit(x))
        T[x]+=d;
}

int query(int x)    {
    int sum=0;
    for (;x;x-=lowbit(x))
        sum+=T[x];
    return sum;
}

LL getfir(int c)  {
    if (!pos[c].size())
        return 1e16;
    else {
        return query(pos[c].back());
    }
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int _;
    read(_);
    while (_--) {
        cin>>n>>s+1>>t+1;
        for (int i=1;i<=n;++i) T[i]=lowbit(i);
        
        for (int c=0;c<maxc;++c) pos[c].clear();
        for (int i=n;i;--i) 
            pos[s[i]-'a'].push_back(i);

        LL ans=1e18,sum=0;
        for (int i=1;i<=n;++i)  {
            int c=t[i]-'a';
            // dbg(i,sum);
            for (int a=0;a<c;++a)   {
                // if (a<=5) dbg(a,getfir(a));
                ans=min(ans,sum+getfir(a)-1);
            }
            if (!pos[c].size()) break;
            // dbg(c,pos[c].back(),getfir(c));
            sum+=getfir(c)-1;
            change(pos[c].back(),-1);
            pos[c].pop_back();
        }

        if (ans>1e15)
            ans=-1;
        cout<<ans<<endl;
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/