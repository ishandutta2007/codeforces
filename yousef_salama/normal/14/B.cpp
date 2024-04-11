#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>

using namespace std;

#include <ext/hash_set>
#include <ext/hash_map>

using namespace __gnu_cxx;
int main(){
    int n, x, dp[1020];
    memset(dp, 0, sizeof dp);
    cin >> n >> x;
    vector <pair <int, int> > r(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        r[i] = make_pair(min(a, b), max(a, b));
        for(int j = r[i].first; j <= r[i].second; j++)
            dp[j]++;
    }
    int dist = INT_MAX;
    for(int i = 0; i < 1020; i++)
        if(dp[i] == n){
            dist = min(dist, abs(i - x));
        }
    if(dist == INT_MAX)cout << -1 << endl;
    else cout << dist << endl;
    return 0;
}