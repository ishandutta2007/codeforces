#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
int n,u,v,a[N];
inline void work(){
	n=read(),u=read(),v=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int cnt=1,res=1;
	for(int i=1;i<n;i++)cnt&=a[i]==a[i+1];
	for(int i=1;i<n;i++)res&=abs(a[i]-a[i+1])<=1;
	if(cnt)printf("%d\n",min(u+v,v*2));
	else if(res)printf("%d\n",min(u,v));
	else puts("0");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}