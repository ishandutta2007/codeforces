#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
typedef long long LL;

char s[maxn],t[maxn];

int main()
{
    scanf("%s",s);
    for (int i=0;i<5;++i)
    {
        scanf("%s",t);
        if (t[0]==s[0]||t[1]==s[1])
            return puts("YES"),0;
    }
    puts("NO");
    return 0;
}