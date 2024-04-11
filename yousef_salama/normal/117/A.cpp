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
long long n, m, c, curTime;
void GetTime(long long i, long long t){
    curTime = i - 1;
    c = 0;
    while(curTime < t){
        if(c == 0)curTime += (m - i) * 2;
        else curTime += (i - 1) * 2;
        c ^= 1;
    }
}
int main(){
//    freopen("a.in", "r", stdin);
    cin >> n >> m;
    while(n--){
        long long a, b, t;
        cin >> a >> b >> t;
        GetTime(a, t);
        if(a == b)cout << t << endl;
        else{
            if(!c){
                if(b > a)cout << curTime + (b - a) << endl;
                else cout << curTime + ((m - a) * 2) + (a - b) << endl;
            }
            else{
                if(b < a)cout << curTime + (a - b) << endl;
                else cout << curTime + ((a - 1) * 2) + (b - a) << endl;
            }
        }
    }
    return 0;
}