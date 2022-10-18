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
int main(){
    int a[2], n;
    cin >> a[0] >> a[1] >> n;
    int turn = 0;
    while(1){
        if(n < __gcd(a[turn], n)){
            cout << (turn ^ 1) << endl;
            return 0;
        }
        n -=  __gcd(a[turn], n);
        turn ^= 1;
    }
    return 0;
}