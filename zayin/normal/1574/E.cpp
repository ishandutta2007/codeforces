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

#define maxc 5
#define maxn 1000050
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
int okr[maxn][2],okc[maxn][2],okrc[2];
int cntr[maxc],cntc[maxn];

map<int,int> num[maxn];

LL pw2[maxn];

int main()  {
    for (int i=pw2[0]=1;i<maxn;++i) pw2[i]=pw2[i-1]*2%modu;

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>q;
    cntr[2]=n;
    cntc[2]=m;
    while (q--) {
        int x,y,c;
        cin>>x>>y>>c; 
        // dbg(c);
        --x,--y;
        auto modify=[&](int ok[maxn][2],int cnt[maxc],int x,int c,int d)  {
            // cout<<(ok==okr?"row:":"col:")<<" "<<x<<" "<<c<<" "<<d<<endl;
            cnt[!ok[x][0]+!ok[x][1]]--;
            ok[x][c]+=d;
            cnt[!ok[x][0]+!ok[x][1]]++;
        };
        auto del=[&](int x,int y)   {
            if (!num[x].count(y)) return;
            int oldc=num[x][y];
            // dbg(x,y,oldc);
            num[x].erase(y);
            modify(okr,cntr,x,(y&1)^oldc^1,-1);
            modify(okc,cntc,y,(x&1)^oldc^1,-1);
            --okrc[(x&1)^(y&1)^oldc^1];
        };
        del(x,y);
        auto ins=[&](int x,int y,int c)   {
            num[x][y]=c;
            // cout<<"ins:"<<x<<" "<<y<<" "<<(~
            modify(okr,cntr,x,(y&1)^c^1,1);
            modify(okc,cntc,y,(x&1)^c^1,1);
            ++okrc[(x&1)^(y&1)^c^1];
        };
        if (~c)
            ins(x,y,c);
        
        auto solver=[&]()   {
            if (cntr[0]) return 0LL;
            return pw2[cntr[2]];
        };
        auto solvec=[&]()   {
            if (cntc[0]) return 0LL;
            return pw2[cntc[2]];
        };
        auto solverc=[&]()  {
            return !okrc[0]+!okrc[1];
        };

        // cout<<"row:"<<endl; for (int i=0;i<n;++i) cout<<i<<":"<<okr[i][0]<<" "<<okr[i][1]<<endl;
        // cout<<"col:"<<endl; for (int i=0;i<m;++i) cout<<i<<":"<<okc[i][0]<<" "<<okc[i][1]<<endl;

        // dbg(solver(),solvec(),solverc());
        cout<<(solver()+solvec()-solverc()+modu)%modu<<endl;
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/