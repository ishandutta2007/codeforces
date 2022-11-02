#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1005;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
int n,m;
int a[N],c[N];
int main(){
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		c[i]=read();
	for (int i=1;i<=m;i++)
		a[i]=read();
	int tot=0;
	for (int i=1,j=1;i<=m&&j<=n;i++){
		while (j<=n&&c[j]>a[i])
			j++;
		if (j<=n)
			tot++,j++;
	}
	printf("%d\n",tot);
	return 0;
}