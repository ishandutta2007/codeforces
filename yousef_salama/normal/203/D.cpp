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
double a, b, m, vx, vy, vz;
int main(){
    cin >> a >> b >> m >> vx >> vy >> vz;
    double p1 = -vx * m / vy + a / 2, p2 = -vz * m / vy;
    while(p1 < 0 || a < p1){
        p1 = fabs(p1);
        if(a < p1)p1 = 2 * a - p1;
    }
    while(p2 < 0 || b < p2){
        p2 = fabs(p2);
        if(b < p2)p2 = 2 * b - p2;
    }
    printf("%.10f %.10f\n", p1, p2);
    return 0;
}