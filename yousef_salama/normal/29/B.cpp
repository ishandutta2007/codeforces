#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
using namespace std;
int main(){
     double l, d, v, g, r;
    cin >> l >> d >> v >> g >> r;
     double time1 = d / v;
     double time2 = (l - d) / v;
     double tmp = time1;
    while(tmp - (g + r) > 0)tmp -= (g + r);
     double wait = 0;
    if(tmp < g)wait = 0;
    else wait = (g + r) - tmp;
    printf("%.14f", wait+time1+time2);
    return 0;
}