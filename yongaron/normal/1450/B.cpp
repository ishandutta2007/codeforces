#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t, k;
int x[1234], y[1234];

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i = 0; i < n; i++)
            cin>>x[i]>>y[i];
        bool found = false;
        for(int i = 0; i < n; i++)
        {
            bool ok = true;
            for(int j = 0; j < n; j++)
                if(abs(x[i]-x[j])+abs(y[j]-y[i]) > k)
                    ok = false;
            if(ok)
            {
                found = true;
                break;
            }
        }
        if(found)
            cout<<1<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}