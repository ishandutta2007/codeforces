#include <iostream>
using namespace std;
int n;
int lost[52];
int won[52];
int meccs[3];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        lost[i]=0;
        won[i]=0;
    }
    for(int i=1; i<=n*(n-1)/2-1; i++)
    {
        int a, b;
        cin>>a>>b;
        won[a]++;
        lost[b]++;
    }
    int meccsdb=1;
    for(int i=1; i<=n; i++)
    {
        if(won[i]+lost[i]!=n-1)
        {
            meccs[meccsdb]=i;
            meccsdb++;
        }
    }
    if(won[meccs[1]]>won[meccs[2]])
    {
        cout<<meccs[1]<<" "<<meccs[2];
    }
    else
    {
        cout<<meccs[2]<<" "<<meccs[1];
    }
    return 0;
}