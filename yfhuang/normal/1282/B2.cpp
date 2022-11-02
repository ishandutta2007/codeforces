#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int t;
int n, p, k;

const int maxn = 2e5 + 5;

int a[maxn];
int pre[maxn], pre1[maxn];


int main(){
    cin >> t;
    while(t--){
        scanf("%d%d%d", &n, &p, &k);
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        pre[0] = 0;
        for(int i = 1;i <= n;i++){
            pre[i] = pre[i - 1] + a[i];
        }
        for(int i = 1;i <= n;i++){
            if(i - k < 1){
                pre1[i] = a[i];
            }else{
                pre1[i] = a[i] + pre1[i - k];
            }
        }
        int ans = 0;
        for(int i = 1;i <= n;i++){
            int mod = i % k;
            long long sum = 0;
            sum += pre[mod - 1];
            sum += pre1[i];
            if(sum <= p)
                ans = i;
        }
        printf("%d\n", ans);
    }
    return 0;
}