#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=99;
ll x[N],y[N],ax,ay,bx,by,xs,ys,t;
int i,j,ans;
int main(){
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&x[0],&y[0],&ax,&ay,&bx,&by,&xs,&ys,&t);
	for(i=1;x[i-1]<3e16 && y[i-1]<3e16;++i){
		x[i]=ax*x[i-1]+bx;
		y[i]=ay*y[i-1]+by;
	}
	for(;--i>=0;)for(j=i;j>=0;--j)if(min(abs(xs-x[j])+abs(ys-y[j]),
		abs(xs-x[i])+abs(ys-y[i]))+abs(x[i]-x[j])+abs(y[i]-y[j])<=t)ans=max(ans,i-j+1);
	printf("%d\n",ans);
	return 0;
}