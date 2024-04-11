#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n,a[N],b[N];
inline void work(){
	n=read();
	for(int i=1;i<=n+n;i++)a[i]=b[i]=0;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	sort(a+1,a+n+1,greater<int>());
	sort(b+1,b+n+1,greater<int>());
	int k=n-n/4,k1=k;
	ll s1=0,s2=0;
	for(int i=1;i<=k;i++)s1+=a[i];
	for(int i=1;i<=k;i++)s2+=b[i];
	for(int i=0;;){
		if(s1>=s2){printf("%d\n",i);return;}
		i++;
		int tmp=n+i-(i+n)/4;s1+=100;
		s1-=a[k--];
		while(tmp>k1)s2+=b[++k1],s1+=a[++k];
	}
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}