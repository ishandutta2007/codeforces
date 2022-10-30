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
#define maxn 2005

int n;
int val[maxn];
int a[maxn][maxn];

vector<pair<int,int> > E;

int solve(vector<int>& pos)    {
    // print("pos=",pos);
    if (pos.size()==1) return pos.back();
    vector<int> vis(pos.size(),0);
    int mx=0;
    for (int i=0;i<pos.size();++i)  
        for (int j=0;j<pos.size();++j)
            mx=max(mx,a[pos[i]][pos[j]]);
    
    int k=++n;
    val[k]=mx;
    for (int i=0;i<pos.size();++i)  {
        if (vis[i]) continue;
        vector<int> tmp;
        for (int j=0;j<pos.size();++j)
            if (a[pos[i]][pos[j]]!=mx)
                tmp.push_back(pos[j]),vis[j]=1;
        E.emplace_back(solve(tmp),k);
    }
    return k;
}

int main()  {
    read(n);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            read(a[i][j]);
    
    vector<int> pos;
    for (int i=1;i<=n;++i)
        pos.push_back(i),val[i]=a[i][i];
    int rt=solve(pos);

    print(n);
    for (int i=1;i<=n;++i) cout<<val[i]<<" "; cout<<endl;
    print(rt);
    for (auto e:E)
        print(e.first,e.second);
    return 0;
}