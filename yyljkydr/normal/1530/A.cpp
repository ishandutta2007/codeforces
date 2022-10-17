#include<bits/stdc++.h>
using namespace std;

int T;

char s[11];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        printf("%d\n",*max_element(s,s+strlen(s))-'0');
    }
}