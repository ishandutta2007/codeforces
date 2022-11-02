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
const int maxn = 105;
vector<pair<int, pair<int, int> > >p;

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        p.clear();
        for(int i = 1;i <= n;i++){
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            p.push_back({x, {y, z}});
        }
        sort(p.begin(), p.end());
        long long L = m, R = m;
        int pre = 0;
        bool flag = true;
        for(int i = 0;i < n;i++){
            L = max(1LL * p[i].second.first, L - (p[i].first - pre));  
            R = min(R + (p[i].first - pre), 1LL * p[i].second.second);
            if(L > R){
                flag = false;
            }
            pre = p[i].first;
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}