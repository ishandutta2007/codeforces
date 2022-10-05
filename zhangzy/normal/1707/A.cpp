#include<bits/stdc++.h>
using namespace std;

int n, q, a[101000], T, ans[101000];

int main(){
    for (cin>>T;T--;){
        cin>>n>>q;
        for (int i=1;i<=n;++i) cin>>a[i];
        int now=0;
        for (int i=n;i>=1;--i){
            if (a[i]>now){
                if (now<q){
                    ans[i]=1; ++now;
                }else{
                    ans[i]=0;
                }
            }else{
                ans[i]=1;
            }
        }
        // cout<<ans<<endl;
        for (int i=1;i<=n;++i) printf("%d",ans[i]);
        puts("");
    }
}