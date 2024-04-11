#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
const int maxn = 2e5 + 5;

int p[maxn];
int inv[maxn];
int l[maxn], r[maxn];
int st[maxn], tot;

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &p[i]);
        inv[p[i]] = i;
    }
    tot = 0;
    for(int i = 1;i <= n;i++){
        while(tot > 0 && p[st[tot]] <= p[i])
            tot--;
        if(tot == 0)
            l[i] = 1;
        else
            l[i] = st[tot] + 1;
        st[++tot] = i;
    }
    tot = 0;
    for(int i = n;i >= 1;i--){
        while(tot > 0 && p[st[tot]] <= p[i])
            tot--;
        if(tot == 0)
            r[i] = n;
        else
            r[i] = st[tot] - 1;
        st[++tot] = i;
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        if(i - l[i] < r[i] - i){
            for(int j = l[i];j < i;j++){
                int val = p[i] - p[j];
                if(inv[val] > i && inv[val] <= r[i]){
                    ans++;
                }
            }
        }else{
            for(int j = i + 1;j <= r[i];j++){
                int val = p[i] - p[j];
                if(inv[val] >= l[i] && inv[val] < i){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}