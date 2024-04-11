#include <bits/stdc++.h>
using namespace std;
char c[105][105];
long long b[105];
int i,j,k,l,s,n,m;
int main() {
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) scanf("%s",c[i]+1);
	for (i=1;i<=n;i++)	for (j=1;j<=m;j++)
	if (c[i][j]=='#') b[i]|=(1ll<<(j-1));
	for (i=1;i<=n;i++)	for (j=i+1;j<=n;j++)
	if ((b[i]&b[j])&&(b[i]!=b[j])) {
		puts("No");
		return 0;
	}
	memset(b,0,sizeof(b));
	for (i=1;i<=n;i++)	for (j=1;j<=m;j++)
	if (c[i][j]=='#') b[j]|=1ll<<(i-1);
	for (i=1;i<=m;i++)	for (j=i+1;j<=m;j++)
	if ((b[i]&b[j])&&(b[i]!=b[j])) {
		puts("No");
		return 0;
	}
	puts("Yes");
}