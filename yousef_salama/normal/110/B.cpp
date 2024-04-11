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
bool islucky(int n){
    string s = toString(n);
    for(int i = 0; i < s.size(); i++)
        if(s[i] != '4' && s[i] != '7')
            return false;
    return true;
}
int main(){
//    freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    int cnt[26];
    memset(cnt, -1, sizeof cnt);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            if(islucky(i - cnt[j]) || cnt[j] == -1){
                cout << char(j + 'a');
                cnt[j] = i;
                break;
            }
        }
    }
    cout << endl;
    return 0;
}