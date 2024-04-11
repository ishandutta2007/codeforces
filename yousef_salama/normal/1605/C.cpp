#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        string s;
        cin >> n >> s;

        vector < vector <int> > v(3);
        for(int i = 0; i < n; i++)
            v[s[i] - 'a'].push_back(i);

        int res = -1;
        for(int i = 0; i < (int)v[0].size(); i++)
        for(int j = i + 1; j < (int)v[0].size() && j <= i + 2; j++){
            int cnt_b = upper_bound(v[1].begin(), v[1].end(), v[0][j]) - lower_bound(v[1].begin(), v[1].end(), v[0][i]);
            int cnt_c = upper_bound(v[2].begin(), v[2].end(), v[0][j]) - lower_bound(v[2].begin(), v[2].end(), v[0][i]);

            if(cnt_b < j - i + 1 && cnt_c < j - i + 1){
                if(res == -1 || v[0][j] - v[0][i] + 1 < res){
                    res = v[0][j] - v[0][i] + 1;
                }
            }
        }
        cout << res << '\n';
    }
    return 0;
}