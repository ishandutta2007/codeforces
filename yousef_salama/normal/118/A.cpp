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
int main(){
    string s;
    cin >> s;
    string ans = "", v = "AOYEUIaoyeui";
    for(int i = 0; i < s.size(); i++){
        bool found = 0;
        for(int j = 0; j < v.size(); j++)
            if(s[i] == v[j]){
                found = 1;
                break;
            }
        if(!found){
            ans += '.';
            ans += tolower(s[i]);
        }
    }
    cout << ans << endl;
    return 0;
}