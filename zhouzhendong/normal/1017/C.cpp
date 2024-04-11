#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
int n;
int a[N];
int main(){
	n=read();
	int base=sqrt(n);
	for (int i=1;i<=n;i++)
		a[i]=n-i+1;
	for (int i=1;i<=(n-1)/base;i++)
		for (int j=1;j<=base/2;j++)
			swap(a[(i-1)*base+j],a[i*base-j+1]);
	int x=n-(n-1)/base*base;
	for (int j=1;j<=x/2;j++)
		swap(a[n-j+1],a[(n-1)/base*base+j]);
	for (int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}