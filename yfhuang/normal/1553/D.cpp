#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int T;
string s, t;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> s >> t;
        int n = s.length(), m = t.length();
        int j = m - 1;
        for(int i = n - 1;i >= 0;i--){
            if(j >= 0 and s[i] == t[j]){
                j--;
            }else{
                i--;
            }
        }
        if(j < 0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}