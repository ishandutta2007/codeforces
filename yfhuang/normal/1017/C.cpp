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

int n;

int main(){
    cin >> n;
    int k = 0, ans = n + 2;
    for(int i = 1;i <= n;i++){
        int tmp = i + (n + i - 1) / i;
        if(tmp < ans){
            ans = tmp;
            k = i;
        }
    }
    //cout << k << endl;
    int right = n;
    int cur = k;
    vector<int> a;
    for(int i = 1;i <= k;i++){
        int num = right / cur;
        for(int j = right - num + 1;j <= right;j++){
            a.push_back(j);
        }
        right -= num;
        cur--;
    }
    for(int i = 1;i <= n;i++){
        printf("%d%c", a[i - 1], i == n ? '\n' : ' ');
    }
    return 0;
}