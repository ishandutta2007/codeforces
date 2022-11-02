#include <bits/stdc++.h>
#define y0 _zzd0001
#define y1 _zzd0002
#define rank _zzd0003
#define next _zzd0004
using namespace std;
typedef long long LL;
typedef long double LD;
const int N=105;
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
int r[N],c[N];
int ans[N][N];
vector <int> x,y;
bool check(int v){
	x.clear();
	y.clear();
	for (int i=1;i<=n;i++)
		if (r[i]&v)
			x.push_back(i);
	for (int i=1;i<=m;i++)
		if (c[i]&v)
			y.push_back(i);
	int a=x.size(),b=y.size();
	if ((a^b)&1)
		return 0;
	for (int i=0;i<min(a,b);i++)
		ans[x[i]][y[i]]|=v;
	if (a>b)
		for (int i=b;i<a;i++)
			ans[x[i]][1]|=v;
	else
		for (int i=a;i<b;i++)
			ans[1][y[i]]|=v;
	return 1;
}
int main(){
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		r[i]=read();
	for (int i=1;i<=m;i++)
		c[i]=read();
	for (int i=30;i>=0;i--){
		if (!check(1<<i)){
			puts("NO");
//			printf("%d\n",i);
			return 0;
		}
	}
	puts("YES");
	for (int i=1;i<=n;i++,puts(""))
		for (int j=1;j<=m;j++)
			printf("%d ",ans[i][j]);
	
	return 0;
}