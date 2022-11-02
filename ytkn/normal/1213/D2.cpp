#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[200000];

vector<int> v[200001];

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        int b = a[i];
        v[b].push_back(0);
        int cnt = 0;
        while(true){
            if(b == 1) break;
            cnt++;
            b /= 2;
            v[b].push_back(cnt);
        }
    }
    int ans = 1e+9;
    for(int i = 1; i <= 200000; i++){
        if(v[i].size() < k) continue;
        sort(v[i].begin(), v[i].end());
        int tmp = 0;
        for(int j = 0; j < k; j++){
            tmp += v[i][j];
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}