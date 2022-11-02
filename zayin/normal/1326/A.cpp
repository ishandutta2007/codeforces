#include<bits/stdc++.h>
using namespace std;
int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        if (n==1)
            puts("-1");
        else    {
            putchar('2');
            for (int i=1;i<n;++i)
                putchar('3');
            puts("");
        }
    }
    return 0;
}