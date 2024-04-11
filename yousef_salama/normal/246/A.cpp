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
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
#define MAXN 100005
using namespace std;
int n;
int main(){
    cin >> n;
    if(n < 3)cout << -1 << endl;
    else{
        for(int i = n - 1; i >= 0; i--)
            cout << i + 1 << ' ';
        cout << endl;
    }
    return 0;
}