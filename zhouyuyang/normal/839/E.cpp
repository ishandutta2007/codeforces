#include<bits/stdc++.h>
using namespace std;
int n,m,ans,b[45];
bitset<45> vis,mp[45];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			int x; scanf("%d",&x);
			mp[i][j]=x^1;
		}
	for (int i=1;i<=n;i++)
		b[i]=i;
	for (int i=1;i<=50000;i++){
		for (int j=1;j<=n;j++) vis[j]=0;
		random_shuffle(b+1,b+n+1);
		int tmp=0;
		for (int j=1;j<=n;j++)
			if (!vis[b[j]]) tmp++,vis|=mp[b[j]];
		ans=max(ans,tmp);
	}
	printf("%.15lf\n",1.0*(ans-1)/ans/2*m*m);
}