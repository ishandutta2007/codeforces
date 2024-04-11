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

int id[maxn],pos[maxn];

int cnt[maxn],vis[maxn];

int cuted[maxn];

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    read(n,m);
    vector<vector<int> > A(n,vector<int>(m,0));
    vector<vector<int> > B(n,vector<int>(m,0));

    map<vector<int>,vector<int> > row;
    rep(i,0,n)  
        rep(j,0,m)
            read(A[i][j]);
    rep(i,0,n)
        rep(j,0,m)
            read(B[i][j]);
    rep(i,n-1,-1)
        row[B[i]].push_back(i);
    rep(i,0,n)  {
        if (!row.count(A[i]))   {
            print("-1");
            return 0;
        }
        pos[id[i]=row[A[i]].back()]=i;
        row[A[i]].pop_back();
    }
    
    cuted[n]=1;
    rep(j,0,m)
        rep(i,1,n)
            if (B[i][j]<B[i-1][j])
                ++cnt[j];
    queue<int> q;
    rep(j,0,m)
        if (!cnt[j])
            vis[j]=1,q.push(j);
    auto cut=[&](int i) {
        cuted[i]=1;
        rep(j,0,m)  {
            if (B[i][j]<B[i-1][j])
                --cnt[j];
            if (!cnt[j]&&!vis[j])
                vis[j]=1,q.push(j);
        }
    };

    vector<int> res;
    while (q.size())    {
        int j=q.front(); q.pop();
        res.push_back(j);
        for (int i=0,k=0;i<n;i=k)   {
            for (k=i+1;!cuted[k]&&B[i][j]==B[k][j];++k);
            if (!cuted[k])
                cut(k);
        }
    }

    bool flag=1;
    for (int i=0,k=0;i<n;i=k)   {
        for (k=i+1;!cuted[k];++k);
        for (int j=i+1;j<k;++j)
            flag&=pos[j]>pos[j-1];
    }

    if (!flag)
        print("-1");
    else {
        print(res.size());
        reverse(res.begin(),res.end());
        for (int j:res) {
            auto exe=[&]()  {
                stable_sort(A.begin(),A.end(),[&](const vector<int>& a,const vector<int>& b){
                    return a[j]<b[j];
                });
            };
            exe();
            cout<<j+1<<" ";
        }
        rep(i,0,n)
            rep(j,0,m)
                assert(A[i][j]==B[i][j]);
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/