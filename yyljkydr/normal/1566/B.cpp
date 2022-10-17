#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T;

char s[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s+1);
        int n=strlen(s+1);
        int t=0;
        for(int i=1,j;i<=n;i=j+1)
        {
            j=i;
            while(s[i]=='0'&&j+1<=n&&s[j+1]=='0')
                j++;
            if(s[i]=='0')
                t++;
        }
        printf("%d\n",min(t,2));
    }
}