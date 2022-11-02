#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int n, k;

const int maxn = 3e5 + 5;
int a[maxn];
typedef long long LL;
LL pre[maxn];
int main(){
    cin >> n >> k;
    pre[0] = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        pre[i] = pre[i - 1] + a[i];
    }
    sort(pre + 1, pre + n);
    LL ans = 1LL * k * pre[n];
    for(int i = 1;i < k;i++){
        ans = ans - pre[i];
    }
    cout << ans << endl;
    return 0;
}