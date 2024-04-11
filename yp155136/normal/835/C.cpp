#include <iostream>
#include <stdio.h>
using namespace std;

#define int long long

int a[11][106][106];
int pre[11][106][106];

main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q,k;
	cin >> n>> q >>k;
	for (int i=0;n>i;i++) {
		int x,y,s;
		cin >> x >>y >> s;
		a[s][x][y]++;
	}
	int nn=101;
	int kk=k;
	for (int i=0;kk>=i;i++) {
		for (int j=1;nn>=j;j++) {
			for (int k=1;nn>=k;k++) {
				pre[i][j][k] = pre[i][j-1][k] + pre[i][j][k-1] - pre[i][j-1][k-1] + a[i][j][k];
			}
		}
	}
	while (q--) {
		int t,a,b,c,d;
		cin >> t >> a >> b >> c >>d;
		swap(a,c);
		swap(b,d);
		t%=(k+1);
		long long sum=0;
		for (long long i=0;k>=i;i++) {
			int num=pre[i][a][b] - pre[i][a][d-1] - pre[i][c-1][b] + pre[i][c-1][d-1];
			sum += num*((i+t)%(k+1));
		}
		cout<<sum<<endl;
	}
}