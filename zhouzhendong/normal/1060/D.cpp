#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
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
int n;
int L[N],R[N];
int main(){
	n=read();
	for (int i=1;i<=n;i++)
		L[i]=read(),R[i]=read();
	LL ans=n;
	sort(L+1,L+n+1);
	sort(R+1,R+n+1);
	for (int i=1;i<=n;i++)
		ans+=max(R[i],L[i]);
	cout << ans;
	return 0;
}