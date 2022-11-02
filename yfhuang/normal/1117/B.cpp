#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, k;
const int maxn = 2e5 + 5;
int a[maxn];

int main(){
    while(cin >> n >> m >> k){
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i]);
        }
        sort(a + 1,a + 1 + n);
        int t = m / (k + 1);
        int y = m % (k + 1);
        long long ans = (a[n] * 1LL * k * t + a[n - 1] * 1LL * t);
        ans += 1LL * y * a[n];
        cout << ans << endl;
    }
    return 0;
}