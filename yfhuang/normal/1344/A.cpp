#include <bits/stdc++.h>
using namespace std;

int t;
int n;

const int maxn = 2e5 + 5;
int a[maxn];
int cnt[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        for(int i = 0;i < n;i++){
            cnt[i] = 0;
        }
        for(int i = 1;i <= n;i++){
            int v = a[i] % n;
            v = (v + n) % n;
            v = (v + i) % n;
            cnt[v]++;
        }
        bool flag = true;
        for(int i = 0;i < n;i++){
            if(cnt[i] > 1){
                flag = false;
            } 
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}