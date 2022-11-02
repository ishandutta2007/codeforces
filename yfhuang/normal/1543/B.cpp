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

ll A[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        ll S = 0;
        for(int i = 1;i <= n;i++){
            cin >> A[i];
            S += A[i];
        }
        ll a = (S % n);
        ll b = (n - a);
        cout << a * b << endl;
    }
    return 0;
}