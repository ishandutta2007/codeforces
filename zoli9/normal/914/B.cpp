#include <bits/stdc++.h>
using namespace std;
int n;
int t[100009];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int sz;
        cin>>sz;
        t[sz]++;
    }
    bool ps=true;
    for(int i=1; i<=100007; i++)
    {
        if(t[i]%2==1)
        {
            ps=false;
            break;
        }
    }
    if(ps) cout<<"Agasa"<<endl;
    else cout<<"Conan"<<endl;
    return 0;
}