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
int n,m,Q,f[N];
unordered_set<int>s[N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read(),m=read(),Q=read();
	bool fl=false;
	if(n>m)swap(n,m),fl=true;
	for(int i=1;i<=Q;i++){
		int x=read(),y=read();
		if(fl)swap(x,y);
		s[x].insert(y); 
	}
	f[1]=1;int ans=0;
	while(f[n]<m){
		ans++;
		for(int i=n;i;i--){
			if(!f[i])continue;
			int t=i+f[i]+(s[i].find(f[i])!=s[i].end());
			ckmax(f[min(n,t)],f[i]),f[i]=min(t,m);
		}
	}
	printf("%d\n",ans);
	return 0;
}