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
using namespace std;
map <string, int> mp;
bool cmp(string a, string b){
    return (mp[a] > mp[b]);
}
int main(){
    int n, m;
    cin >> n >> m;
    vector <int> c(n);
    vector <string> f;
    for(int i = 0; i < n; i++)cin >> c[i];
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        if(!mp.count(s))
            f.push_back(s);
        mp[s]++;
    }
    sort(c.begin(), c.end());
    sort(f.begin(), f.end(), cmp);
    int best = 0, worst = 0, p = m, i = 0;
    while(p > 0){
        int res = min(mp[f[i]], p);
        best += c[i] * res;
        p -= res;
        i++;
    }
    sort(f.rbegin(), f.rend(), cmp);
    p = m, i = c.size() - 1;
    int j = f.size() - 1;
    while(p > 0){
        int res = min(mp[f[j]], p);
        worst += c[i] * res;
        p -= res;
        i--;
        j--;
    }
    cout << best << ' ' << worst << endl;
    return 0;
}