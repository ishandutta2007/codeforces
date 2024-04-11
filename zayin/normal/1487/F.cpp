#include<bits/stdc++.h>
#define maxn 70
#define maxA 405
#define maxB 2050
using namespace std;

int n;

const int A=200,B=1000,inf=1e8;
char s[maxn];

int dp[2][maxA][maxB];

void Min(int& a,int b)  {
    a=min(a,b);
}

int main()  {
    scanf("%s",s+1),n=strlen(s+1);
    reverse(s+1,s+n+1);
    for (int i=1;i<=n;++i) s[i]=(s[i]-'0')*9;
    for (int i=1;;n=max(n,i++)) {
        if (i>n&&!s[i]) break;
        s[i+1]+=s[i]/10,s[i]%=10;
    }
    // for (int i=n;i;--i) cout<<(int)s[i]; cout<<endl;

    n+=10;
    int now=0;
    memset(dp,0x3f,sizeof(dp));
    dp[now][A][B]=0;

    for (int i=n;i;--i) {
        now^=1;
        memset(dp[now],0x3f,sizeof(dp[now]));
        for (int a=-A;a<=A;++a)
            for (int b=-B;b<=B;++b) {
                // cout<<"a b:"<<a<<" "<<b<<endl;
                for (int c=-10;c<=10;++c)   {
                    int na=10*a-(c-s[i]),nb=b-c;
                    if (na<-A||na>A||nb<-B||nb>B) continue;
                    Min(dp[now][na+A][nb+B],dp[now^1][a+A][b+B]+(i-1)*abs(c));
                }
            }
        // for (int a=-A;a<=A;++a)
        //     for (int b=-B;b<=B;++b)
        //         if (dp[now][a+A][b+B]<inf)
        //             cout<<"dp["<<i<<"]["<<a<<"]["<<b<<"]="<<dp[now][a+A][b+B]<<endl;
    }

    int ans=inf;
    for (int i=-A;i<=A;++i)
        Min(ans,dp[now][i+A][i+B]);
    
    printf("%d\n",ans);

    return 0;
}