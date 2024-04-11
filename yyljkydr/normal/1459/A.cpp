#include<bits/stdc++.h>
using namespace std;



int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        string r,b;
        cin>>r>>b;
        int ans=0;
        for(int i=0;i<n;i++)
            ans+=r[i]>b[i]?1:(r[i]<b[i]?-1:0);
        if(ans>0)
            puts("RED");
        else if(ans<0)
            puts("BLUE");
        else
            puts("EQUAL");
    }
}