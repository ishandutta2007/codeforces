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

int n,res[maxn],cand[maxn];

int ask(int a,int b,int c)  {
    // if (cand[a]==cand[b]) return cand[a];
    // if (cand[a]==cand[c]) return cand[a];
    // if (cand[b]==cand[c]) return cand[b];
    cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
    int t;
    cin>>t;
    return t;
}

vector<int> asks(int a,int b,vector<int> cs) {
    vector<int> resp;
    for (int c:cs)
        resp.push_back(ask(a,b,c));
    return resp;
}

bool allequal(int c,vector<int> v)    {
    for (int x:v)
        if (x!=c)
            return 0;
    return 1;
}

#define L(x) ((x)*3-2)
#define M(x) ((x)*3-1)
#define R(x) ((x)*3)

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int _;
    read(_);
    while (_--) {
        int g0=-1,g1=-1;
        // n=randll(2,4)*3;
        cin>>n;
        // for (int i=1;i<=n;++i) cin>>cand[i];
        // int k=7;
        // for (int i=1;i<=n;++i) cand[i]=(i>k);
        // random_shuffle(cand+1,cand+n+1);

        for (int i=1;i<=n/3;++i)    {
            res[i]=ask(L(i),M(i),R(i));
            if (res[i]==0) g0=i;
            if (res[i]==1) g1=i;
        }

        assert(~g0);
        assert(~g1);

        int c,p[2]={-1,-1};
        vector<int> pos={L(g1),M(g1),R(g1)};
        auto resp=asks(L(g0),M(g0),pos);
        if (allequal(0,resp))
            p[c=0]=L(g0);
        else {
            for (int i=0;i<pos.size();++i)
                if (resp[i])
                    p[c=1]=pos[i];
        }

        // for (int i=1;i<=n;++i) cout<<cand[i]<<" "; cout<<endl;
        // cout<<c<<" "<<p[c]<<endl;
    
        vector<int> impostors[2];
        auto append=[&](int c,vector<int> v)  {
            for (int x:v)
                impostors[c].push_back(x);
        };
        auto getall=[&](int c)    {
            // cout<<"getall:"<<c<<" "<<p[c^1]<<endl;
            for (int i=1;i<=n/3;++i)    {
                if (res[i]!=c)  continue;
                // cout<<i<<":"<<res[i]<<" "<<ask(L(i),M(i),p[c^1])<<endl;
                if (ask(L(i),M(i),p[c^1])==c)   {
                    if (ask(L(i),R(i),p[c^1])==c)
                        append(c,{L(i),M(i),R(i)});
                    else
                        append(c,{L(i),M(i)}),append(c^1,{R(i)});
                } else {
                    if (ask(L(i),R(i),p[c^1])==c)
                        append(c,{L(i),R(i)}),append(c^1,{M(i)});
                    else
                        append(c,{M(i),R(i)}),append(c^1,{L(i)});
                }
            }
            assert(impostors[c].size());
        };
        getall(c^1);
        p[c^1]=impostors[c^1].back();
        getall(c);

        sort(impostors[0].begin(),impostors[0].end());
        cout<<"! "<<impostors[0].size()<<" ";
        for (int x:impostors[0])
            cout<<x<<" ";
        cout<<endl;
        // assert(impostors[0].size()==k);
        // for (int x:impostors[0])
        //     assert(cand[x]==0);
        // cerr<<"ok:"<<n<<endl;
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/