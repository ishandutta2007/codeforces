#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
int n,a[N];
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int p1=1,p2=1;
	for(int i=1;i<=n;i++){
		if(a[i]>a[p1])p1=i;
		if(a[i]<a[p2])p2=i;	
	}
	printf("%d %d\n",p1,p2);
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}