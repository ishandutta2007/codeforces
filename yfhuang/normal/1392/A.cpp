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

const int maxn = 2e5 + 5;
int a[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    int n;
    while(T--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        bool flag = false;
        for(int i = 1;i < n;i++){
            if(a[i] != a[i + 1])
                flag = true;
        }
        if(flag){
            cout << 1 << endl;
        }else{
            cout << n << endl;
        }
    }
    return 0;
}