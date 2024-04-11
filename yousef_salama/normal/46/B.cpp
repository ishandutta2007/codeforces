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
    int cnt[5], N;
    for(int i = 0; i < 5; i++)
        scanf("%d", &cnt[i]);
    map <string, int> mp;
    string sizes[5] = {"S", "M", "L", "XL", "XXL"};
    for(int i = 0; i < 5; i++)
        mp[sizes[i]] = i;
    scanf("%d", &N);
    string a[N];
    for(int i = 0; i < N; i++)
        cin >> a[i];
    for(int i = 0; i < N; i++){
        int best = -1;
        for(int j = 4; j >= 0; j--)if(cnt[j])
            if(best == -1 || abs(j - mp[a[i]]) < abs(best - mp[a[i]]))
                best = j;
        cnt[best]--;
        cout << sizes[best] << endl;
    }
    return 0;
}