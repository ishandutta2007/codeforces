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

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans = 0;
        int g1 = gcd(a, b);
        int g2 = gcd(c, d);
        a /= g1;
        b /= g1;
        c /= g2;
        d /= g2;
        int zero = 0;
        zero += (a == 0);
        zero += (c == 0);
        if(zero == 2)
            cout << 0 << endl;
        else if(zero == 1){
            cout << 1 << endl;
        }else{
            if(a == c and b == d){
                cout << 0 << endl;
            }else{
                if((1LL * a * d) % (1LL * b * c) == 0 or (1LL * b * c) % (1LL * a * d) == 0){
                    cout << 1 << endl;
                }else{
                    cout << 2 << endl;
                }
            }            
        }
    }
    return 0;
}