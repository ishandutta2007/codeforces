#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=2e5+5;
int n,x[N],y[N];
inline void work(){
	n=read();int X=0,Y=0;
	for(int i=1;i<=n*2;i++){
		int a=read(),b=read();
		if(!a)y[++Y]=abs(b);
		else x[++X]=abs(a);
	}
	sort(x+1,x+n+1),sort(y+1,y+n+1);
	double ans=0;
	for(int i=1;i<=n;i++)
		ans+=sqrt(1ll*x[i]*x[i]+1ll*y[i]*y[i]);
	printf("%.10lf\n",ans);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}