#include <iostream>

using namespace std;

int abs(int x) {return (x>=0)?x:-x;}

int main()
{
    int n,k; cin>>n>>k;
    int arr[n]; for(int i=0;i<n;++i) cin>>arr[i];
    int ans_i = 0; for(int i=0;i<n;++i) ans_i += arr[i];

    int ans = 0;
    for(int i=0;i<k;i++)
    {
        int ans_n = ans_i;
        for(int j = i; j < n; j += k)
        {
            ans_n -= arr[j];
        }
        if(abs(ans_n) > ans) ans = abs(ans_n);
    }

    cout<<ans;
    return 0;
}