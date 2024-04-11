#include<bits/stdc++.h>
#define pb push_back
#define fs first
#define sc second
#define mp make_pair
using namespace std;

int t;

int main(){
    cin >> t;

    while(t--){
        int a, b, c; cin >> a >> b >> c;
        int d, e, f, g, h; cin >> d >> e >> f >> g >> h;

        a -= d;
        b -= e;
        c -= f;

        if(a < 0 || b < 0 || c < 0){
            cout << "NO\n";
            continue;
        }

        int mins = min(a, g);
        a -= mins;
        g -= mins;

        mins = min(b, h);
        b -= mins;
        h -= mins;

        if(c >= g + h){
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
}