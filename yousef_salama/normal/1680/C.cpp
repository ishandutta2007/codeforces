#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        int total1 = 0;
        for(char c : s)
            if(c == '1')total1++;

        auto can = [&](int cnt0){
            for(int i = 0, j = 0, cur0 = 0, cur1 = 0; i < (int)s.size(); i++){
                if(j < i){
                    j = i;
                    cur0 = 0;
                    cur1 = 0;
                }

                while(j < (int)s.size() && cur0 + (s[j] == '0') <= cnt0){
                    cur0 += (s[j] == '0');
                    cur1 += (s[j] == '1');
                    j++;
                }

                if(total1 - cur1 <= cnt0)return true;

                cur0 -= (s[i] == '0');
                cur1 -= (s[i] == '1');
            }

            return false;
        };

        int L = 0, R = (int)s.size();
        while(L < R){
            int mid = (L + R) / 2;

            if(can(mid))R = mid;
            else L = mid + 1;
        }

        cout << L << '\n';
    }
    return 0;
}