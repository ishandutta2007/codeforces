#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, k;
    scanf("%d%d", &n, &k);
    vector<int> s(k);
    for (int &i: s) scanf("%d", &i);
    if (k == 1) {
        printf("YES\n");
        return;
    }
    vector<int> a(n);
    for (int i=n-k+1;i<n;++i) {
        a[i] = s[i-(n-k)] - s[i-(n-k)-1];
    }
    for (int i=n-k+2;i<n;++i) {
        if (a[i] < a[i-1]) {
            printf("NO\n");
            return;
        }
    }
    if (n == k) {
        a[0] = s[0];
        for (int i=1;i<n;++i) {
            if (a[i] < a[i-1]) {
                printf("NO\n");
                return;
            }
        }
        printf("YES\n");
        return;
    }
    if (a[n-k+1] > 0) {
        if (s[0] > 0) {
            if (s[0] > (n - k + 1) * 1ll *  a[n-k+1]) {
                printf("NO\n");
                return;
            }
        }
        printf("YES\n");
        return;
    }
    if (s[0] > 0) {
        printf("NO\n");
        return;
    }
    if (a[n-k+1] == 0) {
        printf("YES\n");
        return;
    }
    if (s[0] == 0) {
        printf("NO\n");
        return;
    }
    if (s[0] > a[n-k+1] * 1ll * (n - k + 1)) {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    return;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}