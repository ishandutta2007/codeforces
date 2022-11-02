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

long long cnt[1000];
const int maxn = 1e5 + 5;
char s[maxn];

int c[30];

int main(){
    int n;
    scanf("%s", s + 1);
    n = strlen(s + 1);
    long long mx = 0;
    for(int i = 1;i <= n;i++){
        cnt[s[i] - 'a' + 1]++;
        mx = max(cnt[s[i] - 'a' + 1], mx);
    }
    for(int i = 1;i <= n;i++){
        int j = (s[i] - 'a' + 1);
        for(int k = 1;k <= 26;k++){
            cnt[26 * k + j] += c[k];
        }
        c[j]++;
    }
    for(int k = 1;k < 1000;k++){
        mx = max(mx, cnt[k]);
    }
    cout << mx << endl;
    return 0;
}