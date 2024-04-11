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
    string s;
    cin >> s;
    int x = 0;
    int print = 0;
    for(int i = 0; i < s.size(); i++){
        if(x == 1 && s[i] != '/'){
            cout << '/' << s[i];
            print = 1;
        }
        else if(s[i] != '/'){
            cout << s[i];
            print = 1;
        }
        if(s[i] == '/')x = 1;
        else x = 0;
    }
    if(!print)cout << '/';
    cout << endl;
    return 0;
}