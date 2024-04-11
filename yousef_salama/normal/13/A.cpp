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
int main(){
    int A, a = 0, b;
    cin >> A;
    b = A - 2;
    for(int i = 2; i < A; i++){
        int n = A;
        while(n > 0){
            a += n % i;
            n /= i;
        }
    }
    cout << (a / __gcd(a, b)) << '/' << (b / __gcd(a, b)) << endl;
    return 0;
}