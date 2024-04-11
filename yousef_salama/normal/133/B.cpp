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
#define Trvi(it, taxis) for(__typeof(taxis.begin()) it = taxis.begin(); it != taxis.end(); ++it)
#define MAX 1000000000000000LL
using namespace std;
long long MOD = 1000003;
string toString(int i){
    stringstream ss;
    ss << i;
    return ss.str();
}
string Binary(int i){
    string s = "";
    for(int j = 0; j < 4; j++){
        if(i & (1 << j)){
            s = '1' + s;
        }
        else s = '0' + s;
    }
    return s;
}
int main(){
    string chars = "><+-.,[]";
    map <char, string> mp;
    int code = 8;
    for(int i = 0; i < chars.size(); i++){
        mp[chars[i]] = Binary(code);
        code++;
    }
    string s, a = "";
    cin >> s;
    for(int i = 0; i < s.size(); i++)
        a.append(mp[s[i]]);
    long long cur = 1, ans = 0;
    for(int i = a.size() - 1; i >= 0; i--){
        if(a[i] == '1'){
            ans += cur;
            ans %= MOD;
        }
        cur *= 2;
        cur %= MOD;
    }
    cout << ans << endl;
    return 0;
}