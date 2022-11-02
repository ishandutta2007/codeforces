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

int n, m;

vector<int> a;

vector<int> b;

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        int num;
        scanf("%d", &num);
        a.push_back(num);
    }
    sort(a.begin(), a.end());
    for(int i = 1;i <= m;i++){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if(x == 1){
            b.push_back(y);
        }
    }
    sort(b.begin(), b.end());
    int id = lower_bound(b.begin(), b.end(), 1000000000) - b.begin();
    int ans = n + (b.size() - id);
    for(int i = 0;i < n;i++){
        int id = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        int tmp = i + (b.size() - id);
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}