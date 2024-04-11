#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int c, m, x;
        cin >> c >> m >> x;
        cout << min({c, m, (c+m+x)/3}) << endl;
    }
}