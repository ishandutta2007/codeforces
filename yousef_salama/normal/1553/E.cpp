#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector <int> p(n);
        vector <int> cnt(n, 0);

        for(int i = 0; i < n; i++){
            cin >> p[i];
            p[i]--;

            cnt[(i - p[i] + n) % n]++;
        }

        vector <int> res;
        for(int k = 0; k < n; k++)if(cnt[k] >= n / 3){
            vector <bool> vis(n, false);
            int cnt = 0;
            for(int i = 0; i < n; i++)if(!vis[i]){
                cnt++;
            
                do{
                    vis[i] = true;
                    i = (p[i] + k) % n;
                }while(!vis[i]);
            }

            if(n - cnt <= m)res.push_back(k);
        }

        cout << res.size();
        for(int k : res)cout << ' ' << k;
        cout << '\n';
    }
    return 0;
}