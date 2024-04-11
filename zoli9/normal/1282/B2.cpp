#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int q;
int n, k;
ll p;
ll a[200009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>q;
    for(int tt=1; tt<=q; tt++)
    {
        cin>>n>>p>>k;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        sort(a, a+n);
        ll sum=0;
        int db=0;
        while(1)
        {
            if(db+k>n) break;
            if(sum+a[db+k-1]>p) break;
            db+=k;
            sum+=a[db-1];
        }
        int besti=0;
        for(int i=1; i<k; i++)
        {
            if(db+i>n) break;
            ll sum2=sum;
            sum2+=a[i-1];
            for(int j=k+i-1; j<db+i; j+=k)
            {
                sum2-=a[j-1];
                sum2+=a[j];
            }
            if(sum2<=p)
            {
                sum=sum2;
                besti=i;
            }
            else break;
        }
        cout<<db+besti<<endl;
    }

    return 0;
}