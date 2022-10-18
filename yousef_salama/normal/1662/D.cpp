#include <bits/stdc++.h>
using namespace std;

pair <int, string> canonical(const string& s){
    int cnt_b = 0;
    string ret = "";

    for(char c : s){
        if(c == 'B'){
            cnt_b++;
            continue;
        }

        if(ret.empty() || ret.back() != c)ret += c;
        else ret.pop_back();
    }

    return make_pair(cnt_b % 2, ret);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        string a, b;
        cin >> a >> b;

        pair <int, string> ca = canonical(a);
        pair <int, string> cb = canonical(b);

        if(ca == cb)cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}