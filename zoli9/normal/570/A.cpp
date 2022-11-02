#include <iostream>
using namespace std;
int n, m;
int darab[109];
int main()
{
    cin>>m>>n;
    for(int i=1; i<=n; i++)
    {
        int ind=1;
        int ert=0;
        for(int j=1; j<=m; j++)
        {
            int a;
            cin>>a;
            if(j==1)
            {
                ert=a;
            }
            else
            {
                if(ert<a)
                {
                    ert=a;
                    ind=j;
                }
            }
        }
        darab[ind]++;
    }
    int leg=1;
    //cout<<darab[1]<<darab[2]<<darab[3]<<endl;
    for(int i=2; i<=m; i++)
    {
        //cout<<darab[i]<<" "<<darab[leg]<<endl;
        if(darab[i]>darab[leg])
        {
            leg=i;
        }
    }
    cout<<leg;
    return 0;
}