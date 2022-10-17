#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,x,y,cnt[N];

char s[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&x,&y);
        scanf("%s",s+1);
        cnt['U']=cnt['D']=cnt['L']=cnt['R']=0;
        for(int i=1;i<=strlen(s+1);i++)
            cnt[s[i]]++;
        if(x>cnt['R']||x<-cnt['L']||y>cnt['U']||y<-cnt['D'])
            puts("NO");
        else
            puts("YES");
    }
}