#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int read(){
	int x=0;
	char ch=getchar();
	while (!('0'<=ch&&ch<='9'))
		ch=getchar();
	while ('0'<=ch&&ch<='9')
		x=x*10+ch-48,ch=getchar();
	return x;
}
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int m,A[N],B[N];
int main(){
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		int a=read(),b=read(),c=read();
		a=a+b,b=c;
		c=gcd(a,b);
		a/=c,b/=c;
		A[i]=a*100+b;
		B[A[i]]++;
	}
	for (int i=1;i<=m;i++)
		printf("%d ",B[A[i]]);
	return 0;
}