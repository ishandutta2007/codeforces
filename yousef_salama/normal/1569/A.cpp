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

        bool found = false;
        for(int l = 0; l < n; l++){
            int sum = s[l] == 'a' ? 1 : -1;
            for(int r = l + 1; r < n; r++){
                sum += s[r] == 'a' ? 1 : -1;
                if(sum == 0){
                    cout << l + 1 << ' ' << r + 1 << '\n';
                    found = true;

                    break;
                }
            }
            if(found)break;
        }

        if(!found)cout << "-1 -1\n";
    }
    return 0;
}