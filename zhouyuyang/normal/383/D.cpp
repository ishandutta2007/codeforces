#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#define mo 1000000007
using namespace std;
int a[1005],f[2][22100],n,c,ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	c=0;
	ans=0;
	for (int i=1;i<=n;i++){
		f[c][11005]=(f[c][11005]+1)%mo;
		c=1-c;
		memset(f[c],0,sizeof(f[c]));
		for (int j=1005;j<=21005;j++){
			f[c][j-a[i]]=(f[c][j-a[i]]+f[1-c][j])%mo;
			f[c][j+a[i]]=(f[c][j+a[i]]+f[1-c][j])%mo;
		}
		ans=(ans+f[c][11005])%mo;
	}
	printf("%d",ans);
}