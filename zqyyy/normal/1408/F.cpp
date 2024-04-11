#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
int n,k;
inline void fz(int l,int r){
	if(l==r)return;
	int mid=(l+r)>>1;
	fz(l,mid),fz(mid+1,r);
	for(int i=l;i<=mid;i++)printf("%d %d\n",i,mid+1+i-l);
}
int main(){
	n=read();
	if(n<=2)puts("0"),exit(0);
	int cnt=0;
	for(k=1;k*2<=n;k<<=1,cnt=cnt*2+k/2);
	printf("%d\n",cnt*((n!=k)+1));
	fz(1,k);if(n^k)fz(n-k+1,n);
	return 0;
}