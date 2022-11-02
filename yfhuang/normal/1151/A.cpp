#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

int dis(char a, char b){
    int d1 = abs(b - a);
    int d2 = 26 - d1;
    return min(d1, d2);
}
const int maxn = 55;
char s[maxn];
char a[8] = "ACTG";

int main(){
    int n;
    cin >> n;
    scanf("%s", s + 1);
    int ans = 1e9;
    for(int i = 1;i + 3 <= n;i++){
        int tmp = 0;
        for(int j = 0;j < 4;j++){
            tmp += dis(s[i + j], a[j]);
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}