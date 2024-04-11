#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    for(int _ = 0; _ < t; _++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        x1 -= x;
        x2 -= x;
        y1 -= y;
        y2 -= y;
        if((x1 > (b-a)) || (x2 < (b-a)) || (y1 > (d-c)) || (y2 < (d-c))){
            cout << "No" << endl;
        }else{
            if(x1 == 0 && x2 == 0 && (a != 0 || b != 0)){
                cout << "No" << endl;
            }else if(y1 == 0 && y2 == 0 && (c != 0 || d != 0)){
                cout << "No" << endl;
            }else{
                cout << "Yes" << endl;
            }
        }
    }
}