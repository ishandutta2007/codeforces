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
int N, M, cnt[105];
string s[105];
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> s[i];
    for(int i = 0; i < M; i++){
        int Max = 0;
        vector <int> v;
        for(int j = 0; j < N; j++){
            if((s[j][i] - '0') > Max){
                v.clear();
                v.push_back(j);
                Max = s[j][i] - '0';
            }
            if((s[j][i] - '0') == Max)
                v.push_back(j);
        }
        for(int i = 0; i < v.size(); i++)
            cnt[v[i]]++;
    }
    int ans = 0;
    for(int i = 0; i < N; i++)
        ans += cnt[i] > 0;
    cout << ans << endl;
    return 0;
}