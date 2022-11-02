#include<bits/stdc++.h>
#define maxn 105
using namespace std;

int n,m,q,C;
int cnt[maxn];

int sum[maxn*maxn];
int tp[maxn*maxn];

char mp[maxn][maxn];

int id(int i,int j) {
    if (i&1)
        return (i-1)*m+j;
    else
        return (i-1)*m+m-j+1;
}

char chr(int i) {
    if (1<=i&&i<=26) return i-1+'a';
    i-=26;
    if (1<=i&&i<=26) return i-1+'A';
    i-=26;
    return i-1+'0';
}

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d%d",&n,&m,&q);
        C=0;
        for (int i=1;i<=n;++i)  {
            scanf("%s",mp[i]+1);
            for (int j=1;j<=m;++j)
                C+=mp[i][j]=='R';
        }
        for (int i=1;i<=q;++i)  {
            cnt[i]=C/q;
            if (i<=C%q)
                ++cnt[i];
        }

        for (int i=1;i<=q;++i)
            cnt[i]+=cnt[i-1];

        for (int i=1;i<=n;++i)
            if (i&1)
                for (int j=1;j<=m;++j)
                    sum[id(i,j)]=sum[id(i,j)-1]+(mp[i][j]=='R');
            else
                for (int j=m;j;--j)
                    sum[id(i,j)]=sum[id(i,j)-1]+(mp[i][j]=='R');
        
        for (int i=1,j=1;i<=q;++i)  {
            while (j<=n*m&&sum[j]<=cnt[i]) tp[j++]=i;
            // cout<<i<<" "<<cnt[i]<<" "<<j<<endl;
        }

        for (int i=1;i<=n;++i)  {
            for (int j=1;j<=m;++j)
                printf("%c",chr(tp[id(i,j)]));
            puts("");
        }
        // cout<<endl;
    }
    return 0;
}