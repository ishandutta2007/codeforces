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

int n;
const int maxn = 1e5 + 5;

char s[maxn];
char t[maxn];

int cnt[4];

int main(){
    cin >> n;
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    for(int i = 1;i <= n;i++){
        int b1 = s[i] - '0';
        int b2 = t[i] - '0';
        cnt[b1 * 2 + b2]++;
    }
    long long ans = 0;
    ans += 1LL * cnt[0] * (cnt[2] + cnt[3]) + 1LL * cnt[1] * cnt[2];
    cout << ans << endl;
    return 0;
}