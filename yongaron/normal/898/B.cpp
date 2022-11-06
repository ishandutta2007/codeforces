#include <iostream>

using namespace std;

bool yes[20000000];
pair<int, int> how[20000000];

int a, b, n;

int main()
{
    cin>>n>>a>>b;
    yes[0] = true;
    how[0].first = 0;
    how[0].second = 0;
    for(int i = 0; i < n; i++)
    {
        if(yes[i])
        {
            yes[i+a] = true;
            how[i+a].first = how[i].first+1;
            how[i+a].second = how[i].second;
            yes[i+b] = true;
            how[i+b].first = how[i].first;
            how[i+b].second = how[i].second+1;
        }
    }
    if(yes[n])
    {
        cout<<"YES"<<endl;
        cout<<how[n].first<<" "<<how[n].second<<endl;
    }
    else
        cout<<"NO"<<endl;
    return 0;
}