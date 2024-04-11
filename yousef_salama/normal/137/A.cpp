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
string s;
int N, cur = 0, ans = 0;
char c;
int main(){
    cin >> s;
    N = s.size();
    c = s[0];
    for(int i = 0; i < N; i++){
        if(s[i] != c || cur + 1 > 5){
            ans++;
            cur = 0;
            c = s[i];
        }
        cur++;
    }
    ans += cur != 0;
    cout << ans << endl;
    return 0;
}