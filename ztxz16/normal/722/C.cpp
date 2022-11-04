#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int N = 100005;

multiset <long long> v;
long long now[N], ans[N];
int f[N];
int n, a[N], p[N];

int find(int i) {
	return f[i] == i ? i : (f[i] = find(f[i]));
}

void merge(int a, int b) {
	if (f[a] == -1 || f[b] == -1) {
		return;
	}
	
	a = find(a), b = find(b);
	if (a != b) {
		v.erase(v.find(now[a]));
		v.erase(v.find(now[b]));
		f[a] = b;
		now[b] += now[a];
		v.insert(now[b]);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	} 
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		f[i] = -1;
	}
	
	for (int i = n; i >= 1; i--) {
		int x = p[i];
		f[x] = x;
		now[x] = a[x];
		v.insert(a[x]);
		if (x < n) {
			merge(x, x + 1);
		}
		
		if (x > 1) {
			merge(x - 1, x);
		}
		
		ans[i - 1] = *(--v.end());
	}
	
	ans[n] = 0;
	for (int i = 1; i <= n; i++) {
		printf("%I64d\n", ans[i]);
	}
	
	return 0;
}