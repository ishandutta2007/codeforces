#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int maxi=0;
int sum=0;
int main()
{
    for(int i=0; i<5; i++)
    {
        int xy;
        cin>>xy;
        sum+=xy;
        v.push_back(xy);
    }
    sort(v.begin(), v.end());
    if(v[0]==v[1]) maxi=max(maxi, 2*v[0]);
    if(v[1]==v[2]) maxi=max(maxi, 2*v[1]);
    if(v[2]==v[3]) maxi=max(maxi, 2*v[2]);
    if(v[3]==v[4]) maxi=max(maxi, 2*v[3]);
    if(v[0]==v[2]) maxi=max(maxi, 3*v[0]);
    if(v[1]==v[3]) maxi=max(maxi, 3*v[1]);
    if(v[2]==v[4]) maxi=max(maxi, 3*v[2]);
    cout<<sum-maxi;
    return 0;
}