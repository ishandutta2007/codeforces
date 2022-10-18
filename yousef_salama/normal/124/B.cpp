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
using namespace std;
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    string a[n], temp[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        temp[i] = a[i];
    }
    int per[k], ans = 1 << 30;
    for(int i = 0; i < k; i++)
        per[i] = i;
    do{
        int Max = 0, Min = 1 << 30;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < k; j++){
                temp[i][j] = a[i][per[j]];
            }
            int b = atoi(temp[i].c_str());
            Max = max(Max, b);
            Min = min(Min, b);
        }
        ans = min(ans, Max - Min);
    }while(next_permutation(per, per + k));
    cout << ans << endl;
    return 0;
}