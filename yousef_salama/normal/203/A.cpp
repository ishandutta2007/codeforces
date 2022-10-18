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
int x, t, a, b, da, db;
int main(){
    cin >> x >> t >> a >> b >> da >> db;
    bool found = false;
    for(int p1 = -1; p1 < t; p1++)
    for(int p2 = -1; p2 < t; p2++){
        int score = (p1 == -1 ? 0 : a - p1 * da) + (p2 == -1 ? 0 : b - p2 * db);
        if(score == x)found = true;
    }
    if(found)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}