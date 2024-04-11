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

        string q = s;
        sort(q.begin(), q.end());

        vector <int> v;
        for(int i = 0; i < n; i++)
            if(s[i] != q[i])v.push_back(i);

        if(v.empty())cout << "0\n";
        else{
            cout << "1\n";
            cout << v.size();
            for(int x : v)
                cout << ' ' << x + 1;
            cout << '\n';
        }
    }
    return 0;
}