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

int n;
char s[maxn];

int x[maxn],y[maxn];
int rk[maxn],tmp[maxn],sa[maxn];

void prints(int x,int len)   {
    for (int i=0;i<(1<<len);++i)
        putchar(s[i^x]);
    puts("");
}

int main()  {
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    cin>>n>>s;
    for (int i=0;i<(1<<n);++i) sa[i]=i;
    for (int i=0;i<(1<<n);++i) rk[i]=s[i];
    sort(sa,sa+(1<<n),[&](int i,int j){
        return rk[i]<rk[j];
    });
    for (int b=0;b<n;++b)   {
        // dbg(b);
        // for (int i=0;i<(1<<n);++i)  {
        //     printf("%2d:",sa[i]);
        //     // cout<<sa[i]<<":";
        //     prints(sa[i],b);
        // }
        // for (int i=0;i<(1<<n);++i) cout<<rk[i]<<" "; cout<<endl;
        int half=1<<b;
        for (int i=0;i<(1<<n);++i)
            x[i]=i,y[i]=i^half;
        // for (int i=0;i<(1<<n);++i) dbg(i,x[i],y[i]);
        sort(sa,sa+(1<<n),[&](int i,int j){
            if (rk[x[i]]!=rk[x[j]]) return rk[x[i]]<rk[x[j]];
            return rk[y[i]]<rk[y[j]];
        });
        // for (int i=0;i<(1<<n);++i) cout<<sa[i]<<" "; cout<<endl;
        for (int i=0;i<(1<<n);++i) tmp[i]=rk[i];
        int _rk=0;
        for (int i=0,j=0;i<(1<<n);i=j)  {
            for (;j<(1<<n)&&tmp[x[sa[i]]]==tmp[x[sa[j]]]&&tmp[y[sa[i]]]==tmp[y[sa[j]]];++j)
                rk[sa[j]]=_rk;
            ++_rk;
        }
    }

    int x=min_element(rk,rk+(1<<n))-rk;
    prints(x,n);
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/

// ccffcfccfffffcccfffcccccffcccccf
// cccccffffcccccffccfcffcccccfffff