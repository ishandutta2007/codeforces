#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n;
const int maxn = 2e5 + 5;
int a[maxn];
int cnt[maxn];
int pre[maxn];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    sort(a + 1, a + 1 + n);
    pre[0] = 0;
    for(int i = 1;i <= 2e5;i++){
        pre[i] = pre[i - 1] + cnt[i];
    }
    int j = 1;
    int ans = 0, ansl = 0, ansr = 0;
    for(int i = 1;i <= 2e5;i++){
        if(cnt[i] == 0)
            continue;
        if(j < i)
            j = i;
        if(j == i){
            while(cnt[j + 1] > 1){
                j++;
            }
            if(cnt[j + 1] > 0){
                j++;
            }
        }else{
            if(cnt[j] == 1){

            }else{
                while(cnt[j + 1] > 1){
                    j++;
                }
                if(cnt[j + 1] > 0){
                    j++;
                }
            }
        }
        int num = pre[j] - pre[i - 1];
        if(num > ans){
            ans = num;
            ansl = i, ansr = j;
        }
    }
    //cout << ans << " " << ansl << " " << ansr << endl;
    cout << ans << endl;
    vector<int> ret;
    if(ansl == ansr){
        for(int i = 1;i <= cnt[ansl];i++){
            ret.push_back(ansl);
        }
    }else{
        for(int i = 1;i <= cnt[ansl];i++){
            ret.push_back(ansl);
        }
        for(int i = ansl + 1;i < ansr;i++){
            for(int j = 2;j <= cnt[i];j++){
                ret.push_back(i);
            }
        }
        for(int i = 1;i <= cnt[ansr];i++){
            ret.push_back(ansr);
        }
        for(int i = ansr - 1;i > ansl;i--){
            ret.push_back(i);
        }
    }
    for(int i = 0;i < ret.size();i++){
        printf("%d%c", ret[i], i == ret.size() - 1 ? '\n' : ' ');
    }
    return 0;
}