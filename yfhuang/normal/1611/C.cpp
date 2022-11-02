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

const int maxn = 2e5 + 5;
int a[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        bool ok = false;
        if(a[1] == n or a[n] == n)
            ok = true;
        if(ok){
            if(a[1] == n){
                for(int i = 2, j = n;i <= j;i ++, j--){
                    swap(a[i], a[j]);
                }
            }else{
                for(int i = 1, j = n-1;i <= j;i ++, j--){
                    swap(a[i], a[j]);
                }
            } 
            for(int i = 1;i <= n;i++){
                cout << a[i] << ((i == n) ? '\n' : ' ');
            }
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}