#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10;

int T , n , d , p[N] , dep[N] , tree[N][N] , cnt[N] , sum , Max;

int main(){
    scanf("%d" , &T); while(T--){
        memset(p , 0 , sizeof(p));
        memset(cnt , 0 , sizeof(cnt));
        dep[1] = sum = Max = 0;
        scanf("%d %d" , &n , &d);
        tree[0][++cnt[0]] = 1;
        for(int i = 1; i <= n; i++){
            int LS = i << 1 , RS = i << 1 | 1;
            if(LS <= n) dep[LS] = dep[i] + 1 , tree[dep[LS]][++cnt[dep[LS]]] = LS , sum += dep[LS] , Max = max(Max , dep[LS]);
            if(RS <= n) dep[RS] = dep[i] + 1 , tree[dep[RS]][++cnt[dep[RS]]] = RS , sum += dep[RS] , Max = max(Max , dep[RS]);
        }
        if(sum > d || d > n * (n - 1) / 2){ puts("NO"); continue; }
        while(sum < d){
            for(int i = Max; i >= 0; i--){
                if(cnt[i] >= 2 && cnt[i + 1] < (cnt[i] - 1) * 2){
                    tree[i + 1][++cnt[i + 1]] = tree[i][cnt[i]] , cnt[i]-- , sum++;
                    Max = max(Max , i + 1); break;
                }
            }
        }
        for(int k = 0; k < Max; k++)
            for(int i = 1; i <= cnt[k]; i++){
                int LS = 2 * (i - 1) + 1 , RS = 2 * (i - 1) + 2;
                if(LS <= cnt[k + 1]) p[tree[k + 1][LS]] = tree[k][i];
                if(RS <= cnt[k + 1]) p[tree[k + 1][RS]] = tree[k][i];
            }
        puts("YES");
        for(int i = 2; i <= n; i++) printf("%d " , p[i]);
        puts("");
    }
    return 0;
}