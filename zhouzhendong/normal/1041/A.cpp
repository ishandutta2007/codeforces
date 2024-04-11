#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1005;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x*f;
}
int n,a[N];
int main(){
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1);
	int ans=0;
	for (int i=1;i<n;i++)
		ans+=a[i+1]-a[i]-1;
	printf("%d",ans);
	return 0;
}