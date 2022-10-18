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
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
using namespace std;
int x, y, a, b, cnt;
int main(){
    cin >> x >> y >> a >> b;
    for(int p1 = a; p1 <= x; p1++)
    for(int p2 = b; p2 <= y; p2++)
        if(p1 > p2)cnt++;
    cout << cnt << endl;
    for(int p1 = a; p1 <= x; p1++)
    for(int p2 = b; p2 <= y; p2++)
        if(p1 > p2)cout << p1 << ' ' << p2 << endl;
    return 0;
}