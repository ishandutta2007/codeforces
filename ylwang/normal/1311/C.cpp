#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
#include<cmath>
#define maxn 200007
#define ll long long  
using namespace std;
int T,n,m,b[maxn],sum,ans[27];
char s[maxn]; 
inline int read()
{
    int x = 0;
    int flag = 1;
    char ch;
    ch = getchar();
    while(!isdigit(ch)) 
    {
        if(ch == '-') flag = -1;
    ch = getchar();
    } 
    while(isdigit(ch))
    {
        x = (x<<1) + (x<<3) + ch - 48;
        ch = getchar();
    }
    return x * flag;
}

int main()
{
    T = read();
    while(T--)
    {
        n = read();
        m = read();
        sum = 0;
        scanf("%s",s);
        memset(b,0,sizeof(b));
        memset(ans,0,sizeof(ans));
        for(register int i = 1;i <= m;i++)
        {
            int x = read();
            b[x - 1]++;
        }
        for(register int i = n - 1;i >= 0;i--)
        {
            sum += b[i];
            ans[s[i] - 96] += sum;
            ans[s[i] - 96]++;
        }
        for(register int i = 1;i <= 26;i++)
        {
            printf("%d ",ans[i]);
        }
        puts("");
    }

    return 0;
}