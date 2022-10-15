#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

long long solve1(vector<int> a, int g){
	long long ans = 0;
	int n = a.size();
	for (int i=0;i<g;++i){
		int mn = 1000000000;
		int c = 0;
		for (int j=i;j<n;j+=g){
			mn = min(mn, abs(a[j]));
			ans += abs(a[j]);
			if (a[j] < 0){
				c++;
			}
		}
		if (c%2){
			ans -= mn;
			ans -= mn;
		}
	}
	return ans;
}

void solve(int test_ind){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> a(n);
	vector<int> b(m);
	for (int i=0;i<n;++i) scanf("%d",&a[i]);
	for (int i=0;i<m;++i) scanf("%d",&b[i]);
	int g = 0;
	for (int i=0;i<m;++i) g = __gcd(g, b[i]);

	long long ans = solve1(a, g);
	for (int i=0;i<g;++i){
		a[i] *= -1;
	}
	ans = max(ans, solve1(a, g));
	printf("%lld\n", ans);
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}