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
int n, k, p, t;
vector < pair <int, int> > v;
bool cmp(pair <int, int> a, pair<int, int> b){
    return a.first > b.first || a.first == b.first && a.second < b.second;
}
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> p >> t;
        v.push_back(make_pair(p, t));
    }
    sort(v.begin(), v.end(), cmp);
    int pk = v[k - 1].first, tk = v[k - 1].second, ans = 0;
    for(int i = 0; i < n; i++)
        if(v[i].first == pk && v[i].second == tk)ans++;
    cout << ans << endl;
    return 0;
}