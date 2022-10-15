#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2007;
int n,z,a[N];
inline void work(){
	n=read(),z=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,a[i]|z);
	cout<<ans<<endl;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int test=read();
	while(test--)work();
	return 0;
}