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

int n,m;
LL F[maxn],I[maxn],FI[maxn];

LL C(LL n,LL m) {
    return n<m?0:F[n]*FI[m]%modu*FI[n-m]%modu;
}

LL L[maxn],R[maxn];


int main()  {
    F[0]=FI[0]=I[0]=I[1]=1;
    rep(i,1,maxn) F[i]=F[i-1]*i%modu;
    rep(i,2,maxn) I[i]=modu-modu/i*I[modu%i]%modu;
    rep(i,1,maxn) FI[i]=FI[i-1]*I[i]%modu;
    rep(i,0,maxn) assert(F[i]*FI[i]%modu==1);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    read(n,m);
    auto solve=[&](int n,int m,int offset) {
        LL ans=0;
        rep(j,0,m-1)  {
            rep(i,0,n) L[i]=C(j+1+i,j+1)*C(j+n-i-1,j)%modu; //right-end
            rep(i,0,n) R[i]=C(m-j-2+i,m-j-2)*C(m-j-2+n-i,m-j-1)%modu; // left-end
            // rep(i,0,n) print(i,C(m-j-2+i,m-j-2),"* C(",m-j-2+n-i,",",m-j-1,")");
            // dbg(j);
            // rep(i,0,n) cout<<L[i]<<" "; cout<<endl;
            // rep(i,0,n) cout<<R[i]<<" "; cout<<endl;
            LL sum=0;
            rep(i,offset,n)   {
                sum=(sum+L[i-offset])%modu;
                ans=(ans+sum*R[i])%modu;
            }
        }
        return ans*2%modu;
    };
    // print(solve(n,m,1));
    LL ans=(solve(n,m,1)+solve(m,n,2))%modu;
    print(ans);
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/