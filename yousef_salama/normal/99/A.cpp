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
#include <string.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int index = -1;
    for(int i = 0; i < s.size(); i++)
        if(s[i] == '.'){
            index = i;
            break;
        }
    if(s[index - 1] != '9' && s[index + 1] < '5')cout << s.substr(0, index);
    else if(s[index - 1] != '9'){
        string ans = s.substr(0, index);
        ans[ans.size() - 1]++;
        cout << ans << endl;
    }
    else cout << "GOTO Vasilisa." << endl;
    return 0;
}