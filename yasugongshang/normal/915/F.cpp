#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define int long long
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
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
const int N=1000005;
int vis[N],n,father[N],sz[N],ans;
pair<int,int> a[N];
vector<int> v[N];
inline int getfather(int x){
	return father[x]==x?x:father[x]=getfather(father[x]);
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=mp(read(),i); father[i]=i; sz[i]=1;
	}
	for(int i=1;i<n;i++){
		int a=read(),b=read(); v[a].push_back(b); v[b].push_back(a);
	}
	sort(&a[1],&a[n+1]);
	for(int i=1;i<=n;i++){
		for(int j=0;j<v[a[i].second].size();j++)if(vis[v[a[i].second][j]]){
			int t1=getfather(a[i].second),t2=getfather(v[a[i].second][j]);
			ans+=sz[t2]*sz[t1]*a[i].first;
			father[t1]=t2; sz[t2]+=sz[t1];
		}
		vis[a[i].second]=1;
	}
	for(int i=1;i<=n;i++){
		father[i]=i; sz[i]=1; vis[i]=0;
	}
	for(int i=n;i;i--){
		for(int j=0;j<v[a[i].second].size();j++)if(vis[v[a[i].second][j]]){
			int t1=getfather(a[i].second),t2=getfather(v[a[i].second][j]);
			ans-=sz[t2]*sz[t1]*a[i].first;
			father[t1]=t2; sz[t2]+=sz[t1];
		}
		vis[a[i].second]=1;
	}
	cout<<ans<<endl;
}