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

int n, m;

string s[105];

bool vis[105];

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> s[i];
    } 
    memset(vis, 0, sizeof(vis));
    vector<int> a, b;
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            string tmp = s[j];
            reverse(tmp.begin(), tmp.end());
            if(s[i] == tmp){
                vis[i] = true;
                vis[j] = true;
                a.push_back(i);
                b.push_back(j);
            }
        } 
    }
    for(int i = 1;i <= n;i++){
        string tmp = s[i];
        reverse(tmp.begin(), tmp.end());
        if(s[i] == tmp){
            a.push_back(i);
            break;
        }
    }
    cout << m * (a.size() + b.size()) << endl;
    string ans = "";
    for(auto it : a){
        ans += s[it];
    }
    reverse(b.begin(), b.end());
    for(auto it : b){
        ans += s[it];
    }
    cout << ans << endl;
    return 0;
}