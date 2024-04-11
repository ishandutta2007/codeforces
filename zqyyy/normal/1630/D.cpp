#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e6+7;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int n,m,a[N];
inline void work(){
	n=read(),m=read();ll sum=0;
	for(int i=1;i<=n;i++)a[i]=read(),sum+=abs(a[i]);
	int g=0;
	while(m--)g=gcd(g,read());
	ll v1=0,v2=0;
	for(int i=1;i<=g;i++){
		int mn=1e9,cnt=0;
		for(int j=i;j<=n;j+=g){
			cnt+=a[j]<0;
			mn=min(mn,abs(a[j]));
		}
		if(cnt&1)v1+=mn;
		else v2+=mn;
	}
	sum-=min(v1,v2)<<1;
	printf("%lld\n",sum);
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int test=read();
	while(test--)work();
	return 0;
}