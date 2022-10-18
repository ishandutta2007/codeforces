#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    int m;
    cin >> s >> m;
    int n = s.size();

    vector <int> cnt(6, 0);
    for(char c : s)
        cnt[c - 'a']++;

    vector <int> mask(s.size(), (1 << 6) - 1);
    while(m--){
        int pos;
        string w;
        cin >> pos >> w;
        
        pos--;
        mask[pos] = 0;
        for(char c : w)
            mask[pos] |= 1 << (c - 'a');
    }

    vector <int> supply(1 << 6, 0), demand(1 << 6, 0);
    for(int i = 0; i < n; i++)
    for(int j = 0; j < (1 << 6); j++)if((mask[i] & j) != 0){
        supply[j]++;
    }

    for(int j = 0; j < (1 << 6); j++){
        for(int c = 0; c < 6; c++)if(j & (1 << c))
            demand[j] += cnt[c];

        if(demand[j] > supply[j]){
            cout << "Impossible\n";
            return 0;
        }
    }

    string res = "";
    for(int i = 0; i < n; i++){
        for(int c = 0; c < 6; c++)if(cnt[c] > 0 && (mask[i] & (1 << c)) != 0){
            bool ok = true;
            for(int j = 0; j < (1 << 6); j++)if((mask[i] & j) != 0 && (j & (1 << c)) == 0){
                if(demand[j] > supply[j] - 1){
                    ok = false;
                    break;
                }
            }

            if(ok){
                res += 'a' + c;
                for(int j = 0; j < (1 << 6); j++){
                    if(mask[i] & j)supply[j]--;
                    if(j & (1 << c))demand[j]--;
                }
                cnt[c]--;

                break;
            }
        }
    }
    cout << res << '\n';

    return 0;
}