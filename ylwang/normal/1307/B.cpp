#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 5;
int n , x , a[MAXN];
map <int , int> M; 
int main() {
	int T;
	scanf("%d" , &T);
	while(T -- > 0) {
		M.clear();
		scanf("%d %d" , &n , &x);
		for (int i = 1; i <= n; ++i) {
			scanf("%d" , &a[i]);
			M[a[i]] = 1;
		}
		sort(a + 1 , a + 1 + n);
		if(M[x]) {
			printf("1\n");
			continue;
		}
		int ans = 0;
		if(x % a[n] == 0) {
			printf("%d\n" , x / a[n]);
			continue;
		}
		ans += x / a[n];
		printf("%d\n" , max(2 , ans + 1));
	}
	return 0;
}