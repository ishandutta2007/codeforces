#include <bits/stdc++.h>
using namespace std;

int n, m;
const int maxn = 1e5 + 5;
int l[maxn];
int p[maxn];

int main(){
    cin >> n >> m;
    bool flag = true;
    long long sum = 0;
    for(int i = 1;i <= m;i++){
        scanf("%d", &l[i]);
        if(l[i] > n + 1 - i){
            flag = false;
        }
        sum += l[i];
    }
    if(sum < n)
        flag = false;
    if(flag){
        long long r = n + 1;
        for(int i = 1;i <= m;i++){
            sum -= l[i];
            p[i] = min(sum + 1, r - l[i]);
            r = p[i] + l[i] - 1;
            printf("%d%c", p[i], i == m ? '\n' : ' ');
        }
    }else{
        cout << -1 << endl;
    }
    return 0;
}