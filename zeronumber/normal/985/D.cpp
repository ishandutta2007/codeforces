#include<bits/stdc++.h>
#define maxn 205000

using namespace std;
typedef long long ll;
ll n,k,l,r,mid,h,d,s,t;

int main()
{
    cin >> n >> k;
    l=0; r=2e9;
    while (r-l>1){
        mid=(l+r)/2;
        h=mid*(mid+1)/2;
        if (k<mid){
            s=(mid-k+1)/2;
            t=(mid-k)/2+1;
            h-=s*t;
        }
        if (h>=n) r=mid; else l=mid;
    }
    cout << r << endl;
}