#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int n,T,last,ans;
char ch[200001];
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%s",ch+1);//1 
        last=0;
        //last'R'0'R' 
        ans=0;// 
        ch[0]='R';
        n=strlen(ch);//n
        for(int i=1;i<=n;i++)
        {
            if(ch[i]=='R')//'R' 
            {
                ans=max(ans,i-last);//  'R'  
                last=i;
            }
        }
        ans=max(ans,n-last);//'R'n+1 
        printf("%d\n",ans);
    }
    return 0;
}