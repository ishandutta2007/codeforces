#include <bits/stdc++.h>
#define y0 _zzd0001
#define y1 _zzd0002
#define rank _zzd0003
#define next _zzd0004
using namespace std;
typedef long long LL;
typedef long double LD;
const int N=300005;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
int n;
LL a[N],b[N],L[N],R[N][2][2],suf[N][2];
int main(){
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	for (int i=1;i<=n;i++)
		b[i]=read();
	memset(L,0,sizeof L);
	memset(R,0,sizeof R);
	for (int i=1;i<=n;i++)
		if (i&1)
			L[i]=L[i-1]+a[i]*(i*2-2)+b[i]*(i*2-1);
		else
			L[i]=L[i-1]+b[i]*(i*2-2)+a[i]*(i*2-1);
	for (int i=n;i>=1;i--){
		suf[i][0]=suf[i+1][0]+a[i];
		suf[i][1]=suf[i+1][1]+b[i];
		R[i][0][0]=R[i+1][0][0]+suf[i][0];
		R[i][1][0]=R[i+1][1][0]+suf[i][1];
		R[i][0][1]=R[i+1][0][1]+a[i]*(n-i+1);
		R[i][1][1]=R[i+1][1][1]+b[i]*(n-i+1);
	}
//	for (int i=1;i<=n;i++)
//		printf("%d\n",L[i]);
//	for (int i=1;i<=n;i++)
//		printf("%d %d %d %d %d %d\n",suf[i][0],suf[i][1],R[i][0][0],R[i][0][1],R[i][1][0],R[i][1][1]);
	LL ans=0;
	for (int i=0;i<=n;i++)
		if (i&1)
			ans=max(ans,L[i]+R[i+1][1][0]+suf[i+1][1]*(i*2-1)+R[i+1][0][1]+suf[i+1][0]*(n+i-1));
		else
			ans=max(ans,L[i]+R[i+1][0][0]+suf[i+1][0]*(i*2-1)+R[i+1][1][1]+suf[i+1][1]*(n+i-1));
	printf("%I64d",ans);
	return 0;
}