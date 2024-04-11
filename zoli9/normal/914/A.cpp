#include <bits/stdc++.h>
using namespace std;
int n;
int best;
bool van=false;
int main()
{
    ios::sync_with_stdio(false);

    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int szam;
        cin>>szam;
        if(szam<0)
        {
            if(!van)
            {
                best=szam;
            }
            else
            {
                best=max(best, szam);
            }
            van=true;
        }
        else
        {
            int s=sqrt(szam);
            if(s*s!=szam)
            {
                if(!van)
            {
                best=szam;
            }
            else
            {
                best=max(best, szam);
            }
            van=true;
            }
        }
    }
    cout<<best<<endl;
    return 0;
}