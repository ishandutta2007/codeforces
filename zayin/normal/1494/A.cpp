#include<bits/stdc++.h>
#define maxn 505
using namespace std;

int n;
char s[maxn],t[maxn];

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%s",s+1),n=strlen(s+1);

        bool ans=0;
        for (int s=0;s<8;++s)   {
            for (int i=1;i<=n;++i)  {
                int t=::s[i]-'A';
                if (s>>t&1)
                    ::t[i]='(';
                else
                    ::t[i]=')';
            }
            int cnt=0,flag=1;
            for (int i=1;i<=n;++i)  {
                if (t[i]=='(')
                    ++cnt;
                else
                    flag&=(cnt-->0);
            }
            flag&=!cnt;
            ans|=flag;
        }
        puts(ans?"YES":"NO");
    }
    return 0;
}