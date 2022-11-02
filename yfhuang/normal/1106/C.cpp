#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

int n;
const int maxn = 3e5 + 5;
int a[maxn];

long long sqr(int x){
    return 1LL * x * x;
}

int main(){
    while(cin >> n){
        for(int i = 1 ;i <= n;i++){
            scanf("%d", a + i);
        }
        sort(a + 1, a + 1 + n);
        long long ans = 0;
        for(int i = 1;i <= n / 2;i++){
            ans += sqr(a[i] + a[n + 1 - i]);
        }
        cout << ans << endl;
    }
    return 0;
}