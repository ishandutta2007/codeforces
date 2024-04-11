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
int main(){
    string s;
    cin >> s;
    int maxN = 0;
    set<string> S;
    for(int i = 0; i < s.size(); i++)
        for(int j = 0; j + i <= s.size(); j++){if(S.count(s.substr(i, j)))
            maxN = max(maxN, int(s.substr(i, j).size()));
        else S.insert(s.substr(i, j));
        }
    cout << maxN << endl;
    return 0;
}