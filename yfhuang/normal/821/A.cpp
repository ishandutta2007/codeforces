#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 55;

int a[maxn][maxn];
int n;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++)
        for(int j =1 ;j <= n;j++)
            scanf("%d",&a[i][j]);
    bool flag = true;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++){
            if(a[i][j] > 1){
                bool f = 0;
                for(int k = 1;k <= n;k++) if(k != i){
                    for(int l = 1;l <= n;l++) if(l != j){
                        if(a[k][j] + a[i][l] == a[i][j]) f = 1;
                    }
                }
                flag &= f;
            }
        }
    if(flag){
        cout << "Yes" << endl;
    }else cout << "No" << endl;
    return 0;
}

/*
 5 4 3
 1 2 1
 2 3 1
 3 4 1
 4 5 1
 1 2 3 4
 2 3 1 2
 3 4 3 4
*/