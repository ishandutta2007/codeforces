#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100005],n,ans,g,x,y;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	g=a[1];
	for (int i=2;i<=n;i++) g=gcd(g,a[i]);
	if (g>1){
		printf("YES\n0");
		return 0;
	}
	for (int i=1;i<=n;i++) a[i]&=1;
	for (int i=1;i<n-1;i++)
		while (a[i]&1){
			x=a[i]; y=a[i+1];
			a[i]=(x-y+2)%2; a[i+1]=(x+y)%2;
			ans++;
		}
	if ((a[n]+a[n-1])&1) ans+=2;
	else if (a[n]%2==1&&a[n-1]%2==1) ans+=1;
	printf("YES\n%d",ans);
}