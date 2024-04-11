#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int n;
int t[100009];
vi ans;

void kiir()
{
    cout<<"ans: "<<endl;
    for(int i=(int)(ans.size())-1; i>=0; i--)
    {
        cout<<ans[i];
    }
    cout<<endl;
}

void trying(int ix)
{
    vi sum;
    int cry=0;
    int i=0;
    int j=ix;
    while(i<ix || j<n)
    {
        if(i==ix)
        {
            cry+=t[j];
            sum.push_back(cry%10);
            cry/=10;
            j++;
        }
        else if(j==n)
        {
            cry+=t[i];
            sum.push_back(cry%10);
            cry/=10;
            i++;
        }
        else
        {
            cry+=(t[i]+t[j]);
            sum.push_back(cry%10);
            cry/=10;
            i++;
            j++;
        }

    }
    if(cry>0) sum.push_back(cry);
    if(ans.size()==0 || sum.size()<ans.size())
    {
        ans=sum;
        return;
    }
    if(sum.size()==ans.size())
    {
        for(int i=(int)(sum.size())-1; i>=0; i--)
        {
            if(sum[i]<ans[i])
            {
                ans=sum;
                return;
            }
            if(sum[i]>ans[i]) return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=n-1; i>=0; i--)
    {
        char ccc;
        cin>>ccc;
        t[i]=ccc-'0';
    }
    int bal=n/2;
    int jobb=n/2+1;
    while(bal>0)
    {
        if(t[bal-1]>0)
        {
            trying(bal);
            //kiir();
            break;
        }
        bal--;
    }
    while(jobb<n)
    {
        if(t[jobb-1]>0)
        {
            trying(jobb);
            //kiir();
            break;
        }
        jobb++;
    }
    for(int i=(int)(ans.size())-1; i>=0; i--)
    {
        cout<<ans[i];
    }
    cout<<endl;


    return 0;
}