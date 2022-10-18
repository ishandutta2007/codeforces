#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
using namespace std;
string s;
int Max = -1    ;
bool check(int l, int r){
    string a = s.substr(l, r - l + 1);
    if(a == "1000000")return true;
    if(a.size() > 6)return false;
    if(a.size() == 1)return true;
    if(a[0] == '0')return false;
    return true;
}
int main(){
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    for(int j = i + 1; j < s.size() - 1; j++){
        if(check(0, i) && check(i + 1, j) && check(j + 1, s.size() - 1)){
            if(Max == -1)Max = atoi(s.substr(0, i + 1).c_str()) + atoi(s.substr(i + 1, j - (i + 1) + 1).c_str()) +
                    atoi(s.substr(j + 1).c_str());
            else Max = max(Max, atoi(s.substr(0, i + 1).c_str()) + atoi(s.substr(i + 1, j - (i + 1) + 1).c_str()) +
                    atoi(s.substr(j + 1).c_str()));
        }
    }
    cout << Max << endl;
    return 0;
}