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

int n,q;
char op[10];

LL T[maxn];

LL tag[maxn];

int lowbit(int x)   {
    return x&-x;
}

void add(int i,LL x)   {
    for (;i<=n;i+=lowbit(i))
        T[i]+=x;
}
void add(int l,int r,LL x) {
    // cout<<"["<<l<<","<<r<<")"<<" "<<x<<endl;
    add(l,x);
    add(r,-x);
}
LL query(int i) {
    LL ans=0;
    for (;i;i-=lowbit(i))
        ans+=T[i];
    return ans;
}

struct node {
    int l,c;
    bool operator < (const node& nd) const {
        return l<nd.l;
    }
};
set<node> I;

int getcolor(int i) {
    auto it=prev(I.upper_bound(node{i,-1}));
    assert(it!=I.end());
    return it->c;
}

LL Q(int i) {
    LL res=query(i);
    res+=tag[getcolor(i)];
    return res;
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    I.insert(node{0,1});
    while (q--) {
        cin>>op;
        if (*op=='A')   {
            int c,x;
            cin>>c>>x;
            tag[c]+=x;
        } else
        if (*op=='C')   {
            int l,r,c;
            cin>>l>>r>>c;
            ++r;
            vector<node> p;
            p.push_back(node{l,getcolor(l)});
            int ocr=getcolor(r);
            while (1)   {
                auto it=I.lower_bound(node{l,-1});
                if (it==I.end()) break;
                if (it->l>=r) break;
                p.push_back(*it);
                I.erase(it);
            }
            p.push_back(node{r,ocr});
            for (int i=0;i<p.size()-1;++i)  {
                // cout<<"del ["<<p[i].l<<","<<p[i+1].l<<") = "<<p[i].c<<" "<<tag[p[i].c]-tag[c]<<endl;
                add(p[i].l,p[i+1].l,tag[p[i].c]-tag[c]);
            }

            I.insert(node{l,c});
            I.insert(p.back());
        } else 
        if (*op=='Q')   {
            int i;
            cin>>i;
            cout<<Q(i)<<endl;
        }
        // for (auto nd:I) cout<<"["<<nd.l<<", ... ]="<<nd.c<<endl;
        // cout<<"A="; for (int i=1;i<=n;++i) cout<<Q(i)<<" "; cout<<endl;
        // cout<<"C="; for (int i=1;i<=n;++i) cout<<getcolor(i)<<" "; cout<<endl;
        // cout<<"------------------"<<endl;
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/