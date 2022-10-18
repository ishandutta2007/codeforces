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
int n, a[105];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int Max = 0, Min = n - 1;
    for(int i = 0; i < n; i++)
        if(a[i] > a[Max])Max = i;
    for(int i = n - 1; i >= 0; i--)
        if(a[i] < a[Min])Min = i;

    if(Max < Min)cout << Max + (n - Min - 1) << endl;
    else cout << Max + (n - Min - 1) - 1 << endl;
    return 0;
}