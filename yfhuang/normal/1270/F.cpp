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

using namespace std;

const int maxn = 2e5 + 5;
const int maxm = 500;

int cnt[maxm * maxn];
int n;
char s[maxn];
int pre[maxn];

int main(){
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int m = sqrt(n) + 1;
    pre[0] = 0;
    for(int i = 1;i <= n;i++){
        pre[i] = pre[i - 1] + (s[i] == '1');
    }
    long long ans = 0;
    for(int k = 0;k < m;k++){
        // (r - l + 1) = k(pre[r] - pre[l - 1]) -> (r - k pre[r]) = (l - 1) - k pre[l - 1]
        cnt[n * k]++;
        for(int i = 1;i <= n;i++){
            int idx = i + k * (n - pre[i]);
            ans += cnt[idx];
            cnt[idx]++;
        }
        for(int i = 0;i <= n;i++){
            int idx = i + k * (n - pre[i]);
            cnt[idx]--;
        }
    }
    // k >= m -> (pre[r] - pre[l - 1]) * k = r - (l - 1) <= n
    for(int d = 1;d * m <= n;d++){
        int i = 0, j = 0, k = 0;
        while(j <= n and pre[j] < d)
            j++; 
        if(j > n)
            break;
        while(k <= n and pre[k] <= d)
            k++;
        for(i = 1;i <= n;i++){
            while(j <= n and pre[j] - pre[i - 1] < d){
                j++;
            }
            if(j > n){
                break;
            }
            while(k <= n and pre[k] - pre[i - 1] <= d){
                k++;
            }
            int L = max(d * m, j - i + 1);
            int R = k - i; 
            if(L <= R){
                ans += R / d - (L - 1) / d;
            }
        }
    }
    cout << ans << endl;
    return 0;
}