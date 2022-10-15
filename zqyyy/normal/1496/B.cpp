#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=2e5+5;
int n,K,a[N];
inline void work(){
	n=read(),K=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(!K)return (void)printf("%d\n",n);
	sort(a+1,a+n+1);a[n+1]=2e9;
	int mex=0,i=1;
	while(i<=n){
		if(a[i]==mex)i++,mex++;
		else break;
	}
	int num=(a[n]+mex+1)/2;
	int x=lower_bound(a+1,a+n+1,num)-a;
	if(num==mex){
		printf("%d\n",n+K);
		return;
	}
	if(a[x]==num)printf("%d\n",n);
	else printf("%d\n",n+1);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}