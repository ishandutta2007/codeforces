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
    int x,y,z,k;
    cin >> x >> y >> z >> k;
    int r[3];
    r[0] = x;
    r[1] = y;
    r[2] = z;
    int a[3] = {1,1,1};
    while(k){
        int min = INT_MAX;
        int index = -1;
        for(int i =0;i<3;i++){
            if(r[i] == a[i])continue;
            if(a[i] < min){
                min = a[i];
                index = i;
            }
        }
        if (index == -1)break;
        k--; 
        a[index]++;
    }
    cout << ((long long)a[0] * a[1] * a[2]) << endl;
    return 0;
}