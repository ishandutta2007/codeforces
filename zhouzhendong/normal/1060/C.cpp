#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2005;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
int n,m;
LL a[N],b[N];
LL x;
LL va[N],vb[N];
int main(){
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		a[i]=a[i-1]+read();
	for (int i=1;i<=m;i++)
		b[i]=b[i-1]+read();
	x=read();
	for (int i=1;i<=n;i++)
		va[i]=1e9;
	for (int i=1;i<=m;i++)
		vb[i]=1e9;
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			va[j-i+1]=min(va[j-i+1],a[j]-a[i-1]);
	for (int i=1;i<=m;i++)
		for (int j=i;j<=m;j++)
			vb[j-i+1]=min(vb[j-i+1],b[j]-b[i-1]);
	int ans=0;
	int j=m;
	for (int i=1;i<=n;i++){
		while (j>0&&va[i]*vb[j]>x)
			j--;
		if (!j)
			break;
		ans=max(ans,i*j);
	}
	printf("%d",ans);
	return 0;
}