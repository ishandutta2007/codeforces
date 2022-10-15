#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
    int n, m;
    scanf("%d%d", &n, &m);
    if (m < n) {
        printf("No\n");
        return;
    }
    if (m == n) {
        printf("Yes\n");
        for (int i=0;i<n;++i) printf("1 ");
        printf("\n");
        return;
    }
    if (n % 2) {
        printf("Yes\n");
        for (int i=0;i<n-1;++i) printf("1 ");
        m -= n - 1;
        printf("%d\n", m);
        return;
    }
    if (m % 2) {
        printf("No\n");
        return;
    }
    printf("Yes\n");
    for (int i=0;i<n-2;++i) printf("1 ");
    m -= n - 2;
    m /= 2;
    printf("%d %d\n", m, m);
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}