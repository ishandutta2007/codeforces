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
const int maxn = 1e5 + 5;
int a[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        int score = 0;
        for(int i = 0;i < n;i++){
            cin >> a[i];
            score ^= a[i];
        }
        if(score == 0){
            cout << "DRAW" << endl;
            continue;
        }
        int hbit = 31 - __builtin_clz(score);
        int zero = 0, one = 0;
        for(int i = 0;i < n;i++){
            if(a[i] & (1 << hbit)){
                one++;
            }else{
                zero++;
            }
        }
        if(zero % 2 == 0){
            int c = (one - 1) / 2;
            if(c % 2 == 0){
                cout << "WIN" << endl;
            }else{
                cout << "LOSE" << endl;
            }
        }else{
            int c = (one - 1) / 2;
            if(c % 2 == 1){
                cout << "WIN" << endl;
            }else{
                cout << "WIN" << endl;
            }
        }
    }
    return 0;
}