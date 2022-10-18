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
int n, a[105];
int main(){
    cin >> n;
    int sum = 0, ysum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    int i = n - 1, coins = 0;
    while(ysum <= sum){
        ysum += a[i];
        sum -= a[i];
        i--;
        coins++;
    }
    cout << coins << endl;
    return 0;
}