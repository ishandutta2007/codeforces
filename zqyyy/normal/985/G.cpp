#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
template<class T>inline void ckmax(T &x,T y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,T y){if(x>y)x=y;}
const int N=2e5+7;
int n,m,deg[N];
ull A,B,C;
vector<int>G[N];
inline ull C2(ull n){return n*(n-1)/2;}
inline ull S(ll l,ll r){return (l+r)*(r-l+1)/2;}
inline ull calc0(){
	ull ans=0;
	for(int i=1;i<n;i++)
		ans+=i*(C*C2(i)+B*(n-i-1)*i+A*C2(n-i-1));
	return ans;
}
inline ull calc1(){
	ull ans=0;
	for(int x=0;x<n;x++)
		for(int y:G[x])
			if(x<y){
				ans+=x*(A*(n-x-2)+B*x);
				ans+=y*(B*(n-y-1)+C*(y-1));
				ans+=A*S(0,x-1)+B*S(x+1,y-1)+C*S(y+1,n-1);
			}
	return ans;
}
inline ull calc2(){
	ull ans=0;
	for(int x=0;x<n;x++){
		sort(G[x].begin(),G[x].end());int sz=G[x].size();
		int p=lower_bound(G[x].begin(),G[x].end(),x)-G[x].begin();
		ans+=x*(C*C2(p)+B*p*(sz-p)+A*C2(sz-p));
		for(int i=0;i<p;i++)
			ans+=G[x][i]*(A*(sz-i-1)+B*i);
		for(int i=p;i<sz;i++)
			ans+=G[x][i]*(B*(sz-i-1)+C*i);
	}
	return ans;
}
inline ull calc3(){
	static vector<int>g[N];
	static int tim,vis[N];
	for(int x=0;x<n;x++)
		for(int y:G[x])
			if(deg[x]>=deg[y]+(x>y))g[x].push_back(y);
	ull ans=0;
	for(int x=0;x<n;x++){
		++tim;
		for(int y:g[x])vis[y]=tim;
		for(int y:g[x])
			for(int z:g[y]){
				if(vis[z]!=tim)continue;
				static int a[3];
				a[0]=x,a[1]=y,a[2]=z;
				sort(a,a+3);
				ans+=a[0]*A+a[1]*B+a[2]*C;	
			}
	}
	return ans;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read(),m=read(),A=read(),B=read(),C=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		G[x].push_back(y),G[y].push_back(x),deg[x]++,deg[y]++;
	}
	printf("%llu\n",calc0()-calc1()+calc2()-calc3());
	return 0;
}