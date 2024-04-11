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
const int maxn = 1e5 + 5;
int a[maxn];
int b[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 0;i < m;i++){
            cin >> a[i];
        }
        sort(a, a + m);
        for(int i = 0;i < m;i++){
            b[i] = (a[(i+1) % m] - a[i]);
            b[i]--;
            if(b[i] < 0){
                b[i] += n;
            }
        }
        sort(b, b + m);
        int t = 0;
        int protect = 0;
        for(int i = m - 1;i >= 0;i--){
            if(b[i] <= t){
                break;
            }else{
                if(b[i] <= t + 2){
                    protect++;
                    t += 2;
                }else{
                    protect += b[i] - t - 1;
                    t += 4;
                }
            }
        }
        cout << n - protect << endl;
    }
    return 0;
}