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
#define oo 1 << 25
using namespace std;
int N, M, cost = 0, cur;
int room[505][3], boris[505][3];
int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < 3; j++)
            cin >> room[i][j];
    cin >> M;
    for(int i = 0; i < M; i++)
        for(int j = 0; j < 3; j++)
            cin >> boris[i][j];
    for(int i = 0; i < N; i++){
        cur = INT_MAX;
        int par = 2 * (room[i][0] + room[i][1]);
        for(int j = 0; j < M; j++){
            int a = boris[j][0] / room[i][2];
            int b = a * boris[j][1];
            if(b == 0)continue;
            int c = (par + b - 1) / b;
            cur = min(cur, c * boris[j][2]);
        }
        cost += cur;
    }
    cout << cost << endl;
    return 0;
}