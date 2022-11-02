#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <random>
#include <array>
using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

const int N = 60;

typedef array<int, N> num;

num operator ^(const num &a, const num &b){
    num c;
    for(int i = 0;i < N;i++){
        c[i] = a[i] + b[i];
        if(c[i] >= 3) c[i] -= 3;
    }
    return c;
}

mt19937 rnd(0);
int n;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
        --a[i];
    }
    vector<num> nums(n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < N;j++){
            nums[i][j] = rnd() % 3;
        }
    }
    vector<vector<int>> pos(n);
    vector<num> pr(1);
    map<num, int> cnt;
    cnt[pr[0]] = 1;
    int cur = 0;
    ll ans = 0;
    for(int i = 0;i < n;i++){
        pr.push_back(pr.back() ^ nums[a[i]]);
        pos[a[i]].push_back(i);
        if(pos[a[i]].size() >= 4){
            while(cur <= pos[a[i]][int(pos[a[i]].size()) - 4]){
                --cnt[pr[cur]];
                ++cur;
            }
        }
        ans += cnt[pr.back()];
        ++cnt[pr.back()];
    }
    cout << ans << endl;
    return 0;
}