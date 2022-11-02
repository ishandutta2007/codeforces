#include <bits/stdc++.h>
using namespace std;
int n;
int perm[100009];
int valodi[100009];
bool bejar[100009];
vector<int> korok[100009];
int hanykor;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>perm[i];
    }
    hanykor=0;
    for(int i=1; i<=n; i++)
    {
        if(!bejar[i])
        {
            hanykor++;
            korok[hanykor].push_back(i);
            int m=perm[i];
            bejar[i]=true;
            if(perm[i]==i)
            {
                cout<<"YES"<<endl;
                for(int j=1; j<=n; j++)
                {
                    if(j!=i)
                    {
                        cout<<i<<" "<<j<<endl;
                    }
                }
                return 0;
            }
            while(m!=i)
            {
                korok[hanykor].push_back(m);
                bejar[m]=true;
                m=perm[m];
            }
        }
    }
    bool vanketto=false;
    int ok=1;
    for(int i=1; i<=hanykor; i++)
    {
        if(korok[i].size()%2==1)
        {
            cout<<"NO";
            return 0;
        }
        if(korok[i].size()==2)
        {
            ok=i;
            vanketto=true;
        }
    }
    if(!vanketto)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    cout<<korok[ok][0]<<" "<<korok[ok][1]<<endl;
    for(int i=1; i<=hanykor; i++)
    {
        if(i==ok) continue;
        for(int j=0; j<korok[i].size(); j++)
        {
            if(j%2==0)
            {
                cout<<korok[i][j]<<" "<<korok[ok][0]<<endl;
            }
            else
            {
                cout<<korok[i][j]<<" "<<korok[ok][1]<<endl;
            }
        }
    }
    return 0;
}