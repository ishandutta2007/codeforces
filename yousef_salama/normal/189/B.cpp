#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
using namespace std;
int w, h;
long long ans;
int main(){
//    while(true){
        cin >> w >> h;
        ans = 0;
        for(int d1 = 0; d1 <= h; d1++)
        for(int d2 = 0; d2 <= w; d2++){
            int a1 = min(d1, h - d1), a2 = min(d2, w - d2);
            ans += a1 * a2;
        }
        cout << ans << endl;
//    }
    return 0;
}