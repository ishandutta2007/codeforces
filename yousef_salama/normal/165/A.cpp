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
int n, ans = 0, x[205], y[205];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    for(int i = 0; i < n; i++){
        bool p1 = false, p2 = false, p3 = false, p4 = false;
        for(int j = 0; j < n; j++)
            if(i != j){
                p1 |= x[j] > x[i] && y[j] == y[i];
                p2 |= x[j] < x[i] && y[j] == y[i];
                p3 |= x[j] == x[i] && y[j] < y[i];
                p4 |= x[j] == x[i] && y[j] > y[i]; 
            }
        ans += p1 && p2 && p3 && p4;
    }
    cout << ans << endl;
    return 0;
}