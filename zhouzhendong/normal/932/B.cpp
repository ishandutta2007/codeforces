#include <cstring>
#include <cstdio>
#include <cmath>
#include <cmath>
#include <algorithm>
using namespace std;
const int N=1000005;
int g[N],tot[N][10];
int f(int n){
	int res=1;
	while (n){
		if (n%10)
			res*=n%10;
		n/=10;
	}
	return res;
}
int main(){
	for (int i=1;i<=1000000;i++)
		if (i<10)
			g[i]=i;
		else
			g[i]=g[f(i)];
	memset(tot,0,sizeof tot);
	for (int i=1;i<=1000000;i++){
		for (int j=1;j<=9;j++)
			tot[i][j]=tot[i-1][j];
		tot[i][g[i]]++;
	}
	int q,l,r,k;
	scanf("%d",&q);
	while (q--){
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",tot[r][k]-tot[l-1][k]);
	}
	return 0;
}