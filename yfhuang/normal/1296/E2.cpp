#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

const int maxn = 2e5 + 5;
int n;
char s[maxn];

int main(){
    cin >> n;
    scanf("%s", s + 1);
    vector<pair<char, int> > colors = {{'a', 0}};
    vector<int> ans(n, -1);
    for(int i = 1;i <= n;i++){
        if(colors[0].first > s[i]){
            colors.insert(colors.begin(), {'a', colors.size()});
        }
        int id = 0;
        while(id + 1 < colors.size() and s[i] >= colors[id + 1].first){
            id++;
        }
        ans[i] = colors[id].second;
        colors[id].first = s[i];
    }
    cout << colors.size() << endl;
    for(int i = 1;i <= n;i++){
        printf("%d%c", ans[i] + 1, i == n ? '\n' : ' ');
    }
    return 0;
}