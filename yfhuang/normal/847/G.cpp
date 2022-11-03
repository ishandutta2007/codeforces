#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n;

char s[1005][9];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%s",s[i]);
    }
    int mx = 0;
    for(int i = 0;i < 7;i++){
        int num = 0;
        for(int j = 1;j <= n;j++){
            num += s[j][i] - '0';
        }
        mx = max(mx,num);
    }
    cout << mx << endl;
    return 0;
}