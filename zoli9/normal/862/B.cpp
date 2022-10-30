#include <bits/stdc++.h>

using namespace std;

long long n;
vector<int> G[100009];
bool bejart[100009];
long long egyesek;
long long nullak;

void bejaras(int x, int szin)
{
    bejart[x]=true;
    for(int i=0; i<G[x].size(); i++)
    {
        int szomszed=G[x][i];
        if(!bejart[szomszed])
        {
            if(szin==0)
            {
                egyesek++;
                bejaras(szomszed, 1);
            }
            else
            {
                nullak++;
                bejaras(szomszed, 0);
            }
        }
    }
}

int main()
{
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    egyesek=1;
    bejaras(1, 1);
    cout<<egyesek*nullak-(n-1)<<endl;

}