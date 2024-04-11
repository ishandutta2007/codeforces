#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int T;
const int maxn = 1e5 + 5;
char s[maxn * 2];

int main(){
    cin >> T;
    while(T--){
        int n;
        scanf("%d", &n);
        scanf("%s", s + 1);
        if(s[1] == s[2]){
            s[3] = 0;
            printf("%s\n", s + 1);
        }else{
            int j = 2;
            for(;j <= n;j++){
                if(s[j] > s[j-1]){
                    break;
                }
            }
            for(int i = 1;i < j;i++){
                s[j * 2 - 1 - i] = s[i];
            }
            s[j * 2 - 1] = 0;
            printf("%s\n",s + 1);
        }
    }
    return 0;
}