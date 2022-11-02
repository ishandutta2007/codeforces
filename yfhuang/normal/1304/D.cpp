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

int t;
int n;
const int maxn = 2e5 + 5;
char s[maxn];

int a[maxn], b[maxn];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        scanf("%s", s + 1);
        int cur = n;
        for(int i = 1, j = 1;i <= n;i = j + 1, j = i){
            while(j < n and s[j] == '<')
                j++;
            for(int k = j;k >= i;k--){
                a[k] = cur--;
            } 
        }
        cur = 1;
        for(int i = 1, j = 1;i <= n;i = j + 1, j = i){
            while(j < n and s[j] == '>')
                j++;
            for(int k = j;k >= i;k--){
                b[k] = cur++;
            } 
        }
        for(int i = 1;i <= n;i++){
            printf("%d%c", a[i], i == n ? '\n' : ' ');
        }
        for(int i = 1;i <= n;i++){
            printf("%d%c", b[i], i == n ? '\n' : ' ');
        }
    }
    return 0;
}