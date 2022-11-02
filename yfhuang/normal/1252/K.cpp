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

const int maxn = 1e5 + 5;

int a[maxn];
int pre[maxn], suf[maxn];
int n;

int main(){
    cin >> n;
    pre[0] = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        pre[i] = pre[i - 1] | (a[i]);
    }
    suf[n + 1] = 0;
    for(int i = n;i >= 1;i--){
        suf[i] = suf[i + 1] | (a[i]);
    }
    int val = -1;
    int ansid = 0;
    for(int i = 1;i <= n;i++){
        int tmp = pre[i - 1] | suf[i + 1];
        int tmp1 = a[i] - (tmp & a[i]);
        if(tmp1 > val){
            val = tmp1;
            ansid = i;
        }
    }
    vector<int> ans;
    ans.push_back(a[ansid]);
    for(int i = 1;i <= n;i++){
        if(i != ansid){
            ans.push_back(a[i]);
        }
    }
    for(int i = 0;i < ans.size();i++){
        printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
    }
    return 0;
}