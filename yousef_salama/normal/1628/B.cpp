#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        bool found = false;
        set <string> S, S2;

        while(n--){
            string s;
            cin >> s;

            if(found)continue;

            if(s.size() == 1){
                found = true;
                continue;
            }

            if(s.size() == 2 && s[0] == s[1]){
                found = true;
                continue;
            }

            if(s.size() == 3 && s[0] == s[2]){
                found = true;
                continue;
            }

            string r = s;
            reverse(r.begin(), r.end());

            if(S.count(r)){
                found = true;
                continue;
            }

            if(s.size() == 2 && S2.count(r)){
                found = true;
                continue;
            }


            if(s.size() == 3 && S.count(string(1, s[2]) + string(1, s[1]))){
                found = true;
                continue;
            }

            S.insert(s);
            if(s.size() == 3)S2.insert(s.substr(0, 2));
        }
    
        if(found)cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}