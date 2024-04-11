#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 2e5 + 5;
char s[maxn];
int main(){
    int n, k;
    cin >> n >> k;
    scanf("%s",s + 1);
    int ans = 0;
    for(int ch = 0;ch < 26;ch++){
        int tmp = 0;
        for(int i = 1, j = 1;i <= n;i = j + 1, j = i){
            if(s[i] == 'a' + ch){
                while(j < n && (s[j + 1] == s[j]))
                    j++;
                tmp += (j - i + 1) / k;
            }else{
                j = i - 1;
            }
            while(j < n && s[j + 1] != 'a' + ch){
                j++;
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}