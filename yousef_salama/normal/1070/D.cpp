#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    vector <int> a(n);
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);

    long long res = 0;
    for(int i = 0; i < n; i++){
        res += (a[i] + k - 1) / k;
        if(i + 1 < n && a[i] % k != 0){
            int rem = k - (a[i] % k);
            a[i + 1] = max(0, a[i + 1] - rem);
        }
    }
    printf("%lld\n", res);

    return 0;
}