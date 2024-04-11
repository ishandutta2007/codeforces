#include<bits/stdc++.h>
using namespace std;

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,U,D,L,R;
        scanf("%d%d%d%d%d",&n,&U,&R,&D,&L);
        bool ans=0;
        for (int s=0;s<16;++s)  {
            int u=U,d=D,l=L,r=R;
            if (s&1) --u,--l;
            if (s&2) --u,--r;
            if (s&4) --d,--l;
            if (s&8) --d,--r;
            auto check=[&](int x)   {
                return 0<=x&&x<n-1;
            };
            bool flag=check(u)&&check(d)&&check(l)&&check(r);
            ans|=flag;
        }
        puts(ans?"YES":"NO");
    }
    return 0;
}