#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n,k;

char s[N];

int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    int m=0,j=0;
    for(int i=1;i<n;i++)
    {
        if(s[i]>s[j])
        {
            m=i-j;
            break;
        }
        if(s[i]==s[j])
        {
            j++;
            continue;
        }
        j=0;
    }
    if(!m)
        m=n-j;
    for(int i=0;i<k;i++)
        putchar(s[i%m]);
    puts("");
}