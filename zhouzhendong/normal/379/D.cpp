#include <bits/stdc++.h>
using namespace std;
const int N=55;
int k,x,n,m;
bool check(int i,int x,int n){
	if (n==1&&i/2==0&&i%2==1&&x==0)
		return 1;
	if (n==1&&i/2==1&&i%2==0)
		return 0;
	if (i/2==0&&i%2==0)
		return x<=(n-1)/2;
	if (i/2==0&&i%2==1)
		return x<=n/2;
	if (i%2==1)
		return x<=(n-1)/2;
	return x<=(n-2)/2;
}
int tot[N],L[N],R[N];
char s[N];
void pt(int v,int x,int n){
	s[1]=v/2?'C':'A';
	s[n]=v%2?'C':'A';
	for (int i=2;i<n;i++)
		s[i]='B';
	for (int i=v/2+1;(i+1)/2<=x;i+=2)
		s[i]='A',s[i+1]='C';
	s[n+1]='\0';
	if (n==1&&v/2==0&&v%2==1)
		s[1]='B';
	if (n==2&&v/2==0&&v%2==1&&x==0)
		s[n]='B';
	puts(s+1);
}
void Try(int x,int y,int a,int b,int n,int m,int v){
//	printf("%d %d %d %d\n",x,y,a,b);
	tot[1]=a,tot[2]=b;
	L[1]=x/2,R[1]=x%2;
	L[2]=y/2,R[2]=y%2;
	for (int i=3;i<=k;i++){
		tot[i]=tot[i-1]+tot[i-2]+(R[i-2]==0&&L[i-1]==1);
		L[i]=L[i-2],R[i]=R[i-1];
		if (tot[i]>v)
			return;
	}
//	for (int i=1;i<=k;i++)
//		printf("%d %d %d\n",tot[i],L[i],R[i]);
	if (tot[k]!=v)
		return;
	pt(x,a,n);
	pt(y,b,m);
	exit(0);
}
int main(){
	scanf("%d%d%d%d",&k,&x,&n,&m);
	for (int i=0;i<16;i++)
		for (int a=0;a<=n/2;a++)
			for (int b=0;b<=m/2;b++)
				if (check(i/4,a,n)&&check(i%4,b,m))
					Try(i/4,i%4,a,b,n,m,x);
	puts("Happy new year!");
	return 0;
}