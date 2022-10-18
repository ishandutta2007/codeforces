#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    while(q--){
        string s, t;
        cin >> s >> t;

        vector <int> x(s.size()), y(s.size());

        for(int i = 0; i < (int)s.size(); i++){
            x[i] = 0;
            while(x[i] < (int)t.size() && i + x[i] < (int)s.size() && s[i + x[i]] == t[x[i]])x[i]++;

            y[i] = 0;
            while(y[i] < (int)t.size() && i + y[i] < (int)s.size() && s[i + y[i]] == t[(int)t.size() - 1 - y[i]])y[i]++;
        }


        bool found = false;
        for(int i = 0; i < (int)s.size(); i++)
        for(int j = 1; j <= x[i]; j++){
            if(j == (int)t.size())found = true;
            else{
                int k = (int)t.size() - j;
                int l = i + j - k - 1;

                if(l >= 0 && y[l] >= k)found = true;
            }
        }

        if(found)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}