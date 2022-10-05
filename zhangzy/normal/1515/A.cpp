#include <bits/stdc++.h>
using namespace std;

int T, n, x, a[111], s[111];

int main(){
    for (cin>>T;T--;){
        cin>>n>>x;
        for (int i=1;i<=n;++i) scanf("%d",&a[i]), s[i]=s[i-1]+a[i];
        if (s[0]==x||s[n]==x){
            puts("NO"); continue;
        }
        puts("YES");
        int p=-1;
        for (int i=1;i<=n;++i)
            if (s[i]==x) p=i;
        if (p!=-1){
            swap(a[p],a[p+1]);
        }
        for (int i=1;i<=n;++i) printf("%d ",a[i]); puts("");
    }
}