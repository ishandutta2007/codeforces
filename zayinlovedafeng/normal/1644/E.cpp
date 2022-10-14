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
int x[maxn],y[maxn];

struct node {
    int ins;
    int x,l,r;
    bool operator < (const node& N) const {
        return x<N.x;
    }
};
vector<node> E;

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int _;
    read(_);
    while (_--) {
        LL n;
        string s;
        cin>>n>>s;
        // if (!~s.find('R') || !~s.find('D'))   {
        //     cout<<n<<endl;
        //     continue;
        // }
        x[s.size()]=y[s.size()]=n;
        for (int i=s.size()-1;i;--i)    {
            x[i]=x[i+1];
            y[i]=y[i+1];
            if (s[i]=='R')
                --y[i];
            else
                --x[i];
        }

        E.clear();
        bool hR=0,hD=0;
        int nx=1,ny=1;
        for (int i=0;i<s.size();++i)   {
            hR|=s[i]=='R';
            hD|=s[i]=='D';
            if (s[i]=='R')
                ++ny;
            else
                ++nx;
            int lx=nx,ly=ny;
            int rx=hD?x[i+1]:lx;
            int ry=hR?y[i+1]:ly;
            // dbg(i,s[i],hR,hD,lx,rx,ly,ry);
            E.push_back(node{1,lx,ly,ry});
            E.push_back(node{-1,rx+1,ly,ry});
        }
        sort(E.begin(),E.end());
        multiset<int> L,R;
        int last=-1;
        LL ans=1;
        for (int i=0,j=0;i<E.size();i=j)    {
            if (L.size() && R.size())   {
                LL r=*R.rbegin();
                LL l=*L.begin();
                // dbg(last,E[i].x,l,r);
                ans+=(r-l+1)*(E[i].x-last);
            } else assert(!L.size()&&!R.size());

            for (;j<E.size()&&E[j].x==E[i].x;++j)   {
                if (E[j].ins==1)    {
                    L.insert(E[j].l);
                    R.insert(E[j].r);
                } else {
                    L.erase(L.find(E[j].l));
                    R.erase(R.find(E[j].r));
                }
            }
            // dbg(i,j,E[i].x);
            last=E[i].x;
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/