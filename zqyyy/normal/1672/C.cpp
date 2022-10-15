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
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int l=0,r=0;
	for(int i=2;i<=n;i++)
		if(a[i]==a[i-1]){
			if(!l)l=i-1;
			r=i;
		}
	int len=r-l+1,ans=len==3?1:max(r-l-2,0);
	printf("%d\n",ans);
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}