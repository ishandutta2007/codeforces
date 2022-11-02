#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int t;
int x, y, a, b;

int main(){
    cin >> t;
    while(t--){
        cin >> x >> y >> a >> b;
        if((y - x) % (a + b) == 0){
            int T = (y - x) / (a + b);
            if(T > 0){
                cout << T << endl; 
                continue;
            }
        }
        cout << -1 << endl;
    }
    return 0;
}