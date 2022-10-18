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
string a, b;
int main(){
    cin >> a >> b;
    int ans = 0;
    for(int i = 1; i <= a.size() && i <= b.size(); i++)
        if(a.size() % i == 0 && b.size() % i == 0){
            bool flag1 = false, flag2 = false, flag3 = false;
            for(int j = 0; j < a.size(); j++)
                flag1 |= a[j] != a[j % i];
            for(int j = 0; j < b.size(); j++)
                flag2 |= b[j] != b[j % i];
            
            for(int j = 0; j < i; j++)
                flag3 |= a[j] != b[j];
            ans += !(flag1 || flag2 || flag3);
        }
    cout << ans << endl;
    return 0;
}