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
int n, k, ans;
int main(){
//    while(true){
        cin >> n >> k;

        ans = 1 << 20;
        for(int three = 0; three <= n; three++)
        for(int four = 0; four + three <= n; four++)
        for(int five = 0; five + four + three <= n; five++){
            int two = n - (three + four + five);
            if(k == two * 2 + three * 3 + four * 4 + five * 5)
                ans = min(ans, two);
        }
        cout << ans << endl;
//    }
    return 0;
}