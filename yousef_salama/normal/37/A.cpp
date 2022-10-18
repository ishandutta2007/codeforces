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
    int n, l;
    cin >> n;
    map <int, int> mp;
    for(int i = 0; i < n; i++){
        cin >> l;
        if(mp.count(l))mp[l]++;
        else mp[l] = 1;
    }
    map <int, int> :: iterator it;
    it = mp.begin();
    int maxN = 0;
    for(; it != mp.end(); it++)
        maxN = max((*it).second, maxN);
    cout << maxN << ' ' << mp.size() << endl;
    return 0;
}