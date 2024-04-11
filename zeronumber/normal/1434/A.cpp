#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int M=998244353;
const int maxn=1e6+12;
pi b[maxn];
int a[maxn],t[6],sum[maxn],n,m;
void add(int p){
    int x=b[p].S;
    if (!sum[x]) m++;
    sum[x]++;
}
void sub(int p){
    int x=b[p].S;
    sum[x]--;
    if (!sum[x]) m--;
}
int main(){
    for (int i=0;i<6;i++) cin >> t[i];
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++){
        for (int j=0;j<6;j++) b[i*6+j]=(pi){a[i]-t[j],i};
    }
    sort(b,b+n*6);
    int r=0;
    int ans=1e9+10;
    for (int i=0;i<n*6;i++){
        while (m<n&&r<n*6) add(r),r++;
        if (m<n) break;
        ans=min(ans,b[r-1].F-b[i].F);
        sub(i);
    }
    cout << ans << endl;
    return 0;
}