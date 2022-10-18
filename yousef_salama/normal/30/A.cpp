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
long long a, b;
int N;
long long power(int x, int n){
    long long ans = 1;
    for(int i = 0; i < n; i++)
        ans *= x;
    return ans;
}
int main(){
    cin >> a >> b >> N;
    for(int x = 0; x <= 1000; x++){
        if((a * power(x, N)) == b){
            cout << x << endl;
            return 0;
        }
        if((a * power(-x, N)) == b){
            cout << -x << endl;
            return 0;
        }
    }
    printf("No solution\n");
}