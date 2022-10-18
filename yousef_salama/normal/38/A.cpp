#include <iostream>
#include <fstream>
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
#define FOR(i,n) for(int i =0;i<n;i++)
using namespace std;
int main()
{
    int n;
    cin >> n;
    int r[n-1];
    for (int i = 0; i < n-1; i++) {
        int x;
        cin >> x;
        r[i] = x;
    }
    int a,b,ans = 0;
    cin >> a >> b;
    for(int i = a-1;i<b-1;i++){
        ans += r[i];
    }
    cout << ans << endl;
}