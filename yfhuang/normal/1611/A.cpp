#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int n = s.length();
        int f = s[0] - '0';
        int l = s[n-1] - '0';
        bool all = false;
        for(int i = 0;i < n;i++){
            if((s[i] - '0') % 2 == 0)
                all = true;
        }
        if(l & 1){
            if(f % 2 == 0){
                cout << 1 << endl;
            }else{
                if(all)
                    cout << 2 << endl;
                else
                    cout << -1 << endl;
            }
        }else{
            cout << 0 << endl;
        }
    }
    return 0;
}