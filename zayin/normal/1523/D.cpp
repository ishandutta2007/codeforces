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

#define maxm 105
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

int R(int a,int b)  {
    uniform_int_distribution<int> u(a,b);
    static mt19937 e(time(0));
    return u(e);
}

int n,m,p;
char s[maxm];
LL a[maxn];
vector<int> pos[maxn];

int sum[maxn];

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    read(n,m,p);
    rep(i,0,n)  {
        read(s);
        rep(j,0,m)  {
            if (s[j]=='0') continue;
            a[i]|=1LL<<j;
            pos[i].push_back(j);
        }
    }

    int lim=(n+1)>>1;
    int ans=0;
    LL mask=0;
    rep(turn,0,60) {
        int sp=R(0,n-1);
    // rep(turn,0,n) {
    //     int sp=turn;
        int _n=pos[sp].size();

        // dbg(sp);
        rep(s,0,1<<_n) sum[s]=0;
        rep(i,0,n)  {
            LL x=0;
            rep(j,0,_n)
                x|=(a[i]>>pos[sp][j]&1)<<j;
            ++sum[x];
            // dbg(i,x);
        }
        rep(i,0,_n)
            rep(s,0,1<<_n)
                if (s>>i&1)
                    sum[s^(1<<i)]+=sum[s];
        // rep(s,0,1<<_n) cout<<sum[s]<<" "; cout<<endl;
        rep(s,0,1<<_n)  {
            if (sum[s]<lim||__builtin_popcount(s)<ans) continue;
            ans=__builtin_popcount(s);
            mask=0;
            rep(i,0,_n)
                if (s>>i&1)
                    mask|=1LL<<pos[sp][i];
        }
    }
    rep(j,0,m)
        cout<<(mask>>j&1);
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/