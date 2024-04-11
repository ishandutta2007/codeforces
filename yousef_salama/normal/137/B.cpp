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
int N, ans = 0;
int a, cnt[5005];
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a;
        cnt[a]++;
    }
    for(int i = 1; i <= N; i++)
        ans += cnt[i] == 0;
    cout << ans << endl;
    return 0;
}