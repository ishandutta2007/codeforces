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
    string s;
    int k;
    cin >> s >> k;
    int cnt[26];
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < s.size(); i++)
        cnt[s[i] - 'a']++;
    vector <pair<int, char> > v;
    for(int i = 0; i < 26; i++)
        if(cnt[i])v.push_back(make_pair(cnt[i], i));
    sort(v.begin(), v.end());
    int ans = v.size();
    bool vis[26];
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < v.size(); i++){
        if(k >= v[i].first){
            vis[v[i].second] = 1;
            k -= v[i].first;
            ans--;
        }
        else break;
    }
    cout << ans << endl;
    for(int i = 0; i < s.size(); i++)
        if(!vis[s[i] - 'a'])cout << s[i];
    cout << endl;
    return 0;
}