#include<bits/stdc++.h>
using namespace std;
int n,p,q,a[233],c[233],ans;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d%d%d",&n,&p,&q);
	p=min(p,n-1);
	c[0]=1;
	for (int i=1;i<=p;i++){
		a[i]=n+1-i;
		int k=i;
		for (int j=1;k!=1&&j<=i;j++){
			int G=gcd(k,a[j]);
			k/=G; a[j]/=G;
		}
		c[i]=1;
		for (int j=1;j<=i;j++)
			c[i]=c[i]*a[j];	
	}
	for (int i=1;i<=q;i++){
		int P=1,sum=0;
		for (int j=0;j<=p;j++){
			sum+=c[j]*P;
			P=P*i;
		}
		ans^=sum*i;
	}
	printf("%u",ans);
}