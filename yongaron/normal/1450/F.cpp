#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

int times[123456];
int konce[123456];

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ans = 0;
        int a;
        int matimes = 0;
        int maends = 0;
        int l;
        for(int i = 0; i <= n; i++)
            times[i] = konce[i] = 0;
        for(int i = 0; i < n; i++)
        {
            cin>>a;
            matimes = max(matimes, ++times[a]);
            if(!i)
            {
                maends = max(maends, ++konce[a]);
            }
            else if(a == l)
            {
                konce[a] += 2;
                maends = max(maends, konce[a]);
                ans += 1;
            }
            l = a;
        }
        maends = max(maends, ++konce[l]);
        if(matimes > (n+1)/2)
            cout<<-1<<endl;
        else
        {
            while(maends-2 > ans)
                ans++;
            cout<<ans<<endl;   
        }
        
    }
    return 0;
}