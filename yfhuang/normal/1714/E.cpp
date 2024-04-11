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
int n;
const int maxn = 2e5 + 5;
int a[maxn];
int c[11];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        memset(c, 0, sizeof(c)); 
        for(int i = 1;i <= n;i++){
            cin >> a[i];
            c[a[i] % 10]++;
        }
        if(c[0] + c[5] > 0 and c[0] + c[5] < n){
            cout << "NO" << endl;
        }else{
            if(c[0] + c[5] == 0){
                for(int i = 1;i <= n;i++){
                    while(a[i] % 10 != 8){
                        a[i] += a[i] % 10;
                    }
                }
                bool flag = true;
                for(int i = 1;i < n;i++){
                    if(((a[i] / 10) & 1) != ((a[i+1]/10) & 1))
                        flag = false;    
                }
                cout << (flag ? "YES" : "NO") << endl;
            }else{
                for(int i = 1;i <= n;i++){
                    while(a[i] % 10 != 0){
                        a[i] += a[i] % 10;
                    }
                }
                bool flag = true;
                for(int i = 1;i < n;i++){
                    if(a[i] != a[i+1])
                        flag = false;    
                }
                cout << (flag ? "YES" : "NO") << endl;
            }
        }
    }
    return 0;
}