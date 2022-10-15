#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch^48),ch=getchar();
	return f?r:-r;
}
int n,k;
inline void work(){
	n=read(),k=read();
	int ans=n-k+k/2;
	printf("%d\n",ans);
	for(int i=k+1;i<=n;i++)printf("%d ",i);
	for(int i=(k+1)/2;i<k;i++)printf("%d ",i);
	puts("");	
}
int main(){
	int T=read();
	while(T--)work();
	return 0;	
}