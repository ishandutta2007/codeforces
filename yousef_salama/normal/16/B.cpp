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
#include <bitset>
using namespace std;
int N, M;
int main(){
    scanf("%d %d", &N, &M);
    vector <pair <int, int> > a(M);
    for(int i = 0; i < M; i++)
        scanf("%d %d", &a[i].second, &a[i].first);
    sort(a.rbegin(), a.rend());
    int ans = 0, sel = 0;
    for(int i = 0; N > 0 && i < M; i++){
        ans += a[i].first * (min(a[i].second, N));
        N -= min(a[i].second, N);
    }
    cout << ans << endl;
    return 0;
}