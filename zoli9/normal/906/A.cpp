#include <bits/stdc++.h>
using namespace std;
int n;
int darablehet=26;
bool kizart[26];
bool mostvolt[26];
bool egyertelmu;
int felesleges;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1; i<n; i++)
    {
        char tipus;
        cin>>tipus;
        if(tipus=='!')
        {
            string ss;
            cin>>ss;
            for(int u=0; u<26; u++) mostvolt[u]=0;
            for(int u=0; u<ss.size(); u++)
            {
                mostvolt[ss[u]-'a']=1;
            }
            for(int u=0; u<26; u++)
            {
                if(!mostvolt[u])
                {
                    if(!kizart[u])
                    {
                        kizart[u]=true;
                        darablehet--;
                    }
                }
            }
            if(egyertelmu) felesleges++;
        }
        else if(tipus=='.')
        {
            string ss;
            cin>>ss;
            for(int u=0; u<ss.size(); u++)
            {
                if(!kizart[ss[u]-'a'])
                {
                    kizart[ss[u]-'a']=true;
                    darablehet--;
                }
            }
        }
        else
        {
            char akt;
            cin>>akt;
            if(!kizart[akt-'a'])
            {
                kizart[akt-'a']=true;
                darablehet--;
            }
            if(egyertelmu) felesleges++;
        }
        if(darablehet==1) egyertelmu=true;
    }
    char kkk;
    cin>>kkk;
    char vegso;
    cin>>vegso;
    cout<<felesleges<<endl;
    return 0;
}