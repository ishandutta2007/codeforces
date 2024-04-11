#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    ll n;
    cin >> T;
    while(T--){
        cin >> n;
        cout << (n + 1) / 10 << '\n';
    }
    return 0;
}