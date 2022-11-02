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

int t;
int n;
const int maxn = 1e5 + 5;
int a[maxn];
long long x;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> x;
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + 1 + n);
        long long ans = (x + a[n] - 1) / a[n];
        if(ans == 1){
            bool flag = false;
            for(int i = 1;i <= n;i++){
                if(a[i] == x)
                    flag = true;
            }
            if(flag){
                puts("1");
            }else{
                puts("2");
            }
        }else{
            printf("%lld\n", ans);
        }
    }
    return 0;
}