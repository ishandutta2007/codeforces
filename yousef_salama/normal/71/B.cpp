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
int main(){
    double n, k, t, segma;
    cin >> n >> k >> t;
    for(int i = 0; i <= n; i++){
        segma = (i * k);
        if(segma / (n * k) <= t / 100 && t / 100 < (segma + 1) / (n * k)){
            for(int j = 0; j < i; j++)
                cout << k << ' ';
            for(int j = i; j < n; j++)
                cout << 0 << ' ';
            cout << endl;
            return 0;
        }
        for(int j = 1; j <= k; j++){
            segma = (i * k) + j;
            if(segma / (n * k) <= t / 100 && t / 100 < (segma + 1) / (n * k)){
                for(int itr = 0; itr < i; itr++)
                    cout << k << ' ';
                cout << j << ' ';
                for(int itr = i + 1; itr < n; itr++)
                    cout << 0 << ' ';
                cout << endl;
                return 0;
            }
        }
    }
    return 0;
}