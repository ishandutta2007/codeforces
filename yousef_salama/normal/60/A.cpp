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
int main(){
    int n, k, x;
    cin >> n >> k;
    int lo = 1, hi = n;
    string a, b, s, d;
    while(k--){
        cin >> a >> b >> s;
        if(s == "right"){
            cin >> d >> x;
            lo = max(x + 1, lo);
        }
        else{
            cin >> d >> x;
            hi = min(x - 1, hi);
        }
    }
    if(lo > hi)cout << -1 << endl;
    else cout << hi - lo + 1 << endl;
    return 0;
}