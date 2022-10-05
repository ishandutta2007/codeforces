#include <bits/stdc++.h>
using namespace std;

int T, n, l, r, a[202000], l1, l2, r1, r2;

int main(){
    for (cin>>T;T--;){
        cin>>n>>l>>r;
        for (int i=1;i<=n;++i) a[i]=0;
        for (int i=1;i<=n;++i){
            int t; scanf("%d",&t);
            if (i<=l) ++a[t];
            else --a[t];
        }
        l1=l2=r1=r2=0;
        for (int i=1;i<=n;++i)
            if (a[i]){
                if (a[i]>0){
                    l1+=a[i]%2; l2+=a[i];
                }else{
                    r1+=(-a[i])%2; r2+=-a[i];
                }
            }
        int ans=0;
        if (min(l2,r2)>=max(l1,r1)){
            ans=(l2+r2)/2;
        }else{
            ans=(l2+r2)/2+max(l1-r2,r1-l2)/2;
        }
        cout<<ans<<endl;
    }
}