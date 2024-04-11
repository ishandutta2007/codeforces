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
        cin >> n;

        vector <string> v(3);
        cin >> v[0] >> v[1] >> v[2];

        vector <int> ind(3, 0);

        string s = "";
        for(int i = 0; i < 3 * n; i++){
            int cnt[] = {0, 0}, m = 0, mx[] = {0, 0};
            
            for(int j = 0; j < 3; j++){
                if(ind[j] < 2 * n){
                    cnt[v[j][ind[j]] - '0']++;
                    mx[v[j][ind[j]] - '0'] = max(mx[v[j][ind[j]] - '0'], ind[j]);
                    m++;
                }
            }

            if(m <= 1 || (m == 2 && mx[0] >= mx[1]) || (m == 3 && cnt[0] >= cnt[1])){
                s += '0';
                if(ind[0] < 2 * n && v[0][ind[0]] == '0')ind[0]++;
                if(ind[1] < 2 * n && v[1][ind[1]] == '0')ind[1]++;
                if(ind[2] < 2 * n && v[2][ind[2]] == '0')ind[2]++;
            }else{
                s += '1';
                if(ind[0] < 2 * n && v[0][ind[0]] == '1')ind[0]++;
                if(ind[1] < 2 * n && v[1][ind[1]] == '1')ind[1]++;
                if(ind[2] < 2 * n && v[2][ind[2]] == '1')ind[2]++;
            }
        }
        cout << s << '\n';
    }
    return 0;
}