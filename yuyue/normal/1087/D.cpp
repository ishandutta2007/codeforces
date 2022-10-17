#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
	return w*c;
}
const LD eps=1e-9;
const int M=2e5+10;
int nxt[M],to[M],head[M],n,cnt,leaves[M],tot,from[M];
LD v[M],dep[M],len;
LD S;
bool l[M],ll[M];
void add(int x,int y){
	nxt[++cnt]=head[x]; from[cnt]=x; to[cnt]=y; head[x]=cnt;
}
void dfs(int x,int fa,int id){
	if (!nxt[head[x]]) {
		l[x]=1;
	}
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if (y==fa) continue;
		dfs(y,x,i);
	}
}
void dp(int x,int fa){
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if (y==fa) continue;
		dp(y,x);
		len=max(len,dep[x]+dep[y]+v[i]);
		dep[x]=max(dep[x],dep[y]+v[i]);
	}
}
/*
bool check(LD k){
	printf("%d\n",tot);
	for (int i=1;i<=tot;i++) 
	v[leaves[i]]=k/tot;
	memset(dep,0,sizeof(dep));
	len=0;
	dp(1,0);
	cout<<len<<"\n";
	return len>=k+eps;
}
*/
int main(){
	n=read(); S=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add(x,y); 
		add(y,x);
	}
	dfs(1,0,0);
	for (int i=1;i<=cnt;i++){
		if (l[from[i]] || l[to[i]]) 
		tot++,ll[i]=1;
//		cout<<i<<" "<<mx[i]<<" "<<ps[i]<<"\n";
	}
	tot/=2;
//	/*
	for (int i=1;i<=cnt;i++) 
	if (ll[i]){
		v[i]=S/tot;
	}
	memset(dep,0,sizeof(dep));
	len=0;
	dp(1,0);
	printf("%.9LF\n",len);
//	
//	LD l=0,r=S,ans;
//	while (l+eps<=r){
//		LD mid=(l+r)/2;
//		if (check(mid)) ans=mid,l=mid+eps;
//		else r=mid-eps;
//	}
//	printf("%.8Lf\n",ans);
//	*/
	return 0;
}