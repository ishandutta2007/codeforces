#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        int mn = 10;
        for(int mask = 0; mask < (1 << 10); mask++){
            bool ok = true;
            for(int i = 0; i < 10; i++){
                if(s[i] == '0'){
                    if(mask & (1 << i)){
                        ok = false;
                        break;
                    }
                }
                if(s[i] == '1'){
                    if((mask & (1 << i)) == 0){
                        ok = false;
                        break;
                    }
                }
            }
            if(!ok)continue;

            int score[] = {0, 0};
            int rem[] = {5, 5};

            for(int i = 0; i < 10; i++){
                if(mask & (1 << i)){
                    score[i % 2]++;
                    rem[i % 2]--;
                }else{
                    rem[i % 2]--;
                }

                if(score[0] + rem[0] < score[1] || score[1] + rem[1] < score[0]){
                    mn = min(mn, i + 1);
                    break;
                }
            }
        }
        cout << mn << '\n';
    }
    return 0;
}