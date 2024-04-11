#include<bits/stdc++.h>
using namespace std;

const int N=5e3+1e3+7,P=998244353;

int T;

char s[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        int n=strlen(s);
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                if(s[i]=='a')
                    s[i]='b';
                else
                    s[i]='a';
            }
            else
            {
                if(s[i]=='z')
                    s[i]='y';
                else
                    s[i]='z';
            }
        }
        puts(s);
    }    
}