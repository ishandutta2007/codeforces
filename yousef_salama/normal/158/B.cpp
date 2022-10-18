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
int n, s, cnt[5];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        cnt[s]++;
    }
    cout << cnt[4] + cnt[3] + (cnt[2] + 1) / 2 +
            (max(cnt[1] - cnt[3] - (cnt[2] % 2 == 0?0:2), 0) + 3) / 4 << endl;
    return 0;
}