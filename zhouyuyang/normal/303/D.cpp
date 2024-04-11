#include<bits/stdc++.h>
using namespace std;
int n,x;
int power(int x,int y){
	int s=1,mo=n+1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d%d",&n,&x);
	for (int i=2;i*i<=n+1;i++)
		if ((n+1)%i==0) return puts("-1"),0;
	for (int i=x-1;i>1;i--){
		if (i%(n+1)==0) continue;
		int fl=0;
		for (int j=2;j*j<=n&&!fl;j++)
			if (n%j==0&&(power(i,j)==1||power(i,n/j)==1)) fl=1;
		if (!fl){
			printf("%d\n",i);
			return 0;
		}
	}
	puts("-1");
}