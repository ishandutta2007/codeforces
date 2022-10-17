#include<cstdio>
int N,M,sum;
char c;
int mp[503][503];//'*'1'.'0
int main()
{
    scanf(" %d %d",&N,&M);
    for(int i=1;i<=N;++i)
    {
        for(int j=1;j<=M;++j)
        {
            scanf(" %c",&c);
            if(c=='*')mp[i][j]=1,++sum;
            else mp[i][j]=0;
        }
    }
    for(int i=1;i<=N;++i)
    {
        for(int j=1;j<=M;++j)
        {
            if(!mp[i][j])continue;//*
            int k,l,r=1,a=0,b=0,c=0,d=0;//k,la,b,c,d
            k=i,l=j-1;
            while(mp[k][l])--l,++r,a=1;//
            k=i,l=j+1;
            while(mp[k][l])++l,++r,b=1;//
            k=i-1,l=j;
            while(mp[k][l])--k,++r,c=1;//
            k=i+1,l=j;
            while(mp[k][l])++k,++r,d=1;//
            if(r==sum&&a&&b&&c&&d)return 0&printf("YES\n");//YES
        }
    }
    return 0&printf("NO\n");//NO
}