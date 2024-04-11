#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j,posx,posy,l;
    char a[900001];
    char b[460],x,y;
    cin>>n>>m;
    cin>>a;
    for(i=0;i<26;i++) b[i]=i+'a';
    for(i=0;i<m;i++)
    {
        //fflush(stdin);
        scanf(" %c %c",&x,&y);
        for(j=0;j<26;j++)
        {
            if(b[j]==x) posx=j;
            if(b[j]==y) posy=j;
        }
        b[posx]=y;
        b[posy]=x;
    }
    l=strlen(a);
    for(i=0;i<l;i++) a[i]=b[a[i]-'a'];
    a[l]='\0';
    printf("%s",a);
    return 0;
}