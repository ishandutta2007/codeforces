#include <iostream>
using namespace std;

string tab[1024];
int eq[1024];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> tab[i];
    }
    
    int ans=0;
    for(int j=0; j<m; j++)
    {
        int anda=1;
        for(int i=1; i<n; i++)
            if(tab[i][j]<tab[i-1][j] && !eq[i]) anda=0;
        
        if(anda)
        {
            for(int i=1; i<n; i++)
                if(tab[i][j]>tab[i-1][j]) eq[i]=1;
        }
        
        ans+=1-anda;
    }
    cout << ans << endl;
}