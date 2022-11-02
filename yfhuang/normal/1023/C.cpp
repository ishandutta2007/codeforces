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

int n, k;

const int maxn = 2e5 + 5;
char s[maxn];
char t[maxn];

int main(){
    cin >> n >> k;
    scanf("%s", s + 1);
    int left = 0, right = 0, tot = 0;
    for(int i = 1;i <= n;i++){
        if(s[i] == '('){
            left++;
            t[++tot] = s[i];
        }else{
            right++;
            t[++tot] = s[i];
        } 
        if(left * 2 == k){
            for(int j = tot + 1;j <= k;j++){
                t[j] = ')';
            }
            break;
        }
    }
    printf("%s\n", t + 1);
    return 0;
}