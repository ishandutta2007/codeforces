#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
#define fi first
#define se second
const int N=1007;
int q;
vector<int>G[N],dep[N];
int n,rt,d,mx_dep;
inline pair<int,int> query(vector<int>d){
    q++;
    if(q>11)cout<<"! "<<n-1<<" "<<n<<endl,exit(0);
    cout<<"? "<<d.size()<<" ";
    for(int x:d)cout<<x<<" ";
    cout<<endl;int x=read(),y=read();
    return {x,y};
}
void dfs(int x,int fa,int D){
    dep[D].push_back(x),mx_dep=max(mx_dep,D);
    for(int y:G[x])if(y!=fa)dfs(y,x,D+1);
}
inline void work(){
    n=read();
    for(int i=1;i<n;i++){
	int x=read(),y=read();
	G[x].push_back(y),G[y].push_back(x);
    }
    vector<int>vec;
    for(int i=1;i<=n;i++)vec.push_back(i);
    auto res=query(vec);
    mx_dep=0,rt=res.fi,d=res.se,dfs(rt,0,0);
    int l=(d+1)>>1,r=min(d,mx_dep);
    while(l<=r){
	int mid=(l+r)>>1;auto tmp=query(dep[mid]);
	if(tmp.se==d)l=mid+1,res=tmp;
	else r=mid-1;
    }
    int A=res.fi,B;
    for(int i=0;i<=mx_dep;i++)dep[i].clear();
    mx_dep=0,dfs(A,0,0),B=query(dep[d]).fi;
    cout<<"! "<<A<<" "<<B<<endl;
    string s;cin>>s;
    if(s[0]=='I')exit(0);
}
inline void clear(){
    q=0;
    for(int i=1;i<=n;i++)G[i].clear();
    for(int i=0;i<=mx_dep;i++)dep[i].clear();
}
int main(){
//    freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
    int test=read();
    while(test--)work(),clear();
    return 0;
}