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
string Binary(int i){
    string s = "";
    for(int j = 0; j < 8; j++){
        if(i & (1 << j)){
            s = '1' + s;
        }
        else s = '0' + s;
    }
    return s;
}
int rev(int i){
    string a = Binary(i);
    string s = "";
    for(int i = a.size() - 1; i >= 0; i--)
        s += a[i];
    int ans = 0, cur = 1;
    for(int idx = s.size() - 1; idx >= 0; idx--){
        if(s[idx] == '1')ans += cur;
        cur *= 2;
    }
    return ans;
}
int main(){
    string s;
    getline(cin, s);
    for(int i = 0; i < s.size(); i++){
        int per, cur = rev(s[i]);
        if(i == 0)per = 0;
        else per = rev(s[i - 1]);
        cout << ((per - cur) + 256) % 256 << endl;
    }
    return 0;
}