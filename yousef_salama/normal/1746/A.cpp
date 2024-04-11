#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        bool found = false;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;

            if(a == 1)found = true;
        }

        if(!found)cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}