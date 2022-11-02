#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m;

ll cal(ll x){
    ll ret = 0;
    for(int i = 1;i <= x;i++){
        ret += (i - 1) / 2;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    if(cal(n) < m){
        cout << -1 << endl;
        return 0;
    }
    int id = 0;
    for(int i = 1;i <= n;i++){
        if(cal(i) >= m){
            id = i;
            break;
        }
    }
    vector<int> res;
    for(int i = id;;i++){
        ll tmp = cal(id - 1);
        int l = i - (id - 1);
        int r = (id - 1);
        int num = (r - l + 1) / 2;
        if(tmp + num == m){
            for(int j = 1;j <= id - 1;j++){
                res.push_back(j);
            } 
            res.push_back(i);
            break;
        }
    }
    for(int i = res.size() + 1;i <= n;i++){
        int num = 1e8 + i * 10000;
        res.push_back(num);
    }
    for(int i = 0;i < res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}