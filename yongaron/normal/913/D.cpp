#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, T;
vector<pair<int, int> > a[2000005];
vector<pair<int, int> > mah;
int s, p;

int main()
{
    cin>>n>>T;
    s = 0, p = 0;
    for(int i = 0; i < n; i++)
    {
        int b, t;
        cin>>b>>t;
        a[b].push_back(make_pair(t, i));
    }
    for(int i = 1; i <= n; i++)
        sort(a[i].begin(), a[i].end());
    for(int i = n; i > 0; i--)
    {
        //cout<<i<<endl;
        int j = 0;
        if(p > i)
        {
            cout<<p<<endl<<p<<endl;
            for(int i = 0; i < p; i++)
                cout<<mah[i].second+1<<" ";
            cout<<endl;
            return 0;
        }
        while(j < a[i].size() && ((s+a[i][j].first <= T && p < i) || (mah.size() > 0 && a[i][j].first < mah.front().first)))
        {
            //cout<<i<<" "<<j<<endl;
            if(s+a[i][j].first <= T && p < i)
                p++;
            else
            {
                s -= mah.front().first;
                pop_heap(mah.begin(), mah.end());
                mah.pop_back();
            }
            s += a[i][j].first;
            mah.push_back(a[i][j]);
            push_heap(mah.begin(), mah.end());
            j++;
        }
    }
    cout<<p<<endl<<p<<endl;
    for(int i = 0; i < p; i++)
        cout<<mah[i].second+1<<" ";
    cout<<endl;
    return 0;
}