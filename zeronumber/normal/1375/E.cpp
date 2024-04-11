#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=1e3+3;
const int M=1000000007;
int n,a[maxn],b[maxn];
vector <pi> ans;
bool cmp(pi u,pi v){
    if (u.F!=v.F) return u.F<v.F;
    return b[u.S]>b[v.S];
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++){
        b[i]=1;
        for (int j=1;j<=n;j++) if (a[j]<a[i]||(a[j]==a[i]&&j<i)) ++b[i];
    }
    for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++)
            if (b[i]>b[j]) ans.pb((pi){i,j});
    sort(ans.begin(),ans.end(),cmp);
    printf("%d\n",(int)ans.size());
    for (auto x:ans) printf("%d %d\n",x.F,x.S);
    return 0;
}