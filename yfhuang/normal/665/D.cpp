#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n;

const int maxn = 1005;

int a[maxn];

bool is_prime[2000005];

void prime_table(){
    memset(is_prime,true,sizeof(is_prime));
    is_prime[1] = false;
    for(int i = 2;i < 2000005;i++) if(is_prime[i]){
        for(int j = i * 2;j < 2000005;j += i){
            is_prime[j] = false;
        }
    }
}

int main(){
    cin >> n;
    int m = 0;
    prime_table();
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] == 1) m++;
    }
    if(m >= 2){
        int ans = m;
        int x = 1;
        for(int i = 1;i <= n;i++) if(a[i] != 1 && is_prime[a[i] + 1]) {ans++; x = i;break;}
        if(ans == m){
            cout << m << endl;
            for(int i = 1;i <= m;i++) printf("%d%c",1,i == m ? '\n' :' ');
        }else{
            cout << ans << endl;
            for(int i = 1;i <= m;i++) cout << 1 << ' ' ;
            cout << a[x] << endl;
        }
    }else{
        bool flag = false;
        for(int i = 1;i <= n && !flag;i++){
            for(int j = i + 1;j <= n && !flag;j++){
                if(is_prime[a[i] + a[j]]){
                    cout << 2 << endl;
                    cout << a[i] << ' ' << a[j] << endl;
                    flag = true;
                }
            }
        }
        if(!flag){
            cout << 1 << endl;
            cout << a[1] << endl;
        }
    }
}