#include <bits/stdc++.h>
using namespace std;
bool ossze[100009];
int mennyi[10009];
int hanyadik[100009];
vector<int> primek;
int n;
int main()
{
    ios::sync_with_stdio(false);
    int cnt=2;
    while(cnt<=100005)
    {
        primek.push_back(cnt);
        hanyadik[cnt]=primek.size()-1;
        for(int i=2*cnt; i<=100008; i+=cnt)
        {
            ossze[i]=true;
        }
        cnt++;
        while(cnt<=100005 && ossze[cnt]) cnt++;
    }
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int A;
        cin>>A;
        int cn=0;
        while(primek[cn]*primek[cn]<=A)
        {
            if(A%primek[cn]==0)
            {
                //cout<<i<<" "<<cn<<endl;
                mennyi[cn]++;
            }
            while(A%primek[cn]==0)
            {
                A/=primek[cn];
            }
            cn++;
        }
        if(A!=1)
        {
            //cout<<i<<" "<<hanyadik[A]<<endl;
            mennyi[hanyadik[A]]++;
        }
    }
    int maxi=1;
    for(int i=0; i<10000; i++)
    {
        maxi=max(maxi, mennyi[i]);
    }
    cout<<maxi<<endl;

    return 0;
}