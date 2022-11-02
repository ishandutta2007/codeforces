#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        LL n;
        cin >> n;
        LL left = n - 1;
        LL dx = 1;
        vector<LL> ans;
        while(left > 0){
            if(left <= dx * 2){
                ans.push_back(left - dx);
                dx = left;
            }else{
                LL ndx = min(2 * dx, left / 2); 
                ans.push_back(ndx - dx);
                dx = ndx;
            }
            left -= dx;
        }
        cout << ans.size() << endl;
        for(int i = 0;i < ans.size();i++){
            cout << ans[i];
            if(i == ans.size() - 1){
                cout << endl;
            }else{
                cout << " ";
            }
        }
    }
    return 0;
}