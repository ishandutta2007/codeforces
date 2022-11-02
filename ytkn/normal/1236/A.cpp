#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    for(int dum = 0; dum < t; dum++){
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        for(int i = 0; i <= 50; i++){
            for(int j = 0; j <= 50; j++){
                int A = i;
                int B = 2*i+j;
                int C = 2*j;
                if(A <= a && B <= b && C <= c) ans = max(ans, 3*(i+j));
            }
        }
        cout << ans << endl;
    }
}