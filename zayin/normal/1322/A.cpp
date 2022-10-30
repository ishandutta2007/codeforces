#include<bits/stdc++.h>
#define maxn 1000050
using namespace std;

int n;
char s[maxn];
int a[maxn];

int cnt[2];

int main()  {
    scanf("%d%s",&n,s+1);
    for (int i=1;i<=n;++i)  {
        a[i]=(s[i]=='(')?1:-1;
        if (s[i]=='(')
            ++cnt[0];
        else
            ++cnt[1];
    }
    if (cnt[0]!=cnt[1])
        return puts("-1"),0;

    int ans=0,sum=0;
    for (int i=1;i<=n;)  {
        if (a[i]+sum>=0)
            sum+=a[i++];
        else    {
            int j=i;
            do  {
                assert(j<=n);
                sum+=a[j++];
                // cout<<"j:"<<j<<" "<<sum<<endl;
            } while (sum<0);
            ans+=j-i;
            // cout<<i<<" "<<j<<endl;
            i=j;
        }
    }
    printf("%d\n",ans);
    return 0;
}