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
        string s, t;
        cin >> s >> t;
        int n = s.length();
        bool flag = false;
        for(int r = 0;r < n;r++){
            for(int l1 = r;l1 >= 0;l1--){
                int len1 = r - l1 + 1;
                if(s.substr(l1, len1) != t.substr(0, len1))
                    continue;
                int len2 = t.length() - len1;
                int l2 = r - len2;
                if(l2 < 0)
                    continue;
                string ss = s.substr(l2, len2);
                reverse(ss.begin(), ss.end());
                if(ss != t.substr(len1, len2))
                    continue;
                flag = true;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}