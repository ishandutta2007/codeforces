#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<cstring>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<utility>
using namespace std;
char ch[202000]={},ans1[202000]={},ans2[202000]={};
int l;
bool b[202000]={};
int main()
{   
    gets(ch);
    l=strlen(ch);
    if(l<=2)
        puts(ch);
    else
    {
        int p=1;
        ans1[0]=ch[0];
        ans1[1]=ch[1];
        for(int i=2;i<l;++i)
            if(ch[i]!=ch[i-1] || ch[i]!=ch[i-2])
                ans1[++p]=ch[i];
        if(p<=2)
            puts(ans1);
        else
        {
            ans2[0]=ans1[0];
            ans2[1]=ans1[1];
            ans2[2]=ans1[2];
            int t=2;
            for(int i=3;i<l;++i)
                if(ans1[i]!=ans2[t] || ans2[t-1]!=ans2[t-2])
                    ans2[++t]=ans1[i];
            puts(ans2);
        }
    }
    return 0;
}