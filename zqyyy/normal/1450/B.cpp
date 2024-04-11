#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=107;
int n,K,a[N],b[N];
inline int dist(int i,int j){
	return abs(a[i]-a[j])+abs(b[i]-b[j]);
}
vector<int>G[N];
inline void work(){
	n=read(),K=read();
	for(int i=1;i<=n;i++)a[i]=read(),b[i]=read(),G[i].clear();
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(dist(i,j)<=K)G[i].push_back(j),G[j].push_back(i);
	for(int i=1;i<=n;i++)
		if((int)G[i].size()==n-1){puts("1");return;}
	puts("-1");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}