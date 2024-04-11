#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <queue>
using namespace std;

const int maxn = 100 + 5;

char s[maxn];
int pre[maxn],suf[maxn];

int main(){
    scanf("%s",s + 1);
    int n = strlen(s + 1);
    for(int i = 1;i <= n;i++){
        pre[i] = pre[i - 1] + (s[i] == 'Q');
    }
    for(int i = n;i >= 1;i--){
        suf[i] = suf[i + 1] + (s[i] == 'Q');
    }
    long long ans = 0;
    for(int i = 1;i <= n;i++){
        if(s[i] == 'A'){
            ans += 1LL * pre[i - 1] * suf[i + 1];
        }
    }
    cout << ans << endl;
    return 0;
}