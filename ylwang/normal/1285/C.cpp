# include <bits/stdc++.h>
# define int long long
# define rr register
using namespace std;
int X;
int ans=1e17;
int ansb;
signed main(void){
    cin>>X;
    for(rr int i=1;i*i<=X;++i){
        if(X%i)
            continue;
        int a=i,b=X/i;
        if(a*b/std::__gcd(a,b)==X){
            ans=std::min(ans,b);
            if(ans==b)
                ansb=a;
        }
    }
    cout<<ansb<<" "<<ans;
    return 0;
}