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
double Dist(int x1, int y1, int x2, int y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main(){
    int N, K, x, y, nx, ny;
    scanf("%d %d", &N, &K);
    scanf("%d %d", &x, &y);
    double dist = 0;
    for(int i = 1; i < N; i++){
        scanf("%d %d", &nx, &ny);
        dist += Dist(x, y, nx, ny);
        x = nx;
        y = ny;
    }
    printf("%.9f\n", dist * K / 50.0);
    return 0;
}