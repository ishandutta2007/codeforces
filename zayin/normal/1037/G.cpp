#include<bits/stdc++.h>
#define maxc 26
#define maxn 100050
using namespace std;

int n,m;
char s[maxn];

int pre[maxn][maxc],nxt[maxn][maxc];
int l[maxc][maxn],sl[maxc][maxn];
int r[maxc][maxn],sr[maxc][maxn];

bool ex[maxc+5];
int lst[maxc],pos[maxc];

bool cmp(int i,int j)   {
    return lst[i]>lst[j];
}

void calc(const char *s,int n,int dp[maxc][maxn],int sum[maxc][maxn])
{
    // printf("%s\n",s+1);
    for (int c=0;c<maxc;++c)    pos[c]=c;
    memset(lst,0,sizeof(lst));

    for (int i=n;~i;--i)
    {
        memcpy(nxt[i],nxt[i+1],sizeof(nxt[i]));
        if (i)
            nxt[i][s[i]-'a']=i;
    }
    for (int i=1;i<=n;++i)
    {
        lst[s[i]-'a']=i;
        memcpy(pre[i],lst,sizeof(lst));
        sort(pos,pos+maxc,cmp);

        // for (int c=0;c<maxc;++c)
        for (int o=0;o<maxc;++o)
        {
            int c=pos[o],j=lst[c];
            if (j==i) continue;
            // cout<<i<<" "<<c<<":"<<endl;
            memset(ex,0,sizeof(ex));
            for (int ch=0;ch<maxc;++ch)
            {
                if (lst[ch]<=j)  continue;
                int k=lst[ch]-1,p=nxt[j][ch]-1;
                // cout<<ch<<" "<<p<<" "<<dp[c][p]<<" "<<(sum[ch][k]^sum[ch][p])<<" "<<dp[ch][i]<<endl;
                //assert(p>=0&&(dp[c][p]^sum[ch][p]^sum[ch][k]^dp[ch][i])<=maxc);
                ex[dp[c][p]^sum[ch][p]^sum[ch][k]^dp[ch][i]]=1;
            }
            while (ex[dp[c][i]]) ++dp[c][i];
        }
        for (int c=0;c<maxc;++c)
            if (lst[c])
                sum[c][i]=dp[c][i]^sum[c][lst[c]-1];
            else
                sum[c][i]=dp[c][i];

        // for (int c=0;c<maxc;++c) printf("dp[%d][%d]=%d %d\n",i,c,dp[c][i],sum[c][i]);
    }
    // cout<<"-----------"<<endl;
}

int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);


    reverse(s+1,s+n+1);
    calc(s,n,r,sr);
    for (int c=0;c<maxc;++c)
        reverse(r[c]+1,r[c]+n+1),reverse(sr[c]+1,sr[c]+n+1);
    reverse(s+1,s+n+1);
    calc(s,n,l,sl);

    scanf("%d",&m);
    while (m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        bool flag=0;
        for (int c=0;c<maxc;++c)
        {
            if (pre[b][c]<a||nxt[a][c]>b)    continue;
            int i=nxt[a][c]-1,j=pre[b][c]-1;
            // cout<<c<<" "<<i<<" "<<j<<" "<<(r[c][a])<<" "<<(sl[c][i]^sl[c][j])<<" "<<(l[c][b])<<endl;
            int sg=r[c][a]^sl[c][i]^sl[c][j]^l[c][b];
            if (!sg)
                flag=1;
        }
        puts(flag?"Alice":"Bob");
    }

    return 0;
}