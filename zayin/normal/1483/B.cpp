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

int n,a[maxn];

int nxt[maxn],tail[maxn];

int q[maxn],l,r;

int findtail(int i) {
    return !tail[i]?i:tail[i]=findtail(tail[i]);
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int _;
    read(_);
    while (_--) {
        read(n);
        readarray(a+1,n);
        rep(i,1,n+1) nxt[i]=tail[i]=0;

        l=1,r=0;
        for (int i=1,j;i<=n;i=j)  {
            for (j=i+1;j<=n&&__gcd(a[j-1],a[j])>1;) ++j;
            // cout<<"["<<i<<","<<j<<")"<<endl;
            for (int k=i;k<j-1;++k)
                nxt[k]=k+1,tail[k]=k+1;
            q[++r]=i;
        }

        auto pushback=[&](int i) {
            if (!i) return ;
            int j=findtail(q[r]);
            if (__gcd(a[i],a[j])==1) 
                q[++r]=i;
            else
                tail[j]=i,nxt[j]=i;
        };

        int flag=0;
        vector<int> res;
        while (r-l+1>1)    {
            // cout<<"q:"; for (int k=l;k<=r;++k) cout<<q[k]<<" "; cout<<endl;
            int i=q[l++];
            if (flag)    {
                // cout<<"res:"<<i<<endl;
                res.push_back(i);
                if (nxt[i])
                    pushback(nxt[i]);
                else
                    flag=0;
            } else {
                pushback(i);
                flag=1;
            }
        }

        assert(l==r);
        int k=q[l];
        while (k)   {
            if (__gcd(a[k],a[findtail(k)])>1) break;
            res.push_back(k);
            k=nxt[k];
        }

        cout<<res.size()<<" ";
        for (int x:res) cout<<x<<" "; cout<<endl;
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/