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
int main(){
//    freopen("a.in", "r", stdin);
    int n, m;
    cin >> n;
    long long a[n];
    long long ans = 0;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        ans += (i + 1) * (a[i] - 1);
    cout << ans + n << endl;
//    bool found = 0;
//    while(!found){
//        found = 1;
//        for(int i = 0; i < n; i++){
//            if(a[i] != 1){
//                ans++;
//                a[i]--;
//                found = 0;
//                break;
//            }
//            else ans++;
//        }
//    }
//    cout << ans << endl;
    return 0;
}