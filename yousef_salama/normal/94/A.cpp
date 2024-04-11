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
//    freopen("a.in", "r", stdin);
    map <string, char> mp;
    string s, a;
    cin >> s;
    for(char i = '0'; i <= '9'; i++){
        cin >> a;
        mp[a] = i;
    }
    for(int i = 0; i < 80; i += 10)
        cout << mp[s.substr(i, 10)];
    cout << endl;
    return 0;
}