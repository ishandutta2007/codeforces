#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

int T;
int n;

string s;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        cin >> s;
        s = s + s;
        int firstR = -1;
        int firstL = -1;
        for(int i = 0;i < 2 * n;i++){
            if(s[i] == 'R'){
                firstR = i;
                break;
            }
        }
        for(int i = 0;i < 2 * n;i++){
            if(s[i] == 'L'){
                firstL = i;
                break;
            }
        }
        if(firstR == -1 or firstL == -1){
            cout << (n + 2) / 3 << endl;
        }else{
            int st;
            if(firstR == 0){
                int cur = n;
                while(cur > 0 and s[cur - 1] == 'R'){
                    cur--;
                }
                st = cur;
            }else{
                st = firstR;
            }    
            ll ans = 0;
            for(int i = st, j = st;i < st + n;i = j + 1, j = i){
                while(j + 1 < 2 * n and s[j + 1] == 'R'){
                    j++;
                }
                int len1 = j - i + 1;
                int k = j;
                while(j + 1 < 2 * n and s[j + 1] == 'L'){
                    j++;
                }
                int len2 = j - k;
                ans += (len1 / 3) + (len2 / 3); 
            }
            cout << ans << endl;
        }
    }
    return 0;
}