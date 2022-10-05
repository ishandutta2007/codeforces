#include<bits/stdc++.h>
using namespace std;

int n,m,a[111],f[111];

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%1d",&a[i]);
	memset(f,33,sizeof f); f[1]=0;
	for (int i=2;i<=n;++i) if (a[i]){
		for (int j=max(1,i-m);j<i;++j) if (a[j]&&f[j]<233)
			f[i]=min(f[i],f[j]+1);
	}
	if (f[n]>233) return 0*puts("-1");
	cout<<f[n];
}