#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int> > v;

int main()
{
    cin>>n;
    int ma = 1;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        bool ok = false;
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i].first == a)
            {
                ok = true;
                v[i].second++;
                if(v[i].second > ma)
                    ma = v[i].second;
            }
        }
        if(!ok)
            v.push_back(make_pair(a, 1));
    }
    cout<<ma<<endl;
    return 0;
}