#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#define N 100005
using namespace std;
int a[N],f[N],g[N],n,ans;
inline int read(){
	int k=0;
	char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) k=k*10+ch-48;
	return k;
}
int main(){
	n=read();
	if (n==1){
	    printf("1");
	    return 0;
	}
	for (int i=1;i<=n;i++) a[i]=read();
	f[1]=1;
	for (int i=2;i<=n;i++) if (a[i]>a[i-1]) f[i]=f[i-1]; else f[i]=i;
	g[n]=n;
	for (int i=n-1;i>=1;i--) if (a[i]<a[i+1]) g[i]=g[i+1]; else g[i]=i;
	ans=max(g[2],n-f[n-1]+1);
	for (int i=2;i<n;i++){
		if (a[i+1]-a[i-1]>1) ans=max(ans,g[i+1]-f[i-1]+1);
		else ans=max(ans,max(g[i+1]-i+1,i-f[i-1]+1));
	}
	printf("%d",ans); 
}