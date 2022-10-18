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
#include <string.h>
using namespace std;
int main(){
    int n, k, c, d;
    cin >> n >> k >> c;
    bool h[n];
    memset(h, 0, sizeof h);
    for(int i = 0; i < c; i++){
        cin >> d;
        h[d - 1] = 1;
    }
    int TimeLift = k;
    int ans = 0;
    for(int i = 0; i < n; i++){
        TimeLift--;
        if(h[i]){
            ans++;
            TimeLift = k;
        }
        else if(!TimeLift){
                ans++;
                TimeLift = k;
        }
    }
    cout << ans << endl;
    return 0;
}