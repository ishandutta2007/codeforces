#include <bits/stdc++.h>
using namespace std;
int n;
int db[59];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int ss;
        cin>>ss;
        db[ss]++;
    }
    for(int i=1; i<=50; i++)
    {
        if(db[i]>0)
        {
            if(db[i]>n/2)
            {
                cout<<"Bob"<<endl;
            }
            else cout<<"Alice"<<endl;
            return 0;
        }
    }


    return 0;
}