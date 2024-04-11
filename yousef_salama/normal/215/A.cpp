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
int n, m, a[55], b[55];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for(int j = 0; j < m; j++)
        cin >> b[j];
    int ans = 0, cnt = 0;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        if(b[j] % a[i] == 0){
            if((b[j] / a[i]) > ans){
                ans = b[j] / a[i];
                cnt = 1;
            }else if((b[j] / a[i]) == ans)cnt++;
        }
    cout << cnt << endl;
    return 0;
}