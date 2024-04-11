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
/*
 *    /""""""""""|
 *   /__________/
 *   |  ===  ===|
 *   |  (.)  (.)|
 *   |     ,    |
 *   |    __    |
 *    \________/
*/
int main(){
    int n, m, cnt = 1;
    cin >> n >> m;
    n++;
    while(1){
        if(m - cnt < 0){
            cout << m;
            break;
        }
        else{
            m -= cnt;
            cnt++;
            cnt %= n;
        }
    }
    return 0;
}