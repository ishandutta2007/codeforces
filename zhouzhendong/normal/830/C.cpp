#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=0,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?x:-x;
}
const int N=105;
int n;
LL k;
int a[N];
int check(LL x){
	LL tot=0;
	for (int i=1;i<=n;i++)
		tot+=x*((a[i]+x-1)/x);
	return tot<=k;
}
int main(){
	n=read(),k=read();
	for (int i=1;i<=n;i++)
		k+=a[i]=read();
	LL ans=1;
	for (LL i=sqrt(k)+1;i>=1;i--){
		if (check(i))
			ans=max(ans,i);
		if (check(k/i))
			ans=max(ans,k/i);
	}
	cout << ans;
	return 0;
}