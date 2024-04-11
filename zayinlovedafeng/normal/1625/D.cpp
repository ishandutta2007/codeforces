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

#define maxh 30
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

int sz,rt;
int idx[maxn*maxh];
int ch[maxn*maxh][2];

int n,m;
int a[maxn],pos[maxn];

int highbit(int x)  {
    return !x?-1:highbit(x>>1)+1;
}

int newnode()   {
    memset(ch[sz],0,sizeof(ch[sz]));
    idx[sz]=-1;
    return sz++;
}

void ins(int id,int x)  {
    int k=rt;
    for (int b=maxh-1;b>=0;--b) {
        int c=x>>b&1;
        if (!ch[k][c])  {
            ch[k][c]=newnode();
        }
        k=ch[k][c];
    }
    idx[k]=id;
}

int find(int x) {
    int k=rt;
    for (int b=maxh-1;b>=0;--b) {
        int c=~x>>b&1;
        if (!ch[k][c]) c^=1;
        assert(ch[k][c]);
        k=ch[k][c];
    }
    assert(~idx[k]);
    return idx[k];
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i],pos[i]=i;
    
    if (!m) {
        cout<<n<<endl;
        for (int i=1;i<=n;++i)
            cout<<i<<" ";
        cout<<endl;
        return 0;
    }

    sort(pos+1,pos+n+1,[&](int i,int j){
        return a[i]<a[j];
    });

    int h=highbit(m);
    vector<int> res;
    for (int l=1,r=1;l<=n;l=r)  {
        while (r<=n&&(a[pos[l]]>>(h+1))==(a[pos[r]]>>(h+1))) ++r;
        // dbg(l,r);
        // for (int k=l;k<r;++k)
        //     dbg(pos[k],a[pos[k]]);

        if ((a[pos[l]]>>h)==(a[pos[r-1]]>>h))   {
            // dbg("case 1");
            res.push_back(pos[l]);
        } else {
            sz=0,rt=newnode();
            for (int k=l;k<r;++k)
                if (~a[pos[k]]>>h)
                    ins(pos[k],a[pos[k]]);
            
            bool flag=0;
            for (int k=l;k<r;++k)
                if (a[pos[k]]>>h)   {
                    int j=find(a[pos[k]]);
                    if ((a[j]^a[pos[k]])>=m)    {
                        flag=1;
                        res.push_back(j);
                        res.push_back(pos[k]);
                        break;
                    }
                }
            if (!flag)
                res.push_back(pos[l]);
        }
    }

    if (res.size()<=1)
        cout<<-1<<endl;
    else {
        cout<<res.size()<<endl;
        for (int i:res) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/