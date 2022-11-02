#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n, m;
int people[1029];
int pizza[1029];
int pizzaid[1029];
ll pr[100009];
int olcso1=1, olcso2=2;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        int tip=0;
        int num;
        cin>>num;
        for(int j=1; j<=num; j++)
        {
            int ing;
            cin>>ing;
            tip=((1<<(ing-1))|tip);
        }
        for(int j=0; j<512; j++) if((j&tip)==tip) people[j]++;
    }
    for(int i=1; i<=m; i++)
    {
        cin>>pr[i];
        int tip=0;
        int num;
        cin>>num;
        for(int j=1; j<=num; j++)
        {
            int ing;
            cin>>ing;
            tip=((1<<(ing-1))|tip);
        }
        if(pizza[tip]==0 || pr[i]<pizza[tip])
        {
            pizza[tip]=pr[i];
            pizzaid[tip]=i;
        }
    }
    if(pr[olcso1]>pr[olcso2]) swap(olcso1, olcso2);
    for(int i=3; i<=m; i++)
    {
        if(pr[i]<pr[olcso1])
        {
            olcso2=olcso1;
            olcso1=i;
        }
        else if(pr[i]<pr[olcso2])
        {
            olcso2=i;
        }
    }
    int ans1=olcso1;
    int ans2=olcso2;
    //cout<<ans1<<" es "<<ans2<<endl;
    ll price=pr[olcso1]+pr[olcso2];
    int ppl=0;
    for(int i=0; i<512; i++)
    {
        if(pizza[i]==0) continue;
        int ujp=people[i];
        ll ujprice=pr[pizzaid[i]]+pr[olcso1];
        int masik=olcso1;
        if(pizzaid[i]==olcso1)
        {
            ujprice=pr[pizzaid[i]]+pr[olcso2];
            masik=olcso2;
        }
        if(ujp>ppl || (ujp==ppl && ujprice<price))
        {
            ans1=pizzaid[i];
            ans2=masik;
            ppl=ujp;
            price=ujprice;
        }
        for(int j=i+1; j<512; j++)
        {
            if(pizza[j]==0) continue;
            int ujp=people[i|j];
            ll ujprice=pr[pizzaid[i]]+pr[pizzaid[j]];
            if(ujp>ppl || (ujp==ppl && ujprice<price))
            {
                ans1=pizzaid[i];
                ans2=pizzaid[j];
                ppl=ujp;
                price=ujprice;
            }
        }
    }
    cout<<ans1<<" "<<ans2<<endl;

    return 0;
}