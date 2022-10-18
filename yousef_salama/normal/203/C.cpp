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
int n, d, a, b, xi, yi;
vector < pair<int, int> > v;
int main(){
    cin >> n >> d >> a >> b;
    for(int i = 0; i < n; i++){
        cin >> xi >> yi;
        v.push_back(make_pair(xi * a + yi * b, i));
    }
    sort(v.begin(), v.end());
    vector <int> ret;
    for(int i = 0; i < n; i++){
        if(d < v[i].first)break;
        else d -= v[i].first, ret.push_back(v[i].second + 1);
    }
    cout << ret.size() << endl;
    for(int i = 0; i < ret.size(); i++)
        cout << ret[i] << ' ';
    cout << endl;
    return 0;
}