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

        int i = 0;
        if((int)s.size() % 2 != (int)t.size() % 2)i++;

        int j = 0;
        while(j < (int)t.size() && i < (int)s.size()){
            if(s[i] == t[j]){
                i++;
                j++;
            }else{
                i += 2;
            }
        }
        if(j == (int)t.size())cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}