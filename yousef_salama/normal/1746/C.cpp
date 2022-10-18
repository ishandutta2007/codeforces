#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector <int> a(n), inv(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i]--;
            inv[a[i]] = i;
        }

        for(int i = 0; i < n; i++){
            if(i > 0)cout << ' ';
            cout << min(n, inv[i] + 2);
        }
        cout << '\n';
    }

    return 0;
}