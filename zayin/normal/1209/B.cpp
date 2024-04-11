#include<bits/stdc++.h>
#define maxn 105
using namespace std;

int n,a[maxn],b[maxn];
char s[maxn];

int main()  {
    scanf("%d%s",&n,s);
    for (int i=0;i<n;++i)
        scanf("%d%d",a+i,b+i);
    int ans=0;
    for (int t=0;t<5e4;++t) {
        int cnt=0;
        for (int i=0;i<n;++i)
            cnt+=(s[i]=='1');
        if (ans<cnt)    {
            ans=cnt;
            // cout<<t<<" "<<cnt<<endl;
        }
        for (int i=0;i<n;++i)   {
            if (t<b[i]) continue;
            if ((t-b[i])%a[i])  continue;
            s[i]^=1;
        }
        // for (int i=0;i<n;++i)   cout<<s[i]; cout<<endl;
        // cout<<t<<" "<<cnt<<endl;
    }
    printf("%d\n",ans);
    return 0;
}