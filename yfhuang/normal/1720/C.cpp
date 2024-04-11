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
int n, m;
const int maxn = 1005;
char s[maxn][maxn];

int main(){
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 1;i <= n;i++){
            scanf("%s", s[i] + 1);
        }
        int zero = 0, zero2 = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(s[i][j] == '0'){
                    zero++;
                }
                if(i + 1 <= n){
                    if(s[i][j] == '0' and s[i + 1][j] == '0')
                        zero2++;
                }
                if(j + 1 <= m){
                    if(s[i][j] == '0' and s[i][j + 1] == '0')
                        zero2++;
                }
                if(i + 1 <= n and j - 1 >= 1){
                    if(s[i][j] == '0' and s[i + 1][j - 1] == '0'){
                        zero2++;
                    }
                }
                if(i - 1 >= 1 and j - 1 >= 1){
                    if(s[i][j] == '0' and s[i - 1][j - 1] == '0'){
                        zero2++;
                    }
                }
            }
        }
        int one = n * m - zero;
        if(zero == 0){
            one--;
        }   
        if(zero2 == 0){
            one--;
        }
        cout << one << endl;
    }
    return 0;
}