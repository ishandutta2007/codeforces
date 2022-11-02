#include <iostream>
#include <vector>
using namespace std;
int n, m;
long long mod=1000000007;
long long ans=1;
bool bejar[100009];
vector<int> p[100009];
vector<bool> barat[100009];
int kezd[100009];
int veg[100009];
int komp[100009];
int komponensek=0;
bool bar[100009];
int main()
{
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        kezd[i]=a;
        veg[i]=b;
        bar[i]=c;
        p[a].push_back(b);
        p[b].push_back(a);
        if(c)
        {
            barat[a].push_back(true);
            barat[b].push_back(true);
        }
        else
        {
            barat[a].push_back(false);
            barat[b].push_back(false);
        }


    }
    for(int i=1; i<=n; i++)
    {
        if(!bejar[i])
        {
            komponensek++;
            int sor[100009];
            int sk=1, sv=1;
            int ind=i;
            int akt;
            sor[1]=ind;
            komp[ind]=1;
            bejar[ind]=true;
            while(sk<=sv)
            {
                akt=sor[sk];
                for(int j=0; j<p[akt].size(); j++)
                {
                    int szom=p[akt][j];
                    if(!bejar[szom])
                    {
                        sv++;
                        sor[sv]=szom;
                        bejar[szom]=true;

                        //cout<<akt<<" "<<" "<<p[akt][j]<<" "<<komp[akt]<<" "<<barat[akt][j]<<endl;

                        if(barat[akt][j])
                        {
                            komp[szom]=komp[akt];
                        }
                        else
                        {
                            komp[szom]=3-komp[akt];
                        }
                    }
                }
                sk++;
            }
        }
    }
    //cout<<komponensek;
    /*for(int i=1; i<=n; i++)
    {
        cout<<komp[i]<<" ";
    }*/
    for(int i=1; i<=m; i++)
    {
        if(bar[i])
        {
            if(komp[kezd[i]]!=komp[veg[i]])
            {
                cout<<0;
                return 0;
            }
        }
        else
        {
            if(komp[kezd[i]]==komp[veg[i]])
            {
                cout<<0;
                return 0;
            }
        }
    }

    for(int i=1; i<komponensek; i++)
    {
        ans*=2;
        ans%=mod;
    }
    cout<<ans;
    return 0;
}