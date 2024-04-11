#include<bits/stdc++.h>
#define maxn 300050
using namespace std;

const char *DNA="ACGT";

int n,m;

char s[maxn],t[maxn];
char as[maxn],at[maxn];

char tmp[maxn];

int dp[maxn][2][4];

int chr(char c)
{
    for (int i=0;i<4;++i)
        if (DNA[i]==c)
            return i;
    exit(1);
}

int calc(char s[maxn],int n,int m,char str[maxn])
{
    // cout<<"calc:"<<n<<" "<<m<<endl;
    // printf("%s\n",s);
    int ans=0;
    memset(dp,0,sizeof(dp));
    for (int i=0;i<n;++i)
    {
        char *p=s+i*m;
        for (int j=0;j<m;++j)
            ++dp[i][j&1][chr(p[j])];
    }

    // for (int i=0;i<n;++i)
    //     for (int c=0;c<=1;++c)
    //         for (int j=0;j<4;++j)
    //             cout<<"dp: "<<i<<" "<<c<<" "<<j<<" "<<dp[i][c][j]<<endl;

    for (int a=0;a<4;++a)
        for (int b=0;b<4;++b)
        {
            if (a==b)   continue;
            int s[2]={a,b},t[2]={-1,-1},sum=0;
            for (int i=0;i<4;++i)
            {
                if (a==i||b==i) continue;
                if (~*t)
                    t[1]=i;
                else
                    t[0]=i;
            }

            for (int i=0;i<n;++i)
                if (i&1)
                {
                    if (dp[i][0][t[0]]+dp[i][1][t[1]]<dp[i][0][t[1]]+dp[i][1][t[0]])
                        swap(t[0],t[1]);
                    sum+=dp[i][0][t[0]]+dp[i][1][t[1]];
                    for (int j=0;j<m;++j)
                        tmp[i*m+j]=DNA[t[j&1]];
                } else
                {
                    if (dp[i][0][s[0]]+dp[i][1][s[1]]<dp[i][0][s[1]]+dp[i][1][s[0]])
                        swap(s[0],s[1]);
                    sum+=dp[i][0][s[0]]+dp[i][1][s[1]];
                    for (int j=0;j<m;++j)
                        tmp[i*m+j]=DNA[s[j&1]];
                }
            
            // cout<<a<<" "<<b<<" "<<sum<<endl;
            
            if (ans>sum)    continue;
            ans=sum;
            for (int s=0;s<n*m;++s)
                str[s]=tmp[s];
        }
    // cout<<ans<<endl;
    // for (int i=0;i<n;++i,puts(""))
    //     for (int j=0;j<m;++j)
    //         putchar(str[m*i+j]);
    return ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;++i)
        scanf("%s",s+m*i);
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            t[n*j+i]=s[m*i+j];
    
    int c1=calc(s,n,m,as),c2=calc(t,m,n,at);
    // cout<<"end"<<endl;
    if (c1>c2)
        for (int i=0;i<n;++i,puts(""))
            for (int j=0;j<m;++j)
                putchar(as[m*i+j]);
    else
        for (int i=0;i<n;++i,puts(""))
            for (int j=0;j<m;++j)
                putchar(at[n*j+i]);
    return 0;
}