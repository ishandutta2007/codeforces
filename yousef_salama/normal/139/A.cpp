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
int N, a[8], ans = 0;
int main(){
    cin >> N;
    for(int i = 0; i < 7; i++)
        cin >> a[i];
    for(int i = 0; ; i++){
        N -= a[i % 7];
        if(N <= 0){
            cout << (i % 7) + 1 << endl;
            return 0;
        }
    }
    return 0;
}