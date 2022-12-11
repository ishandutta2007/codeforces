#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <list>
#include <vector>
using namespace std;

typedef long long LL;

inline LL read()
{
    LL x=0,f=1; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-')f=-f; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define MID(a,b) (((a)+(b))>>1)
#define maxx(a,b) ((a)<(b)?(b):(a))
#define minx(a,b) ((a)<(b)?(a):(b))

const int INF=(int) 0x3f3f3f3f;
const int maxn=(int) 700+20;
const int mod=(int) 1000000007;
const double eps=(double) 1e-8;

LL dp[maxn][maxn][3][3];
int nxt[maxn];
int n;
char s[maxn];
stack<int> st;

inline void pre_work()
{
    memset(dp,0,sizeof(dp));
    while(!st.empty()) st.pop();
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='(') st.push(i);
        else
        {
            int t=st.top(); st.pop();
            nxt[t]=i;
        }
    }
}

void DP(int l,int r)
{
    if(l+1==r)
    {
        dp[l][r][0][1]=dp[l][r][1][0]=1;
        dp[l][r][0][2]=dp[l][r][2][0]=1;
        return ;
    }
    if(nxt[l]==r)
    {
        DP(l+1,r-1);
        for(int i=0;i<3;i++) for(int j=0;j<3;j++)
        {
            if(i!=1)
                dp[l][r][1][0]=(dp[l][r][1][0]+dp[l+1][r-1][i][j])%mod;
            if(i!=2)
                dp[l][r][2][0]=(dp[l][r][2][0]+dp[l+1][r-1][i][j])%mod;
            if(j!=1)
                dp[l][r][0][1]=(dp[l][r][0][1]+dp[l+1][r-1][i][j])%mod;
            if(j!=2)
                dp[l][r][0][2]=(dp[l][r][0][2]+dp[l+1][r-1][i][j])%mod;
        }
    }
    else
    {
        int id=nxt[l];
        DP(l,id); DP(id+1,r);
        for(int i=0;i<3;i++) for(int j=0;j<3;j++)
        for(int p=0;p<3;p++) for(int q=0;q<3;q++)
        {
            if(!(j && p && j==p))
                dp[l][r][i][q]=
                (dp[l][r][i][q]+(dp[l][id][i][j]*dp[id+1][r][p][q])%mod)%mod;
        }
    }
}
int main()
{
//    freopen("in.txt","r",stdin);
    while(~scanf("%s",s+1))
    {
        n=strlen(s+1);
        pre_work();
        DP(1,n);
        LL ans=0;
        for(int i=0;i<3;i++) for(int j=0;j<3;j++)
            ans=(ans+dp[1][n][i][j])%mod;
        cout <<ans <<endl;
    }
    return 0;
}