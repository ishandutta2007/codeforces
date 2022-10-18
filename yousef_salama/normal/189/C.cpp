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
int n, x, mp[200005], a[200005], b[200005];
int main(){
//    while(true){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];
        for(int i = 0; i < n; i++)
            mp[b[i]] = i + 1;

        for(int i = 0; i < n; i++)
            a[i] = mp[a[i]];
        int i;
        for(i = 1; i < n; i++)
            if(a[i] < a[i - 1])break;
        cout << n - i << endl;
//    }
    return 0;
}