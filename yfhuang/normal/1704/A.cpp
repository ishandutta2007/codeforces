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
int n, m;
string a, b;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n >> m;
        cin >> a >> b;
        if(n < m){
            cout << "NO" << endl;
        }else if(n >= m){
            bool flag = false;
            for(int i = 0;i < n - m + 1;i++){
                if(a[i] == b[0]){
                    flag = true;
                }
            }
            bool match = true;
            for(int i = 1;i < m;i++){
                if(b[i] != a[n - m + i]){
                    match = false;
                }
            }
            if(flag and match){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}