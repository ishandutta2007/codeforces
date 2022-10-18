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
string toString(int n){
    stringstream ss;
    ss << n;
    return ss.str();
}
int main(){
//    freopen("a.in", "r", stdin);
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++)
        if(s[i] == '4' || s[i] == '7')cnt++;
    string a = toString(cnt);
    for(int i = 0; i < a.size(); i++)
        if(a[i] != '4' && a[i] != '7'){
            cout << "NO" << endl;
            return 0;
        }
    cout << "YES" << endl;
    return 0;
}