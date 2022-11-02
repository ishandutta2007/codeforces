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

#define maxc 26
#define maxn 1500050
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

int sz;
int fa[maxn],len[maxn];
int ch[maxn][maxc];

int id[maxn];

int n;
string str[maxn];

void ins(int i) {
    int k=0;
    for (char _c:str[i])    {
        int c=_c-'a';
        if (!ch[k][c])  {
            ch[k][c]=++sz;
            len[sz]=len[k]+1;
        }
        k=ch[k][c];
    }
    id[k]=k;
}

vector<int> G[maxn];

int L[maxn],R[maxn],timestamp;

void dfs(int i) {
    if (!id[i]) 
        id[i]=id[fa[i]];
    L[i]=++timestamp;
    for (int j:G[i])
        dfs(j);
    R[i]=timestamp;
}

void build()    {
    queue<int> q;
    rep(c,0,maxc)
        if (ch[0][c])
            q.push(ch[0][c]);
    while (q.size())    {
        int k=q.front(); q.pop();
        G[fa[k]].push_back(k);
        rep(c,0,maxc)   {
            if (!ch[k][c])
                ch[k][c]=ch[fa[k]][c];
            else {
                fa[ch[k][c]]=ch[fa[k]][c];
                q.push(ch[k][c]);
            }
        }
    }
    dfs(0);
}

int T[maxn];

int lowbit(int x)   {
    return x&-x;
}

void add(int i,int d) {
    for (;i<=sz+1;i+=lowbit(i))
        T[i]+=d;
}

int query(int i)    {
    int res=0;
    for (;i;i-=lowbit(i))
        res+=T[i];
    return res;
}
int query(int l,int r)    {
    return query(r)-query(l-1);
}

int main()  {
    // freopen("c.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    read(n);
    rep(i,0,n)  {
        read(str[i]);
        ins(i);
    }
    build();

    
    int ans=0;
    rep(i,0,n)  {
        vector<int> match(str[i].size());

        int k=0;
        rep(j,0,str[i].size())    {
            k=ch[k][str[i][j]-'a'];
            if (match[j]=(j==str[i].size()-1?id[fa[k]]:id[k]))  {
                // dbg("add",L[match[j]]);
                add(L[match[j]],1);
            }
        }

        map<int,int> cand;
        int last=maxn;
        rep(j,(int)str[i].size()-1,-1)   {
            if (match[j]&&j-len[match[j]]<last)
                ++cand[match[j]],last=j-len[match[j]];
        }
        
        for (auto p:cand)   {
            // dbg(query(L[p.first],R[p.first]),L[p.first],R[p.second],p.second);
            if (query(L[p.first],R[p.first])==p.second)
                ++ans;
        }

        for (int x:match)
            if (x)
                add(L[x],-1);
        // rep(i,0,sz) cout<<T[i]<<" "; cout<<endl;
        
        // dbg(i,ans);
    }
    print(ans);
    
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/