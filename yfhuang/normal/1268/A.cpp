#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 200005;
int n, k;
int a[maxn];
char s[maxn];
int flag[maxn];
int b[maxn];
int main(){
    cin >> n >> k;
    scanf("%s", s + 1);
    for(int i = 1;i <= n;i++){
        a[i] = s[i] - '0';
    }
    for(int i = 1;i <= n;i++){
        b[i] = a[(i - 1) % k + 1];
    }
    bool flag = true;
    for(int i = 1;i <= n;i++){
        if(b[i] > a[i])
            break;
        if(b[i] < a[i]){
            flag = false;
            break;
        }
    }
    if(flag){
        cout << n << endl;
        for(int i = 1;i <= n;i++){
            putchar('0' + a[(i - 1) % k + 1]);
        }
        puts("");
    }else{
        cout << n << endl;
        for(int i = k;i >= 1;i--){
            if(a[i] != 9){
                a[i] = a[i] + 1;
                for(int j = i + 1;j <= k;j++){
                    a[j] = 0;
                }
                break;
            }
        }
        for(int i = 1;i <= n;i++){
            putchar('0' + a[(i - 1) % k + 1]);
        }
        puts("");
    }
    return 0;
}