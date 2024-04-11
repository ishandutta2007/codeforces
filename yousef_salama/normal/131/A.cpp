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
string s;
bool flag = true;
int main(){
    cin >> s;
    for(int i = 1; i < s.size(); i++)
        if(islower(s[i]))flag = false;
    if(flag){
        for(int i = 0; i < s.size(); i++)
            if(islower(s[i]))cout << (char)toupper(s[i]);
            else cout << (char)tolower(s[i]);
        cout << endl;
    }else cout << s << endl;
    return 0;
}