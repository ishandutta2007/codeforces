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

struct frac {
    LL p,q;
    frac(LL _p=0,LL _q=1)   {
        p=_p,q=_q;
    }
    bool operator < (const frac& F) const {
        return p*F.q<q*F.p;
    }
    bool operator <= (const frac& F) const {
        return p*F.q<=q*F.p;
    }
}; 
ostream& operator << (ostream& os,const frac& F)    {
    os<<F.p<<"/"<<F.q;
    return os;
}

int n,m;
int len[maxn],pos[maxn],rk[maxn];
frac a[maxn],b[maxn],g[maxn];

int L[maxn],M[maxn],R[maxn];

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int _;
    read(_);
    while (_--) {
        cin>>n>>m;
        for (int i=1;i<=n;++i) cin>>a[i].p,a[i].q=1;
        for (int i=1;i<=m;++i)  {
            cin>>len[i];
            len[i]+=len[i-1];
            LL p=0,q=0;
            for (int j=len[i-1]+1;j<=len[i];++j)
                cin>>b[j].p,b[j].q=1,p+=b[j].p,++q;
            pos[i]=i;
            g[i]=frac(p,q);
        }
        sort(a+1,a+n+1);
        reverse(a+1,a+n+1);

        sort(pos+1,pos+m+1,[&](int i,int j){
            return !(g[i]<=g[j]);
        });

        for (int i=1;i<=m;++i) rk[pos[i]]=i;

        for (int i=1;i<=m;++i)  {
            L[i]=(g[pos[i-1]]<=a[i])+L[i-1];
            M[i]=(g[pos[i]]<=a[i])+M[i-1];
            R[i]=(g[pos[i+1]]<=a[i])+R[i-1];
        }

        // for (int i=1;i<=m;++i) cout<<i<<" "<<a[i]<<endl;
        // for (int i=1;i<=m;++i) cout<<i<<" "<<g[i]<<endl;

        for (int i=1;i<=m;++i)  {
            auto find=[&](frac F)   {
                int l=1,r=m+1;
                while (l<r) {
                    int mid=(l+r)>>1;
                    if (F<=g[pos[mid]])
                        l=mid+1;
                    else
                        r=mid;
                }
                return l;
            };
            for (int j=len[i-1]+1;j<=len[i];++j)    {
                frac F=g[i];
                F.p-=b[j].p,--F.q;
                int k=find(F);

                int cnt=0;
                if (k==rk[i]) {
                    cnt=M[m]-(g[pos[k]]<=a[k])+(F<=a[k]);
                } else 
                if (k<rk[i])    {
                    cnt=M[m]-(M[rk[i]]-M[k-1])+(L[rk[i]]-L[k])+(F<=a[k]);
                } else {
                    --k;
                    // dbg(rk[i],k,M[k]-M[rk[i]-1],F,a[k]);
                    cnt=M[m]-(M[k]-M[rk[i]-1])+(R[k-1]-R[rk[i]-1])+(F<=a[k]);
                }
                cout<<(cnt==m);
                // cout<<"res:"<<cnt<<" "<<(cnt==m)<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/