#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int t, n;
const int maxn = 1e5 + 5;
int a[maxn];
typedef long long LL;
LL check(LL mid){
    LL mx = 1e9, mi = 0;
    for(int i = 1;i < n;i++){
        if(a[i] == -1 and a[i + 1] != -1){
            mx = min(mx, a[i + 1] + mid);
            mi = max(mi, a[i + 1] - mid);
        }else if(a[i] != -1 and a[i + 1] == -1){
            mx = min(mx, a[i] + mid);
            mi = max(mi, a[i] - mid);
        }else if(a[i] != -1 and a[i + 1] != -1){
            if(abs(a[i] - a[i + 1]) > mid)
                return -1e18;
        }
    }
    if(mi <= mx){
        return mi;
    }else{
        return -1e18;
    }
}

int main(){
    cin >> t;
    while(t--){
        scanf("%d", &n);
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i]);
        }
        LL l = 0, r = 2e9;
        while(l < r){
            //cout << l << " " << r << endl;
            int mid = (l + r) / 2;
            if(check(mid) != -1e18){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        printf("%lld %lld\n", l, check(l));
    }
    return 0;
}