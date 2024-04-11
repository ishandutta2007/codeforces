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
int Max = 0;
pair <int, int> a[100005];
bool cmp(pair <int, int> a, pair <int, int> b){
    if(a.first != b.first)return a.first < b.first;
    else return a.second < b.second;
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a + N, cmp);
    Max = a[0].second;
    for(int i = 1; i < N; i++){
        if(a[i - 1].first < a[i].first && a[i].second < Max)
            ans++;
        Max = max(Max, a[i].second);
    }
    cout << ans << endl;
    return 0;
}