#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long 
using namespace std;
const int MAXN = (int)3e5+10;
#define INF 0x3f3f3f3f

ll A[MAXN];
ll dp[MAXN];
int n,k;
ll l,r;
bool check(int mid){
    for(int i = 1;i <= n;i++){dp[i] = 0;}
    dp[0] = 1;
    int pl = 1,pr;
    for(int i = 1;i <= n;i++){
        while(A[i] - A[pl] > mid) pl++;
        pr = i - k + 1;
        for(int j = pl;j <= pr;j++){
            if(dp[j - 1]){
                dp[i] = 1;
                break;
            }
            else pl++;// 
        }
    }
    //for(int i = 1;i <= n;i++) printf("%d ",dp[i]);
    //printf("\n");
    return dp[n];
}

int main()
{
    scanf("%d%d",&n,&k);  
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&A[i]);
        r = max(A[i],r);
    }
    for(int i = 1;i <= n;i++) dp[i] = INF;
    sort(A+1,A+1+n);
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)){r = mid - 1;}
        else{l = mid + 1;}
    }
    printf("%lld",l);
    return 0;
}