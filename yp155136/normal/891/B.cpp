#include <bits/stdc++.h>
using namespace std;

int a[23];
int b[23];

int main ()
{
    int n;
    cin >> n;
    //map<int,int> mp;
    vector< pair<int,int> > v;
    for (int i=1;n>=i;i++)
    {
        cin >> a[i];
        v.push_back(make_pair(a[i],i));
        //mp[ a[i] ] = i;
    }
    sort(v.begin(),v.end());
    v.push_back(v.front());
    for (int i=0;n>i;i++)
    {
        b[ v[i+1].second ] = v[i].first;
    }
    for (int i=1;n>=i;i++) cout << b[i]<<' ';
}