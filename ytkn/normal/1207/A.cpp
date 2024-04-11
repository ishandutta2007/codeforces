#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int b, f, p;
        int h, c;
        cin >> b >> f >> p;
        cin >> h >> c;
        int ans = 0;
        for(int j = 0; j*2 <= 2*f; j++){
            if(j*2 > b) break;
            ans = max(ans, h*j+c*min(p, (b-j*2)/2));
            //cout << j << ' ' << h*j << ' ' << (b-j*2)/2 << endl;
            //cout << ans << endl;
        }
        cout << ans << endl;
    }
}