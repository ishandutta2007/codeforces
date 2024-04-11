#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2007,M=5e5+7;
int n,m,u[M],v[M];
bitset<N<<1>a[N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)u[i]=read(),v[i]=read(),a[u[i]][v[i]]=1;
	for(int i=1;i<=n;i++)a[i][i+n]=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)if(a[j][i]){swap(a[i],a[j]);break;}
		for(int j=1;j<=n;j++)if(i!=j && a[j][i])a[j]^=a[i];
	}
	for(int i=1;i<=m;i++)puts(a[v[i]][u[i]+n]?"NO":"YES");
	return 0;
}