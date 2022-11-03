#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

long long n,m,k;
long long x,s;

const int maxm = 2e5 + 5;

long long a[maxm],b[maxm];

long long c[maxm],d[maxm];

int main(){
	cin >> n >> m >> k;
	cin >> x >> s;
	for(int i = 1;i <= m;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= m;i++){
		cin >> b[i];
	}
	for(int i = 1;i <= k;i++){
		cin >> c[i];
	}
	for(int i = 1;i <= k;i++){
		cin >> d[i];
	}
	long long ans = x * n;
	b[0] = 0;
	a[0] = x;
	for(int i = 0;i <= m;i++){
		long long cost = s - b[i];
		if(cost < 0) continue;
		long long p = upper_bound(d + 1,d + k + 1,cost) - d;
		p--;
		ans = min(ans,a[i] * (n - c[p]));
	}
	cout << ans << endl;
	return 0;
}