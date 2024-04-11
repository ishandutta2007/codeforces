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
int n,a[N];
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	double sum=0;
	for(int i=1;i<n;i++)sum+=a[i];
	printf("%.9lf\n",sum/(n-1)+a[n]);	
}
int main(){
	int T=read();
	while(T--)work();
	return 0;	
}