#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n;
const int maxn = 2e5 + 5;
int a[maxn];
int cnt[5];
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    int now = 0;
    while(cnt[2] > 0 || cnt[1] > 0){
        if(now == 0){
            if(cnt[2] > 0){
                cnt[2]--;
                now += 2;
                printf("2 ");
            }else{
                cnt[1]--;
                now += 1;
                printf("1 ");
            }
        }else{
            if(now & 1){
                if(cnt[2] > 0){
                    cnt[2]--;
                    now += 2;
                    printf("2 ");
                }else{
                    cnt[1]--;
                    now += 1;
                    printf("1 ");
                }
            }else{
                if(cnt[1] > 0){
                    cnt[1]--;
                    now += 1;
                    printf("1 ");
                }else{
                    cnt[2]--;
                    now += 2;
                    printf("2 ");
                }
            }
        }
    }
    return 0;
}