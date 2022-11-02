#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()  {
    int q;
    scanf("%d",&q);
    while (q--) {
        LL u,v;
        scanf("%lld%lld",&u,&v);
        vector<int> posu,posv;
        for (int i=0;i<31;++i)  {
            if (u>>i&1) posu.push_back(i);
            if (v>>i&1) posv.push_back(i);
        }
        bool flag=(u<=v);
        if (posu.size()<posv.size())
            flag=0;
        else    {
            for (int i=0;i<posv.size();++i)
                flag&=posv[i]>=posu[i];
        }
        puts(flag?"YES":"NO");
    }
    return 0;
}