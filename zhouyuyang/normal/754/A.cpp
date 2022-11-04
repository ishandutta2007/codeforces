#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int n,x,ans,a[205],b[205],c[205],f[205];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		a[i]=a[i-1]+x;
	}
	memset(f,-1,sizeof(f));
	f[0]=0;
	for (int i=1;i<=n;i++){
		for (int j=0;j<i;j++)
			if (a[j]!=a[i]&&f[j]!=-1) f[i]=j;
	}
	f[0]=-1;
	ans=0;
	x=n;
	while (f[x]!=-1){
		ans++;
		b[ans]=x;
		x=f[x];
		c[ans]=x+1;
	}
	if (x){
		printf("NO");
		return 0;
	}
	printf("YES\n%d\n",ans);
	for (;ans;ans--) printf("%d %d\n",c[ans],b[ans]);
	return 0;
}