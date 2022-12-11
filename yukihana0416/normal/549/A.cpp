#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn=55;

char ch[maxn][maxn];

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m) && n+m)
    {
        int cnt[5];
        int ans=0;
        for(int i=0;i<n;i++) scanf("%s",ch[i]);
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<m-1;j++)
            {
                memset(cnt,0,sizeof(cnt));
                if(ch[i][j]=='c') cnt[3]=1;
                if(ch[i][j]=='f') cnt[0]=1;
                if(ch[i][j]=='a') cnt[1]=1;
                if(ch[i][j]=='e') cnt[2]=1;
                if(ch[i+1][j]=='c') cnt[3]=1;
                if(ch[i+1][j]=='f') cnt[0]=1;
                if(ch[i+1][j]=='a') cnt[1]=1;
                if(ch[i+1][j]=='e') cnt[2]=1;
                if(ch[i][j+1]=='c') cnt[3]=1;
                if(ch[i][j+1]=='f') cnt[0]=1;
                if(ch[i][j+1]=='a') cnt[1]=1;
                if(ch[i][j+1]=='e') cnt[2]=1;
                if(ch[i+1][j+1]=='c') cnt[3]=1;
                if(ch[i+1][j+1]=='f') cnt[0]=1;
                if(ch[i+1][j+1]=='a') cnt[1]=1;
                if(ch[i+1][j+1]=='e') cnt[2]=1;
                if(cnt[0] && cnt[1] && cnt[2] && cnt[3]) ans++;
            }
        }
        cout <<ans <<endl;
    }
    return 0;
}