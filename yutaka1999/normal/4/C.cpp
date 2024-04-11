#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>

using namespace std;

map <string,int> mp;
char str[35];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",&str);
        string s=str;
        int v=mp[s];
        if(v==0) puts("OK");
        else printf("%s%d\n",str,v);
        mp[s]++;
    }
    return 0;
}