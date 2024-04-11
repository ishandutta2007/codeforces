#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;

int n, m, k;
vector<vector<char>> t;

char ch(int x)
{
    return (char)('a'+x);
}

void change(int needK)
{
    if(needK==0) return;
    int n1=n;
    if(n1%2==1) n1--;
    int m1=m;
    if(m1%2==1) m1--;
    for(int i=0; i<n1; i+=2)
    {
        for(int j=0; j<m1; j+=2)
        {
            swap(t[i][j+1], t[i+1][j]);
            needK-=2;
            if(needK==0) return;
        }
    }
}

void fillt()
{
    int n1=n;
    if(n1%2==1) n1--;
    for(int i=0; i<n1; i+=2)
    {
        for(int j=0; j<m; j++)
        {
            char cl=ch(4*((i/2)%2)+j%4);
            t[i][j]=cl;
            t[i+1][j]=cl;
        }
    }
}

void printans()
{
    cout<<"YES"<<'\n';
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<t[i][j];
        }
        cout<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n>>m>>k;
        t.assign(n, vector<char>(m, '.'));
        fillt();
        if(n%2==0 && m%2==0)
        {
            if(k%2!=0)
            {
                cout<<"NO"<<'\n';
                continue;
            }
            fillt();
            change(k);
            printans();
        }
        else if(n%2==1)
        {
            int mini=m/2;
            if(k<mini || k%2!=mini%2)
            {
                cout<<"NO"<<'\n';
                continue;
            }
            fillt();
            change(k-mini);
            for(int j=0; j<m; j+=2)
            {
                char cl='x';
                if(j%4!=0) cl='y';
                t[n-1][j]=cl;
                t[n-1][j+1]=cl;
            }
            printans();
        }
        else
        {
            int k2=n*m/2-k;
            int mini=n/2;
            if(k2<mini || k2%2!=mini%2)
            {
                cout<<"NO"<<'\n';
                continue;
            }
            fillt();
            change(k);
            printans();
        }
    }
    return 0;
}