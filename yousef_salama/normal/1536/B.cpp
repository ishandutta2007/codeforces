#include <bits/stdc++.h>
using namespace std;

bool rec(set <string>& S, string cur, int rem){
    if(rem == 0){
        if(S.count(cur))return false;

        cout << cur << '\n';
        return true;
    }

    for(char c = 'a'; c <= 'z'; c++){
        if(rec(S, cur + c, rem - 1)){
            return true;
        }
    }
    return false;
}

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

        int cnt_all = 1;
        for(int L = 1; L <= n + 1; L++){
            cnt_all *= 26;

            set <string> S;
            for(int i = 0; i + L - 1 < n; i++){
                S.insert(s.substr(i, L));
            }

            if(S.size() >= cnt_all)continue;

            rec(S, "", L);
            break;
        }
    }
    return 0;
}