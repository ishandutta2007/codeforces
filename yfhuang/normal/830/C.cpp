#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 105;
int n;
typedef long long LL;
LL k;
int a[maxn];
vector<int> A;
int main(){
    cin >> n >> k;
    long long sum = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d",a + i);
        sum += a[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 2000;j++){
            A.push_back((a[i] + j - 1) / j);
        }
    }
    sort(A.begin(),A.end());
    int tot = unique(A.begin(), A.end()) - A.begin();
    A.resize(tot);
    long long ans = 0;
    for(int i = tot - 1;i >= 0;i--){
        long long nxt;
        if(i == tot - 1) nxt = 1e15;
        else nxt = A[i + 1];
        long long K = 0;
        
        for(int j = 1;j <= n;j++){
            K += (a[j] + A[i] - 1) / A[i];
        }
        long long ret = (k + sum) / K;
        if(ret >= A[i]) ans = max(ans,min(ret,nxt));
    }
    //cout << A[0] << endl;
    for(int i = A[0] - 1;i > 0;i--){
        
        long long ret = 0;
        for(int j = 1;j <= n;j++){
            ret += 1LL * i * ((a[j] + i - 1) / i) - a[j];
        }
        
        if(ret <= k) ans = max(ans,1LL * i);
    }
    cout << ans << endl;
    return 0;
}