#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

map<string,int>tw,tr;

int T,n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n;
        bool ok=0;
        tw.clear();
        tr.clear();
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            string rs=s;
            reverse(rs.begin(),rs.end());
            if(s==rs)
                ok=1;
            else
            {
                if(s.size()==2)
                {
                    if(tw.count(rs))
                        ok=1;
                    else
                    {
                        for(char i='a';i<='z';i++)
                        {
                            string tmp=rs+i;
                            if(tr.count(tmp))
                                ok=1;
                        }
                    }
                    tw[s]=1;
                }
                else
                {
                    if(tr.count(rs))
                        ok=1;
                    else
                    {
                        if(tw.count(rs.substr(0,2)))
                        {
                            ok=1;
                        }
                    }
                    tr[s]=1;
                }
            }
        }
        puts(ok?"YES":"NO");
    }
}