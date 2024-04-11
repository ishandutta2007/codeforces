#include <bits/stdc++.h>
using namespace std;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        string s;
        int k;
        cin >> s >> k;

        string q = s;

        auto calc = [&](){
            int mask = 0;
            for(char c : q)
                mask |= 1 << (c - '0');
            return __builtin_popcount(mask);
        };
        auto solve = [&](int i){
            if(s[i] == '9')return string("");

            q = s;
            q[i]++;

            for(int d = '0'; d <= '9'; d++){
                for(int j = i + 1; j < (int)q.size(); j++)
                    q[j] = d;
                if(calc() <= k)return q;
            }

            for(int d = s[i] + 1; d <= '9'; d++){
                char mn = d;
                for(int j = 0; j < i; j++)
                    mn = min(mn, s[j]);

                q[i] = d;
                for(int j = i + 1; j < (int)q.size(); j++)
                    q[j] = mn;

                if(calc() <= k)return q;
            }
            return string("");
        };

        if(calc() <= k){
            cout << q << '\n';
            continue;
        }

        for(int i = (int)s.size() - 1; i >= 0; i--){
            string r = solve(i);
            if(r != ""){
                cout << r << '\n';
                break;
            }
        }
    }
    return 0;
}