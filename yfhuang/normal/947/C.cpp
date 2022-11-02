#include <bits/stdc++.h>
using namespace std;

int n;

int digit[40];

const int maxn = 300000 * 30;
int ch[maxn][2];
int val[maxn];
int tot;

void insert(int num){
    for(int i = 0;i < 30;i++){
        digit[i] = (num >> i) & 1;
    }
    int cur = 0;
    for(int i = 29;i >= 0;i--){
        int chr = digit[i];
        if(ch[cur][chr] == -1){
            ch[cur][chr] = ++tot;
            memset(ch[tot], -1, sizeof(ch[tot]));
            val[tot] = 0;
        }
        cur = ch[cur][chr];
        val[cur]++;
    }
}

int search(int num){
    for(int i = 0;i < 30;i++){
        digit[i] = (num >> i) & 1;
    }
    int cur = 0;
    int res = 0;
    for(int i = 29;i >= 0;i--){
        int chr = digit[i];
        if(ch[cur][chr] != -1 and val[ch[cur][chr]] != 0){
            cur = ch[cur][chr];
            res = res * 2 + chr;
        }else{
            cur = ch[cur][chr ^ 1];
            res = res * 2 + (chr ^ 1);
        }
        val[cur]--;
    }
    return res;
}
const int maxm = 3e5 + 5;
int a[maxm], p[maxm];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    } 
    memset(ch[0], -1, sizeof(ch[0]));
    val[0] = 0;
    tot = 0;
    for(int i = 1;i <= n;i++){
        cin >> p[i];
        insert(p[i]);
    }
    for(int i = 1;i <= n;i++){
        int res = search(a[i]);
        cout << (res ^ a[i]) << " ";
    }
    return 0;
}