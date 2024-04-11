#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int q;
int n;
vector<int> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>q;
    for(int tt=1; tt<=q; tt++)
    {
        cin>>n;
        v.resize(4*n);
        for(int i=0; i<4*n; i++)
        {
            cin>>v[i];
        }
        sort(v.begin(), v.end());
        int i=0;
        int j=4*n-1;
        int area=-1;
        bool vege=false;
        while(i<j)
        {
            if(v[i]!=v[i+1] || v[j]!=v[j-1])
            {
                cout<<"NO"<<endl;
                vege=true;
                break;
            }
            int newarea=v[i]*v[j];
            if(area==-1) area=newarea;
            else
            {
                if(area!=newarea)
                {
                    cout<<"NO"<<endl;
                    vege=true;
                    break;
                }
            }
            i+=2;
            j-=2;
        }
        if(vege) continue;
        cout<<"YES"<<endl;
    }
    return 0;
}