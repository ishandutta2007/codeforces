#include<bits/stdc++.h>
using namespace std;

const int N=505;

int T,n,k,a[N];

char s[N];

string f[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        scanf("%s",s+1);
        for(int i=1;i<=n;i++)
            s[i]-='a';
        for(int i=1;i<=n;i++)
            f[i]=f[i-1]+s[i];
        for(int i=0;i<n;i++)
        {
            int bn=min((int)s[i+1],min((s[i+1]+1)%k,(s[i+1]-1+k)%k));
            int cn=min((int)s[i+2],min((s[i+2]+1)%k,(s[i+2]-1+k)%k));
            f[i+1]=min(f[i+1],f[i]+(char)bn);
            f[i+2]=min(f[i+2],f[i]+(char)cn+s[i+1]);
            f[i+1]=min(f[i+1],f[i].substr(0,i-1)+s[i+1]+f[i].back());
            if(i>=1)
                f[i+2]=min(f[i+2],f[i].substr(0,i-1)+s[i+2]+f[i].back()+s[i+1]);
        }
        for(auto x:f[n])
            putchar(x+'a');
        puts("");
    }
}