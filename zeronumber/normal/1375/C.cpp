#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=1e6+3;
const int M=1000000007;
int _,n,a[maxn],pre[maxn],suf[maxn];

int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        //pre[1]=a[1]; for (int i=2;i<=n;i++) pre[i]=min(pre[i-1],a[i]);
        //suf[n]=a[n]; for (int i=n-1;i;i--)  suf[i]=max(suf[i+1],a[i]);
        //bool flag=0;
        //for (int i=1;i<n;i++) flag|=pre[i]>suf[i+1];
        if (a[1]>a[n]) puts("NO"); else puts("YES");
    }
    return 0;
}