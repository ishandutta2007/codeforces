#include <bits/stdc++.h>
using namespace std;

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

        vector <int> v;
        for(int i = 0; i < n; i++)
            if(s[i] == '2')v.push_back(i);

        if((int)v.size() == 1 || (int)v.size() == 2){
            cout << "NO\n";
            continue;
        }

        vector <string> g(n, string(n, '='));

        for(int i = 0; i < n; i++)
            g[i][i] = 'X';

        for(int i = 0; i < (int)v.size(); i++){
            int j = (i + 1) % ((int)v.size());
            g[v[i]][v[j]] = '+';
            g[v[j]][v[i]] = '-';
        }

        cout << "YES\n";
        for(int i = 0; i < n; i++)
            cout << g[i] << '\n';
    }
    return 0;
}