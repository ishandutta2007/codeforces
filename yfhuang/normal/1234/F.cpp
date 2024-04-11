#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>

using namespace std;

const int maxn = 1e6 + 5;

char s[maxn];

int f[(1 << 20) + 5];
const int mask = (1 << 20) - 1;
int main(){
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for(int i = 1;i <= n;i++){
        int tmp = 0;
        for(int j = 1;j <= 20 and i + j - 1 <= n;j++){
            int k = s[i + j - 1] - 'a';
            if(tmp & (1 << k)){
                break;
            }
            tmp |= (1 << k);
            f[tmp] = __builtin_popcount(tmp);
        }
    }
    for(int j = 0;j < 20;j++){
        for(int i = 0;i < (1 << 20);i++){
            if(i & (1 << j)){
                f[i] = max(f[i], f[i ^ (1 << j)]);
            }
        }
    }
    int ans = 0;
    for(int i = 0;i < (1 << 20);i++){
        ans = max(ans, f[i] + f[mask ^ i]); 
    }
    cout << ans << endl;
    return 0;
}