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
int n, xi, yi, wi;
vector < pair<int, int> > v[100005];
long long dfs(int i, int parn, bool can){
    long long sum = 0, Min;
    for(vector < pair<int, int> > :: iterator u = v[i].begin(); u != v[i].end(); u++)
        if(u->first != parn)
            sum += 2 * u->second + dfs(u->first, i, false);
    Min = sum;
    if(can){
        for(vector < pair <int, int> > :: iterator u = v[i].begin(); u != v[i].end(); u++)
            if(u->first != parn){
                Min = min(Min, sum - u->second - dfs(u->first, i, false) + dfs(u->first, i, true));
            }
    }
    return Min;
}
int main(){
    cin >> n;
    for(int itr = 0; itr < n - 1; itr++){
        cin >> xi >> yi >> wi;
        v[xi - 1].push_back(make_pair(yi - 1, wi));
        v[yi - 1].push_back(make_pair(xi - 1, wi));
    }
    cout << dfs(0, -1, true) << endl;
    return 0;
}