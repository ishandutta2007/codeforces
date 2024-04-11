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
#define FOR(i,n) for(int i =0;i<n;i++)
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        a[i] = x;
    }
    long long cnt = 1;
    long long ans = 0;
    for(int i =0;i<n;i++){
        if(i < n-1 && a[i] == a[i+1])cnt++;
        else{
            ans += (cnt*(cnt+1))/2;
            cnt = 1;
        }
    }
    cout << ans << endl;
}