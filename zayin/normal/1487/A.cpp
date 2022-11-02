#include<bits/stdc++.h>
using namespace std;
int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,a,mna=1e8,cnt=0;
        scanf("%d",&n);
        for (int i=0;i<n;++i)   {
            scanf("%d",&a);
            if (mna==a)
                ++cnt;
            else
            if (mna>a)
                mna=a,cnt=1;
        }
        printf("%d\n",n-cnt);
    }
}