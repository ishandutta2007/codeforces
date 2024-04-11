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

map<int, long long> mp;


int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        int b;
        scanf("%d", &b);
        mp[b - i] += b;
    }
    long long ans = 0;
    for(auto v : mp){
        ans = max(ans, v.second);
    }
    cout << ans << endl;
    return 0;
}