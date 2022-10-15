#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int N = 10005;

int n, m;

int a[N], b[N];

void solve(int test_ind){
	cin >> n >> m;

	int A = 0, B = 0;

	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a[i], &b[i]);
		A = max(A, a[i]);
		B = max(B, b[i]);
	}

	if (A + B > n) {
		printf("IMPOSSIBLE\n");
		return ;
	}

	A += n - A - B;

	while (A--) {
		printf("R");
	}
	while (B--) {
		printf("W");
	}
	printf("\n");
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}