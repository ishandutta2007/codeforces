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
using namespace std;
int main(){
    int a, b, g, n;
    cin >> a >> b;
    g = __gcd(a,b);
    vector <int> div;
    for(int i = 1; i * i <= g; i++){
        if(g % i == 0){
            div.push_back(i);
            if(i * i != g)div.push_back(g / i);
        }
    }
    cin >> n;
    sort(div.begin(), div.end());
    while(n--){
        int f, t, ans = -1;
        cin >> f >> t;
        int lo = 0, hi = div.size() - 1, mid;;
        while(lo <= hi){
            mid = (lo + hi) / 2;
            if(div[mid] >= f && div[mid] <= t){
                lo = mid + 1;
                ans = max(ans, div[mid]);
            }
            else if(div[mid] < f)lo = mid + 1;
            else hi = mid - 1;
        }
        cout << ans << endl;
    }
    return 0;
}