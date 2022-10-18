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
#define FOR(i,n) for(int i =0;i<n;i++)
using namespace std;
int main()
{
    int y,w;
    cin >> y >> w;
    int ans =  6 - max(y,w) + 1;
    int d = 6;
    while(1){
        if(ans % 3 == 0 && d % 3 == 0){
            ans /= 3;
            d /= 3;
        }
        else if(ans % 2 == 0 && d % 2 == 0){
            ans /= 2;
            d /= 2;
        }
        else break;
    }
    cout << ans << '/' << d;
}