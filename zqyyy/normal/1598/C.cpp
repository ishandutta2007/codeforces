#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n,a[N];
map<int,int>h;
inline void work(){
	n=read();ll sum=0,ans=0;
	for(int i=1;i<=n;i++)a[i]=read(),sum+=a[i];
	if((sum*2)%n!=0){puts("0");return;}
	sum=sum*2/n,h.clear();
	for(int i=1;i<=n;i++)ans+=h[sum-a[i]],h[a[i]]++;
	printf("%lld\n",ans);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}