#include <bits/stdc++.h>
using namespace std;

int t;
int n;
typedef long long ll;

const int maxn = 1e5 + 5;

ll a[maxn];
ll val[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    val[0] = 1;
    for(int i = 1;i <= 60;i++){
        val[i] = val[i - 1] * 2 + 1;
    }
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        int ans = 0;
        for(int i = 2;i <= n;i++){
            if(a[i] < a[i - 1]){
                ll delta = a[i - 1] - a[i];
                int id = 32;
                while((delta & (1LL << id)) == 0){
                    //cout << delta << " " << 1LL << id << endl;
                    id--;
                }  
                ans = max(ans, id + 1);
                a[i] = a[i - 1];
            }
        }
        cout << ans << endl;
    }
    return 0;
}