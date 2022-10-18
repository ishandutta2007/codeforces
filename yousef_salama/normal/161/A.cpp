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
int n, m, x, y, a[100005], b[100005];
vector < pair <int, int> > v;
int main(){
    cin >> n >> m >> x >> y;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    int prev = -1;
    for(int i = 0; i < n; i++){
        int j = max(lower_bound(b, b + m, a[i] - x) - b, prev);
        if(j == m)continue;
        if(prev == j)
            j++;
        if(j == m)continue;
        if(a[i] - x <= b[j] && b[j] <= a[i] + y){
            v.push_back(make_pair(i + 1, j + 1));
            prev = j;
        }
    }
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++)
        cout << v[i].first << ' ' << v[i].second << endl;
    return 0;
}