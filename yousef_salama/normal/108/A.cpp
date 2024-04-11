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
string to(int a){
    stringstream ss;
    ss << a;
    return ss.str();
}
bool isPal(string s){
    for(int i = 0; i < s.size(); i++)
        if(s[i] != s[(s.size() - 1) - i])return false;
    return true;
}
int main(){
//    freopen("a.in", "r", stdin);
    string s;
    cin >> s;
    int a = atoi(s.substr(0, 2).c_str());
    int b = atoi(s.substr(3, 2).c_str());
    while(1){
        b++;
        if(b > 59){
            b = 0;
            a++;
        }
        if(a > 23){
            a = 0;
        }
        string s = a / 10 == 0?"0":"", c = b / 10 == 0?"0":"";
        s += to(a);
        c += to(b);
        if(isPal(s + c)){
            cout << s << ":" << c << endl;
            break;
        }
    }
    return 0;
}