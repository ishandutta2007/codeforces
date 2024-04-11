#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    vector <bool> a(1 << k, false);
    for(int i = 0; i < n; i++){
        int ai;
        scanf("%d", &ai);
        a[ai] = true;
    }

    vector <int> f(1 << k), mn(1 << k), mx(1 << k);
    for(int i = 0; i < (1 << k); i++){
        if(a[i]){
            f[i] = 1 << 25;
            mn[i] = i;
            mx[i] = i;
        }else{
            f[i] = 1 << 25;
            mn[i] = -1;
            mx[i] = -1;
        }
    }

    for(int j = 0; j < k; j++){
        for(int i = 0; i < (1 << k); i += 1 << (j + 1)){
            for(int l = 0; l < (1 << j); l++){
                int f0 = f[i + l];
                int mn0 = mn[i + l];
                int mx0 = mx[i + l];

                int f1 = f[i + l + (1 << j)];
                int mn1 = mn[i + l + (1 << j)];
                int mx1 = mx[i + l + (1 << j)];

                f[i + l] = min(f0, f1);
                if(mx0 != -1 && mn1 != -1)f[i + l] = min(f[i + l], mn1 - mx0);
                mn[i + l] = mn0 != -1 ? mn0 : mn1;
                mx[i + l] = mx1 != -1 ? mx1 : mx0;

                f[i + l + (1 << j)] = min(f0, f1);
                if(mx1 != -1 && mn0 != -1)f[i + l + (1 << j)] = min(f[i + l + (1 << j)], (mn0 ^ (1 << j)) - (mx1 ^ (1 << j)));
                mn[i + l + (1 << j)] = mn1 != -1 ? mn1 ^ (1 << j) : (mn0 != -1 ? mn0 ^ (1 << j) : -1);
                mx[i + l + (1 << j)] = mx0 != -1 ? mx0 ^ (1 << j) : (mx1 != -1 ? mx1 ^ (1 << j) : -1);
            }
        }
    }

    for(int i = 0; i < (1 << k); i++){
        if(i > 0)printf(" ");
        printf("%d", f[i]);
    }
    printf("\n");

    return 0;
}