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
//    freopen("a.in", "r", stdin);
    int n, sum = 0;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
    }
    int s[n], p[n];

    s[0] = -2 * v[0];
    for(int i = 1; i < n; i++)
        s[i] = s[i - 1] + (-2 * v[i]);
    for(int i = 1; i < n; i++)
        s[i] = max(s[i - 1], s[i]);

    p[n - 1] = -2 * v[n - 1];
    for(int i = n - 2; i >= 0; i--)
        p[i] = p[i + 1] + (-2 * v[i]);
    for(int i = n - 2; i >= 0; i--)
        p[i] = max(p[i + 1], p[i]);
    int ans = sum;
    for(int i = 0; i < n - 1; i++)
        ans = max(ans, sum + s[i] + p[i + 1]);
    ans = max(ans, sum + p[0]);
    ans = max(ans, sum + s[n - 1]);

    cout << ans << endl;
    return 0;
}