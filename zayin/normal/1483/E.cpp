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

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    mt19937 gen(time(0));

    int _;
    read(_);
    while (_--) {
        LL M=1e14-_;
        // dbg(M);

        auto solve=[&]()    {
            LL balance=1;
            LL l=0,r=1e14+1;

            int times=0;
            auto query=[&](LL x)    {
                ++times;
                assert(times<=105);
                // dbg(balance,x);
                
                string resp;
                // #define test
                #ifdef test
                    if (x>M&&balance<x) assert(0);
                    resp=(x<=M?"Lucky!":"Fraudster!");
                #else 
                    cout<<"? "<<x<<endl;
                    cin>>resp;
                #endif

                if (resp[0]=='L')
                    return balance+=x,l=x,1;
                else
                    return balance-=x,r=x,0;
            };
            auto maintain=[&]()    {
                while (balance<r)
                    query(l);
            };
            
            rep(i,0,46) 
                if (!query(balance))
                    break;
            
            if (r-l==1) {
                cout<<"! "<<l<<endl;
                return ;
            }
            //(l,r]

            while (1)   {
                maintain();
                // dbg(l,r,balance,times);
                if (r-l<=2) {
                    if (r-l==2)
                        query(l+1);
                    #ifdef test
                        assert(l==M);
                        dbg(times);
                    #else
                        cout<<"! "<<l<<endl;
                    #endif
                    return;
                }
                LL m1=(2*l+r+2)/3,m2=(l+1+2*r)/3;
                if (query(m1))
                    query(m2);
            }
        };
        solve();
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/