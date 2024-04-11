#include<bits/stdc++.h>
using namespace std;

int q;

string s,t;

int main()
{
    scanf("%d",&q);
    while(q--)
    {
        cin>>s>>t;
        int ans=0;
        for(int i=0;i<s.size();i++)
            for(int j=i;j<s.size();j++)
            {
                if(j-i+1>t.size())
                    continue;
                string ri=s.substr(i,j-i+1);
                if(j-((int)t.size()-(j-i+1))<0)
                    continue;
                string le=s.substr(j-((int)t.size()-(j-i+1)),((int)t.size()-(j-i+1)));
                reverse(le.begin(),le.end());
                if(ri+le==t)
                    ans=1;
            }
        puts(ans?"YES":"NO");
    }
}