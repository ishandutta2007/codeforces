#include <bits/stdc++.h>
using namespace std;
int test;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++)
        {
            cin>>v[i];
        }
        sort(v.begin(), v.end());
        vector<int> w;
        w.push_back(v[0]);
        for(int i=1; i<n; i++)
        {
            if(v[i]!=v[i-1]) w.push_back(v[i]);
        }
        int ans=0;
        for(int i=(int)w.size()-1; i>=max(0, (int)w.size()-5); i--)
        {
            int kezd=w[i];
            int m2=0;
            int m3=0;
            for(int j2=i-1; j2>=0; j2--)
            {
                if(kezd%w[j2]!=0)
                {
                    m2=w[j2];
                    for(int j3=j2-1; j3>=0; j3--)
                    {
                        if(kezd%w[j3]!=0 && m2%w[j3]!=0)
                        {
                            m3=w[j3];
                            break;
                        }
                    }
                    break;
                }
            }
            ans=max(ans, kezd+m2+m3);
        }
        cout<<ans<<endl;
    }
    return 0;
}