#include<cstdio>
#include<vector>

using namespace std;

int main() {
	int n,p1,p2,p3,t1,t2;
	scanf("%d%d%d%d%d%d", &n, &p1, &p2, &p3, &t1, &t2);
	int res = 0;
	vector<int> l(n), r(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &l[i], &r[i]);
	}
//	printf("%d %d %d %d\n", l[0], r[0], r[0] - l[0], p1);
	for(int i = 0; i < n; ++i) res += p1*(r[i] - l[i]);
	for(int i = 0; i < n - 1; ++i) {
		int t = l[i + 1] - r[i];
		if(t < t1) res += p1 * t;
		else {
			res += p1 * t1;
			t -= t1;
			if(t < t2) res += p2*t;
			else {
				res += p2 * t2;
				res += p3 * (t - t2);
			}
		}
	}
	printf("%d\n", res);
	return 0;
}