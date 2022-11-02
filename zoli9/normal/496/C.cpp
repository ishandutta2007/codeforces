#include <iostream>
using namespace std;
int n, m, db;
string a[101];
bool v[101];
bool jo;
int main()
{
cin>>n>>m;
db=0;
for(int i=1; i<=n; i++)
{
   cin>>a[i];
   v[i]=false;
}
for(int i=0; i<m; i++)
{
    jo=true;
    for(int j=2; j<=n; j++)
    {
        if(v[j])
        {

        }
        else
        {

            if(a[j][i]<a[j-1][i])
            {

                jo=false;
            }
            else
            {

            }
        }
    }
    if(jo)
    {
        for(int j=2; j<=n; j++)
        {
            if(!v[j])
            {
                if(a[j][i]>a[j-1][i])
                {
                    v[j]=true;
                }
            }
        }
    }
    else
    {
        db++;

    }
}
cout<<db;

    return 0;
}