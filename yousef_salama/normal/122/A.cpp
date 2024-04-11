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
#include <bitset>
using namespace std;
string toString(int i){
    stringstream ss;
    ss << i;
    return ss.str();
}
bool isLucky(int i){
    string s = toString(i);
    for(int i = 0; i < s.size(); i++)if(!(s[i] == '4' || s[i] == '7'))
        return false;
    return true;
}
int main(){
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 0; i <= n; i++)
        if(isLucky(i) && (n % i == 0))
            cnt++;
    if(cnt)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}