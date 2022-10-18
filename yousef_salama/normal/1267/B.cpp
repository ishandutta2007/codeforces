#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    vector < pair <char, int> > v;

    for(int i = 0; i < (int)s.size(); i++){
        if(v.empty() || v.back().first != s[i])v.push_back(make_pair(s[i], 1));
        else v.back().second++;
    }

    if(v.size() % 2 == 0){
        cout << "0\n";
        return 0;
    }

    if(v[v.size() / 2].second == 1){
        cout << "0\n";
        return 0;
    }

    for(int i = 0; i < (int)v.size() - 1 - i; i++){
        if(v[i].first != v[(int)v.size() - 1 - i].first || v[i].second + v[(int)v.size() - 1 - i].second < 3){
            cout << "0\n";
            return 0;
        }
    }

    cout << v[v.size() / 2].second + 1 << '\n';

    return 0;
}