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

const int maxn = 1e5 + 5;

char s[maxn];

int n;

int cnt[maxn];

int main(){
    cin >> n;
    scanf("%s", s + 1);
    /* 
    for(int i = 1;i <= n;i++){
        cnt[s[i] - 'a']++;
    }
    long long ans = 0;
    for(int i = 0;i < 26;i++){
        ans += cnt[i] * (cnt[i] + 1) / 2;
    }
    cout << ans << endl;
    */ 
    sort(s + 1, s + 1 + n);
    printf("%s\n", s + 1);
    return 0;
}