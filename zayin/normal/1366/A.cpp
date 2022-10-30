#include<bits/stdc++.h>
using namespace std;

int main()  {
    int T;
    cin>>T;
    while (T--) {
        int a,b;
        cin>>a>>b;

        int l=0,r=min(a/2,b);
        auto calc=[&](int x)    {
            return x+min(a-2*x,(b-x)/2);
        };
        while (r-l>5) {
            int m1=(2*l+r)/3,m2=(l+2*r)/3;
            if (calc(m1)<calc(m2))
                l=m1;
            else
                r=m2;
        }

        int ans=0;
        for (int i=l;i<=r;++i)
            ans=max(ans,calc(i));
        cout<<ans<<endl;
    }
    return 0;
}