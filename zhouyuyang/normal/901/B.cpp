#include<bits/stdc++.h>
using namespace std;
bitset<155> a,b,c;
int n;
int main(){
	scanf("%d",&n);
	a[1]=1; b[0]=1;
	for (int i=2;i<=n;i++){
		c=b^(a<<1);
		b=a,a=c;
	}
	printf("%d\n",n);
	for (int i=0;i<=n;i++)
		printf("%d ",a[i]?1:0);
	printf("\n%d\n",n-1);
	for (int i=0;i<n;i++)
		printf("%d ",b[i]?1:0);
}