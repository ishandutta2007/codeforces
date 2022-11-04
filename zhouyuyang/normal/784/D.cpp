#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int s[]={8,-1,-1,-1,6,9,4,-1,0,5};
char st[12313];

int main()
{
    scanf("%s",st+1);int n=strlen(st+1);
    for(int i=1,j=n;i<j;i++,j--)
        if(st[i]!=st[j]&&s[st[i]-'0']!=st[j]-'0') return 0*puts("No");
    if(n&1){if(st[n/2+1]!='3'&&st[n/2+1]!='7')return 0*puts("No");}
    puts("YES");
    return 0;
}