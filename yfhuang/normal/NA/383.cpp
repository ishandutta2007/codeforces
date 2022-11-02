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
int n, x;
const int maxn = 105;
int w[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        bool flag = true;
        cin >> n >> x;
        for(int i = 1;i <= n;i++){
            cin >> w[i];
        }
        sort(w + 1, w + 1 + n);
        int sum = 0;
        for(int i = 1;i <= n;i++){
            sum += w[i];
            if(sum == x){
                if(i == n)
                    flag = false;
                else{
                    swap(w[i], w[i+1]);
                    break;
                }
            }
        }
        if(flag){
            cout << "YES" << endl;
            for(int i = 1;i <= n;i++){
                cout << w[i] << ((i == n) ? '\n' : ' ');
            }
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}