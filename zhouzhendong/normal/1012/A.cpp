#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
/*******************************/
const int N=200005;
/*******************************/
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
int n,a[N];
int main(){
	n=read();
	for (int i=1;i<=n*2;i++)
		a[i]=read();
	sort(a+1,a+n*2+1);
	LL ans=1LL*(a[n]-a[1])*(a[n*2]-a[n+1]);
	for (int i=2;i<=n;i++)
		ans=min(ans,1LL*(a[n*2]-a[1])*(a[i+n-1]-a[i]));
	printf("%I64d",ans);
	return 0;
}