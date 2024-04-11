#include<bits/stdc++.h>
using namespace std;

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

void printr(ostream& os){os<<endl;}
template<class T, class... Args>
void printr(ostream& os, const T& t, const Args&... args){
    os<<t<<" ";
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


// DEBUG
void dbgr(ostream& os) { os<<endl; }
template<class T, class... Args>
void dbgr(ostream& os, const T& t, const Args&... args) {
	os<<t; if (sizeof...(args)) os<<", ";
	dbgr(os,args...); 
}
#define dbg(args...) cout<<#args<<" = ", dbgr(cout,##args) //cout can be changed

         
typedef long long LL;

#define maxn 3050

int n,m;
int deg[maxn];
int a[maxn][maxn];

vector<int> seq;

void dfs(int i) {
    for (int j=1;j<=n;++j)  {
        if (a[i][j])    {
            a[i][j]=a[j][i]=0;
            dfs(j);
        }
    }
    seq.push_back(i);
}

int u[maxn],v[maxn];

int fa[maxn];

int find(int i) {
    return i==fa[i]?i:fa[i]=find(fa[i]);
}

bool vis[maxn];

int main()  {
    read(n,m);
    for (int t=0;t<m;++t)   {
        int u,v;
        read(u,v);
        ++deg[u],++deg[v];
        a[u][v]=a[v][u]=1;
        tie(::u[t],::v[t])=make_pair(u,v);
    }

    int cnt=0,vert=0;
    for (int i=1;i<=n;++i)
        if (deg[i]&1)
            ++cnt,vert^=i;

    for (int i=1;i<=n;++i)  {
        cnt-=(deg[i]&1);
        for (int i=1;i<=n;++i) fa[i]=i;
        for (int t=0;t<m;++t)
            if (u[t]!=i&&v[t]!=i)
                fa[find(u[t])]=find(v[t]);
                
        vector<int> tmp;
        for (int j=1;j<=n;++j)  {  
            if (!a[i][j]) continue;
            if (deg[j]%2)  {
                --cnt,vert^=j;
                --deg[j];
                a[i][j]=a[j][i]=0;
                tmp.push_back(j);
            } else fa[find(j)]=find(i);
        }

        bool flag=(cnt<=1);

        int spcnt=0,spj=0;
        for (int j=1;j<=n;++j) vis[j]=0;
        for (int j:tmp) {
            if (vis[find(j)]) continue;
            if (find(j)!=i&&deg[j]) {
                ++spcnt,spj=j;
                vis[find(j)]=1;
            }
        }
        
        if (!cnt&&spcnt==1)   {
            a[i][spj]=a[spj][i]=1;
        } else
            flag&=!spcnt;
        // dbg(i,cnt,vert,tmp.size(),spcnt,flag);

        if (flag) {
            dfs(i);
            seq.push_back(-1);
            for (int j:tmp)
                if (spj!=j)
                    seq.push_back(j),seq.push_back(i);
            break;
        }
        for (int j:tmp) {
            ++cnt,vert^=j;
            ++deg[j];
            a[i][j]=a[j][i]=1;
        }
        cnt+=(deg[i]&1);
    }

    print(seq.size());
    for (int i:seq) cout<<i<<" ";
    return 0;
}