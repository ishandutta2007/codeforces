#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
const int N=200005,M=400005;
struct data{
	int son[N],nextt[M],ed[M],nedge;
	inline void aedge(int a,int b){
		nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b;
	}
}e1,e2;
int a[N],r,s1,s2,anss,tong[N],n,m,i,ans,que[N],vis[N],vv[N];
inline int yi(int x){
	return ((x-1)^1)+1;
}
inline void insert(int a,int b){
	e1.aedge(a,b); e2.aedge(b,a);
}
inline void dfs1(int p){vis[p]=1;
	for(int i=e1.son[p];i;i=e1.nextt[i]){
		if(vis[e1.ed[i]]==0)dfs1(e1.ed[i]);
	}
	que[++r]=p; //cout<<p<<endl;
}
inline void dfs2(int p){
	tong[p]=ans;
	for(int i=e2.son[p];i;i=e2.nextt[i]){
		if(tong[e2.ed[i]]==0)dfs2(e2.ed[i]);
	}
}
inline int read(){
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
vector<int> v[N];
int main(){
    m=read(); n=read();
    for(int i=1;i<=m;i++)a[i]=read();
    for(int i=1;i<=n;i++){
    	int t=read();
    	while(t--){
    		v[read()].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		if(a[i])insert(v[i][0]<<1,v[i][1]<<1),insert(yi(v[i][0]<<1),yi(v[i][1]<<1)),insert(v[i][1]<<1,v[i][0]<<1),insert(yi(v[i][1]<<1),yi(v[i][0]<<1));
		else insert(v[i][0]<<1,yi(v[i][1]<<1)),insert(yi(v[i][0]<<1),v[i][1]<<1),insert(v[i][1]<<1,yi(v[i][0]<<1)),insert(yi(v[i][1]<<1),v[i][0]<<1);
	}n*=2;
	for(int i=1;i<=n;i++)if(vis[i]==false)dfs1(i);
	for(int i=r;i;i--)if(tong[que[i]]==0){
		ans++; dfs2(que[i]);
	}
	for(int i=1;i<=n;i+=2)if(tong[i]==tong[i+1]){
		puts("NO"); return 0;
	}
	puts("YES");
}