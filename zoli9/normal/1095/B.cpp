#include <bits/stdc++.h>
using namespace std;
int n;
int a[100009];
vector<int> w;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    //int mini, maxi;
    //int min2=-1, max2;
    for(int i=1; i<=n; i++)
    {
        int szam;
        cin>>szam;
        w.push_back(szam);
    }
    if(n==2)
    {
        cout<<0<<endl;
        return 0;
    }
    sort(w.begin(), w.end());
    int valasz=min(w.back()-w[1], w[w.size()-2]-w[0]);
    cout<<valasz<<endl;
    return 0;
}