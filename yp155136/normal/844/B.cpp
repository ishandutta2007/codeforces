#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;
const int MAX_N = 56;

int a[MAX_N][MAX_N];
int row[MAX_N],col[MAX_N];

int main () {
	int n,m;
	scanf("%d %d",&n,&m);
	LL ans=n*m;
	for (int i=1;n>=i;i++) {
		for (int j=1;m>=j;j++) {
			scanf("%d",&a[i][j]);
			row[i] += a[i][j];
			col[j] += a[i][j];
		}
	}
	for (int i=1;n>=i;i++) {
		int _1=row[i];
		int _0=m-row[i];
		if (_1 > 1) ans += ((1LL<<_1) - _1 - 1);
		if (_0 > 1) ans += ((1LL<<_0) - _0 - 1);
	}
	for (int i=1;m>=i;i++) {
		int _1=col[i];
		int _0=n-col[i];
		if (_1 > 1) ans += ((1LL<<_1) - _1 - 1);
		if (_0 > 1) ans += ((1LL<<_0) - _0 - 1);
	}
	printf("%lld\n",ans);
}