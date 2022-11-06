#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
pair<long long, long long> num[202];
vector<pair<int, int> > v1[202];
vector<pair<int, int> > v2[202];

int pet(long long m)
{
    int k = 0;
    while(m%5 == 0)
    {
        m /= 5;
        k++;
    }
    return k;
}
int dva(long long m)
{
    int k = 0;
    while(m%2 == 0)
    {
        m /= 2;
        k++;
    }
    return k;
}

int main()
{
    long long a, b;
    cin>>n>>k;
    for(int i = 0; i < n; i++)
    {
        cin>>a;
        num[i].first = pet(a);
        num[i].second = dva(a);
    }
    v1[0].push_back(make_pair(0, 0));
    for(int i = 0; i < n; i++)
    {
        for(int f = k-1; f >= 0; f--)
        {
            for(int j = 0; j < v1[f].size(); j++)
                v2[f].push_back(make_pair(v1[f][j].first+num[i].first, v1[f][j].second+num[i].second));
            sort(v2[f].begin(), v2[f].end());
            if(v2[f].size())
            {
                v1[f+1].push_back(v2[f][v2[f].size()-1]);
                a = v2[f][v2[f].size()-1].first;
            }
            for(int i = v2[f].size()-2; i >= 0; i--)
            {
                if(v2[f][i].first != a)
                {
                    a = v2[f][i].first;
                    v1[f+1].push_back(v2[f][i]);
                }
            }
            v2[f].clear();
        }
        for(int f = k-1; f >= 0; f--)
        {
            for(int j = 0; j < v1[f].size(); j++)
                v2[f].push_back(v1[f][j]);
            v1[f].clear();
            sort(v2[f].begin(), v2[f].end());
            if(v2[f].size())
            {
                v1[f].push_back(v2[f][v2[f].size()-1]);
                a = v2[f][v2[f].size()-1].first;
            }
            for(int i = v2[f].size()-2; i >= 0; i--)
            {
                if(v2[f][i].first != a)
                {
                    a = v2[f][i].first;
                    v1[f].push_back(v2[f][i]);
                }
            }
            v2[f].clear();
        }
    }
    int ma = 0;
    for(int i = 0; i < v1[k].size(); i++)
        if(min(v1[k][i].first, v1[k][i].second) > ma)
            ma = min(v1[k][i].first, v1[k][i].second);
    /*for(int i = 0; i <= k; i++)
    {
        for(int j = 0; j < v1[i].size(); j++)
        {
            cout<<v1[i][j].first<<" "<<v1[i][j].second<<" \t";
        }
        cout<<endl;
    }*/
    cout<<ma<<endl;
    return 0;
}