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
bool x[2005], y[2005];
string s, a, b;
vector <long long> v;
int main(){
    cin >> s >> a >> b;
    for(int i = 0; i < s.size(); i++){
        if(i + a.size() <= s.size() && s.substr(i, a.size()) == a)
            x[i] = true;
        if(i + b.size() <= s.size() && s.substr(i, b.size()) == b)
            y[i + b.size() - 1] = true;
    }

    for(int i = 0; i < s.size(); i++){
        if(!x[i])
            continue;

        long long hash = 0, pow = 1;
        for(int j = i; j < s.size(); j++){
            hash += (s[j] - 'a' + 1) * pow;
            pow *= 31;

            if(j - i + 1 >= a.size() && j - i + 1 >= b.size() && y[j])
                v.push_back(hash);
        }
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    cout << v.size() << endl;
    return 0;
}