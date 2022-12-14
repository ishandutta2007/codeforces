#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> Set;
const int N = 333333;
long long A[N], P[N], n, ans;
Set S;
int main () {
    cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> A[i], P[A[i]] = i;
	for (int i = 1; i <= n; i ++) {
		int cnt = S.order_of_key(P[i]);
		ans += i - cnt - 1 - min(cnt, i - cnt - 1);
		int mid = ((i - 1) >> 1) + 1;
		if (mid <= cnt) 
			ans += P[i] + mid - *S.find_by_order(mid - 1) - cnt - 1;
		mid = i >> 1;
		if (mid > cnt)
			ans += *S.find_by_order(mid - 1) + cnt - P[i] - mid;
		S.insert(P[i]);
		cout << ans << ' ';
	}
}