#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s,p;
    cin>>s>>p;
    int pos=0;
    for(int i=0;i<p.size();i++)
    {
        if(pos>=s.size()) break;
        if(s[pos]==p[i]) pos++;
    }
    if(pos==s.size()) printf("%d\n",pos);
    else printf("%d\n",pos+1);
    return 0;
}