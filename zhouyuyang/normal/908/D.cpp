#include<bits/stdc++.h>
#define mo 1000000007
using namespace std;
int f[1005][1005],k,pa,pb,invb,invab;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int dp(int i,int j){
	if (i+j>=k) return (i+j+1ll*pa*invb)%mo;
	if (f[i][j]!=-1) return f[i][j];
	return f[i][j]=1ll*(1ll*pa*dp(i+1,j)%mo+1ll*pb*dp(i,i+j)%mo)%mo*invab%mo;
}
int main(){
	scanf("%d%d%d",&k,&pa,&pb);
	invb=power(pb,mo-2);
	invab=power(pa+pb,mo-2);
	memset(f,-1,sizeof(f));
	printf("%d\n",dp(1,0));
}