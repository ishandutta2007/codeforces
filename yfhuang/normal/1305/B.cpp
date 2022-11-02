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

const int maxn = 1005;

char s[maxn];
int n;

int main(){
    scanf("%s", s + 1);
    n = strlen(s + 1);
    vector<int> open, close;
    for(int i = 1;i <= n;i++){
        if(s[i] == '(')
            open.push_back(i);
        else
            close.push_back(i);
    }
    reverse(close.begin(), close.end());
    vector<int> ans;
    for(int i = 0;i < min(open.size(), close.size());i++){
        if(open[i] < close[i]){
            ans.push_back(open[i]);
            ans.push_back(close[i]);
        }else{
            break;
        }
    }
    sort(ans.begin(), ans.end());
    if(ans.size() > 0){
        cout << 1 << endl;
        cout << ans.size() << endl;
        for(int i = 0;i < ans.size();i++){
            printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
        }
    }else{
        cout << 0 << endl;
    }
    return 0;
}