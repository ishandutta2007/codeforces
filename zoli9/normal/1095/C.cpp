#include <bits/stdc++.h>
using namespace std;
int powers[40];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int k;
    cin>>n>>k;
    if(k>n)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    int hatv=0;
    int eddig=0;
    while(n>0)
    {
        if(n%2)
        {
            powers[hatv]++;

        eddig++;

        }

        hatv++;
        n/=2;
    }
    if(k<eddig)
    {
        cout<<"NO"<<endl;
        return 0;
    }

    while(eddig<k)
    {
        while(powers[hatv]<=0)
        {
            hatv--;
        }
        powers[hatv]--;
        powers[hatv-1]+=2;
        eddig++;
    }
    cout<<"YES"<<endl;
    for(int i=0; i<40; i++)
    {
        for(int j=0; j<powers[i]; j++)
        {
            cout<<(1<<(i))<<" ";
        }
    }
    cout<<endl;
    return 0;
}