#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int maxn = 2e5 + 5;

int cnt[maxn];
int n;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        int t;
        scanf("%d",&t);
        cnt[t]++;
    }
    long long ans = 1;
    for(int i = 0;i < maxn;i++){
        if(cnt[i] > 0) ans += cnt[i] - 1;
    }
    cout << ans << endl;
    return 0;
}