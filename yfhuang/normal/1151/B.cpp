#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int n, m;
const int maxn = 505;

int a[maxn][maxn];
bool dif[maxn];

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            scanf("%d", &a[i][j]);
        }
    }
    bool all = true;
    for(int i = 1;i <= n;i++){
        dif[i] = true;
        for(int j = 2;j <= m;j++){
            if(a[i][j] != a[i][j - 1]){
                dif[i] = false;
            }
        }
        all &= dif[i];
    }
    if(all){
        int ret = 0;
        for(int i = 1;i <= n;i++){
            ret = ret ^ a[i][1];
        }
        if(ret == 0){
            cout << "NIE" << endl;
        }else{
            cout << "TAK" << endl;
            for(int i = 1;i <= n;i++){
                printf("%d%c", 1, i == n ? '\n' : ' ');
            }
        }
    }else{
        cout << "TAK" << endl;
        int pos = 0;
        for(int i = 1;i <= n;i++){
            if(dif[i] == false)
                pos = i;
        }
        int pre = 0, suf = 0;
        for(int i = 1;i < pos;i++){
            pre = pre ^ a[i][1];
        }
        for(int i = pos + 1;i <= n;i++){
            suf = suf ^ a[i][1];
        }
        int id = 0;
        for(id = 1;id <= m;id++){
            if(((pre ^ a[pos][id]) ^ suf) > 0)
                break;
        }
        bool first = true;
        for(int i = 1;i < pos;i++){
            if(first){
                first = false;
            }else{
                putchar(' ');
            }
            printf("%d", 1);
        }
        if(first){
            first = false;
        }else{
            putchar(' ');
        }
        printf("%d", id);
        for(int i = pos + 1;i <= n;i++){
            if(first){
                first = false;
            }else{
                putchar(' ');
            }
            printf("%d", 1);
        }
        puts("");
    } 
    return 0;
}