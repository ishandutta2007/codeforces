#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=4e5+7;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int n,a[N];
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)ans=gcd(ans,a[i]-a[1]);
	if(!ans)ans=-1;
	printf("%d\n",ans);
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}