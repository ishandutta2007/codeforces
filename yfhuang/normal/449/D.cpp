#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

const int mod = 1e9 + 7;
const int maxn = (1 << 20) + 100;
int a[maxn];
int n;
int cnt[maxn];

int qpow(int a,int n){
    int ret = 1;
    for(;n;n >>= 1){
        if(n & 1) ret = 1LL * ret * a % mod;
        a = 1LL * a * a % mod;
    }
    return ret;
}

void upd(int &a,int b){
    a += b;
    if(a >= mod) a -= mod;
}

void display(){
    for(int j = 0;j < (1 << 4);j++){
        printf("%d\n",cnt[j]);
    }
}

void count(){
   // cout << "!" << endl;
    for(int i = 0;i < 20;i++){
        for(int j = (1 << 20) - 1;j >= 0;j--){
            if((j & (1 << i)) == 0){
                upd(cnt[j],cnt[j ^ (1 << i)]);
            }
        }
    }
  //  display();
    int ans = 0;
    for(int j = 0;j < (1 << 20);j++){
        int val = qpow(2,cnt[j]) - 1;
        if(val < 0) val += mod;
        if(__builtin_popcount(j) & 1){
            upd(ans,mod - val);
        }else{
            upd(ans,val);
        }
    }
    printf("%d\n",ans);
}

void solve(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    count();
}


int main(){

    solve();
    return 0;
}