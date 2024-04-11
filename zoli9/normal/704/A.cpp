#include <bits/stdc++.h>
using namespace std;
vector<int> note[300009];
set<int> s;
int n, q;
int main()
{
    cin>>n>>q;
    int uze=0;
    for(int u=1; u<=q; u++)
    {
        int tip, val;
        cin>>tip>>val;
        if(tip==1)
        {
            uze++;
            note[val].push_back(uze);
            s.insert(uze);
        }
        else if(tip==2)
        {
            while(note[val].size()>0)
            {
                int xx=note[val].back();
                if(s.find(xx)!=s.end())
                {
                    s.erase(xx);
                }
                note[val].pop_back();
            }
        }
        else if(tip==3)
        {
            auto it=s.begin();
            while(it!=s.end() && (*it)<=val)
            {
                s.erase(it++);
            }
        }
        cout<<s.size()<<endl;
    }

    return 0;
}