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
int N, a, cnt[105];
int main(){
    memset(cnt, 0, sizeof cnt);
    int ans = 0;
    scanf("%d", &N);
    while(N--){
        scanf("%d", &a);
        cnt[a]++;
    }
    for(int i = 0; i < 105; i++)
        for(int j = i; j < 105; j++){
            if(i == j){
                ans += cnt[i] / 4;
                cnt[i] %= 4;
            }
            else{
                int cur = min(cnt[i], cnt[j]) / 2;
                ans += cur;
                cnt[i] -= cur * 2;
                cnt[j] -= cur * 2;
            }
        }
    cout << ans << endl;
    return 0;
}