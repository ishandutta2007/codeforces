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
#define oo 1 << 25
using namespace std;
string toString(int a){
    stringstream ss;
    ss << a;
    return ss.str();
}
int main(){
    string s;
    cin >> s;
    int cnt = 0;
    while(s.size() != 1){
        int a = 0;
        for(int i = 0; i < s.size(); i++)
            a += s[i] - '0';
        s = toString(a);
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}