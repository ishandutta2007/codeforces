#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 105;
const int maxm = 10 * 8 * 6 * 4 * 2;

int a[maxn][maxm];
char s[maxn];

int st[maxn], fe[maxn];

int main(){
    int n;
    while(cin >> n){
        scanf("%s", s + 1);
        for(int i = 1;i <= n;i++){
            scanf("%d%d", &st[i], &fe[i]);
        } 
        for(int i = 1;i <= n;i++){
            int init = s[i] == '1';
            for(int j = 1;j <= fe[i];j++){
                a[i][j] = init;
            }
            for(int j = 1;st[i] * j + fe[i] < maxm;j++){
                init ^= 1;
                for(int k = 1;k <= st[i];k++){
                    a[i][(j - 1) * st[i] + fe[i] + k] = init;
                } 
            }
        }
        int ans = 0;
        for(int j = 1;j < maxm;j++){
            int tmp = 0;
            for(int i = 1;i <= n;i++){
                if(a[i][j] == 1)
                    tmp++;
            }
            ans = max(ans, tmp);
        }
/*        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= 70;j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        } */
        cout << ans << endl;
    }
    return 0;
}