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
#include <random>
#include <chrono>
using namespace std;

int n;
const int maxn = 505;
int a[maxn];
vector<int> pos[maxn];
pair<int, int> p[maxn];

int main(){
    cin >> n;
    int ans = 0;
    for(int i = 1;i <= 2 * n;i++){
        scanf("%d", &a[i]);
        pos[a[i]].push_back(i);
    }
    for(int i = 1;i <= n;i++){
        p[i] = make_pair(pos[i][0], pos[i][1]);
    }
    sort(p + 1, p + 1 + n);
    for(int i = 1;i <= n;i++){
        ans += p[i].second - p[i].first - 1;
        for(int j = i + 1;j <= n;j++){
            if(p[i].second > p[j].first and p[i].second < p[j].second){
                ans--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}