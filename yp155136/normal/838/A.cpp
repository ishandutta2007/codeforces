#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 2501;
const int INF = 1e9 +7;

int a[MAX_N][MAX_N];
int pre[MAX_N][MAX_N];
int prime[MAX_N];

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i=1;n>=i;i++) {
		string s;
		cin >> s;
		for (int j=0;m>j;j++) {
			a[i][j+1] = s[j]-'0';
		}
	}
	for (int i=1;n>=i;i++) {
		for (int j=1;m>=j;j++) {
			pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + a[i][j];
		}
	}
	int ans = INF;
	for (int k=2;MAX_N>k;k++) {
		if (prime[k] == 0) {
			for (int i=k*k;MAX_N>i;i+=k) {
				prime[i] = 1;
			}
			int cnt=0;
			for (int ii=1;;ii++) {
				for (int jj=1;;jj++) {
					int i=min(ii*k,n),j=min(jj*k,m);
					int tot=k*k;
					int a=ii*k-k+1,b=jj*k-k+1;
					int _1 = pre[i][j] - pre[i][b-1] - pre[a-1][j] + pre[a-1][b-1];
					cnt += min(tot-_1,_1);
					if (jj*k >= m) break;
				}
				if (ii*k >= n) break;
			}
			ans = min(ans,cnt);
		}
	}
	cout<<ans<<endl;
}