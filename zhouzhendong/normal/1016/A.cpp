#include <bits/stdc++.h>
#define y0 _zzd0001
#define y1 _zzd0002
#define rank _zzd0003
#define next _zzd0004
using namespace std;
typedef long long LL;
typedef long double LD;
const int N=200005;
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
LL p[N];
LL a[N];
int main(){
	n=read(),m=read();
	for (int i=1;i<=n;i++){
		a[i]=a[i-1]+read();
		p[i]=a[i]/m;
	}
	for (int i=1;i<=n;i++)
		printf("%I64d ",p[i]-p[i-1]);
	return 0;
}