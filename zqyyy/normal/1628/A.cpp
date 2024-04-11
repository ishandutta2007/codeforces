#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n,m,b[N],a[N],cnt[N];
bool vis[N];
inline void work(){
	n=read(),m=0;
	for(int i=1;i<=n;i++)cnt[i]=0,vis[i]=0;
	for(int i=1;i<=n;i++)a[i]=read(),cnt[a[i]]++;
	int mex=0,l=1;
	for(int i=1;i<=n;i++){
		cnt[a[i]]--,vis[a[i]]=1;
		while(vis[mex])mex++;
		if(!cnt[mex]){
			b[++m]=mex,mex=0;
			for(int j=l;j<=i;j++)vis[a[j]]=0;
			l=i+1;	
		}
	}
	printf("%d\n",m);
	for(int i=1;i<=m;i++)printf("%d ",b[i]);
	puts("");
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}