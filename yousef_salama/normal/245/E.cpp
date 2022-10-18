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
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
using namespace std;
string s;
int main(){
    cin >> s;
    
    int ans = 0, x = 0, y = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '+'){
            if(x > 0){
                x--;
                y++;
            }else{
                ans++;
                y++;
            }
        }else{
            if(y > 0){
                y--;
                x++;
            }else{
                ans++;
                x++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}