#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int num[30];
char s[205];
int main(){
   int n;
    cin >> n;
    scanf("%s",s);
    int cnt = 0;
    int ans = 0;
    for(int i = 0;i < n;i++){
        if('A' <= s[i] && s[i] <= 'Z'){
            memset(num,0,sizeof(num));
            cnt = 0;
        }else{
            int x = s[i] - 'a';
            if(num[x] == 0) cnt++;
            num[x]++;
            ans = max(ans,cnt);
        }
    }
    cout << ans << endl;
    return 0;
}