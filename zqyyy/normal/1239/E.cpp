#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=27,M=3e6+7;
int n,m,a[N<<1],pre[N][M];
int8_t u[N][M],f[N][M],v[N<<1],id[N<<1];
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n+n;i++)m+=a[i]=read(),id[i]=i;
	sort(a+1,a+n+n+1),swap(a[2],a[n+n]),f[0][0]=1,m-=a[1]+a[n+n];
	for(int k=2;k<n+n;k++)
		for(int i=min(k-1,n-1);i;i--)
			for(int j=m;j>=a[k];j--)
				if(!f[i][j] && f[i-1][j-a[k]])
					f[i][j]=1,pre[i][j]=j-a[k],u[i][j]=k;
	for(int i=(m+1)/2;i<=m;i++)
		if(f[n-1][i]){
			for(int j=n-1,k=i;j;k=pre[j][k],j--)v[u[j][k]]=1;
			break;
		}
	sort(id+2,id+n+n,[](int x,int y){return v[x]<v[y];});
	sort(id+2,id+n+1,[](int x,int y){return a[x]<a[y];});
	sort(id+n+1,id+n+n,[](int x,int y){return a[x]>a[y];});
	for(int k=0;k<2;k++,puts(""))
		for(int i=1;i<=n;i++)
			printf("%d ",a[id[k*n+i]]);
	return 0;
}