#include<bits/stdc++.h>
#define mo 1000000007
using namespace std;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	int n,m; scanf("%d%d",&n,&m);
	printf("%d",1ll*power(n+1,m-1)*power(2,m)%mo*(n-m+1)%mo);
}