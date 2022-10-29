#include<cstdio>
#include<cstring>
using namespace std;
char cg[110];
int s[110],t[110];
int main()
{
    scanf("%s",cg+1);
    int n=strlen(cg+1);
    s[0]=0;
    for(int i=1;i<=n;i++)s[i]=s[i-1]+(cg[i]=='Q');
    s[n+1]=0;
    for(int i=n;i>=1;i--)t[i]=t[i+1]+(cg[i]=='Q');
    int ss=0;
    for(int i=1;i<=n;i++)ss=ss+(cg[i]=='A')*s[i]*t[i];
    printf("%d\n",ss);
    return 0;
}