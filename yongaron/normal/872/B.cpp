#include <bits/stdc++.h>


#define forn(n) for(int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair
#define moc 1000000000;
#define llmoc 1000000000000000000;

using namespace std;

typedef long long ll;
typedef vector<int> vei;
typedef pair<int, int> pai;
typedef vector<pair<int, int> > vepai;

int n, k, ma = -1000000001, mi = 1000000001;
int a[1000005];

int main()
{
    cin>>n>>k;
    forn(n)
    {
        cin>>a[i];
        if(a[i] < mi)
            mi = a[i];
        if(a[i] > ma)
            ma = a[i];
    }
    if(k == 1)
        cout<<mi<<endl;
    if(k > 2)
        cout<<ma<<endl;
    if(k == 2)
        cout<<max(a[0], a[n-1])<<endl;
    return 0;
}