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
map <string, int> mp;
string s, a, b;
int g[16][16], n, m;
vector <string> opt, cur, names;
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        mp[s] = i;
        names.push_back(s);
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g[mp[a]][mp[b]] = 1;
        g[mp[b]][mp[a]] = 1;
    }
    for(int team = 0; team < 1 << n; team++){
        for(int i = 0; i < n; i++)if((team & (1 << i)))
            for(int j = i + 1; j < n; j++)if((team & (1 << j)))
                if(g[i][j])goto skip;
        for(int i = 0; i < n; i++)
            if(team & (1 << i))cur.push_back(names[i]);
        if(cur.size() > opt.size())opt = cur;
        skip:
        cur.clear();
    }
    cout << opt.size() << endl;
    sort(opt.begin(), opt.end());
    for(int i = 0; i < opt.size(); i++)
        cout << opt[i] << endl;
    return 0;
}