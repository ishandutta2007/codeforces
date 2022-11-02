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

int n, q;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(i == 0 and j == 0){
                cout << 0;
            }else{
                if(i & 1){
                    cout << (1LL << (i + j - 1));
                }else{
                    cout << 0;
                }
            }
            if(j == n - 1){
                cout << endl;
                fflush(stdout);
            }else{
                cout << " ";
            }
        }
    }
    cin >> q;
    while(q--){
        ll sum;
        cin >> sum;
        int nx = 0, ny = 0;
        for(int i = 1;i < 2 * n;i++){
            cout << (nx + 1)<< " " << (ny+1) << endl;
            fflush(stdout);
            if(sum & (1LL << (i - 1))){
                if(nx & 1){
                    ny++;
                }else{
                    nx++;
                }
            }else{
                if(nx & 1){
                    nx++;
                }else{
                    ny++;
                }
            } 
        }
    }
    return 0;
}