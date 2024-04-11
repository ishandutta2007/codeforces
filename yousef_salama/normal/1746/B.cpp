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

        vector <int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];

        int l = 0, r = n - 1, res = 0;
        while(l <= r){
            if(a[l] == 0){
                l++;
                continue;
            }
            if(a[r] == 1){
                r--;
                continue;
            }

            l++;
            r--;
            res++;
        }
        cout << res << '\n';
    }

    return 0;
}