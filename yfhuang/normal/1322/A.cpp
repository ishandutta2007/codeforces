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
const int maxn = 1e6 + 5;

char s[maxn];

int main(){
    cin >> n;
    scanf("%s", s + 1);
    int m = 0;
    for(int i = 1;i <= n;i++){
        if(s[i] == '('){
            m++;
        }
    }
    if(m * 2 != n){
        cout << -1 << endl;
        return 0;
    }
    bool flag = true;
    int ans = 0, len = 0;
    int sum = 0;
    for(int i = 1;i <= n;i++){
        if(s[i] == '('){
            sum++;
        }else{
            sum--;
        }
        if(sum == 0){
            if(!flag){
                len++;
                ans += len; 
                len = 0;
            }
            flag = true;
        }
        if(sum < 0){
            flag = false;
            len++;
        }
    }
    cout << ans << endl;
    return 0;
}