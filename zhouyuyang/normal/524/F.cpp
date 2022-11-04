#include<map>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 2000005
using namespace std;
bool b[N];
char c[N];
int h[N],q[N];
int i,j,k,n,H,T,t;
int main(){
	scanf("%s",c+1);
	n=strlen(c+1);
	for (i=1;i<=n;i++)
		t+=(c[i]=='(')?1:-1;
	for (i=n+1;i<=n*2;i++) c[i]=c[i-n];
	if (t<0) for (i=1;i<=-t;i++) putchar('(');
	for (i=1;i<=2*n;i++)
		h[i]=h[i-1]+((c[i]=='(')?1:-1);
	H=1; T=0;
	for (i=1;i<=n;i++){
		for (;T&&h[i]<h[q[T]];T--);
		q[++T]=i;
	}
	for (i=1;i<=n;i++){
		if (h[q[H]]-h[i-1]<min(t,0)) b[i]=1;
		for (;T>=H&&h[n+i]<h[q[T]];T--);
		q[++T]=n+i;
		if (q[H]==i) H++;
	}
	for (i=1,j=2;;){
		for (;b[i];i++);
		for (;b[j];j++);
		if (i==j)
			for (j++;b[j];j++);
		if (i>n||j>n) break;
		for (k=0;k<n&&c[i+k]==c[j+k];k++);
		if (c[i+k]<c[j+k]) j=j+k+1; else i=i+k+1;
	}
	if (j<i) i=j;
	for (j=i;j<n+i;j++)
		putchar(c[j]);
	if (t>0) for (i=1;i<=t;i++) putchar(')');
}