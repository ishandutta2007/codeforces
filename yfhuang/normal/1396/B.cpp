#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

int T;
const int maxn = 105;
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
        sort(a + 1, a + 1 + n);
        int sum = 0;
        for(int i = 1;i < n;i++){
            sum += a[i];
        }
        if(a[n] > sum){
            cout << "T" << endl;
        }else{
            if((a[n] + sum) & 1){
                cout << "T" << endl;
            }else{
                cout << "HL" << endl;
            }
        }
    }
    return 0;
}