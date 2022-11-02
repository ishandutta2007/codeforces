#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

vi answer;

int d[5009];
int n, m;
void kitolt()
{
    int s=answer.size();
    int kezd=1;
    while(s<n)
    {
        answer.push_back(kezd*100000+1);
        s++;
        kezd++;
    }
}
void kiir()
{
    for(int szam: answer)
    {
        cout<<szam<<" ";
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=1; i<=5000; i++)
    {
        d[i]=(i/2)*((i-1)/2);
    }
    cin>>n>>m;
    if(m==0)
    {
        kitolt();
        kiir();
        return 0;
    }
    int kell=n;
    if(d[kell]<m)
    {
        cout<<-1<<endl;
        return 0;
    }
    while(d[kell]>=m) kell--;
    for(int i=1; i<=kell; i++) answer.push_back(i);
    int plusz=m-d[kell];
    answer.push_back(kell+(kell-2*plusz)+1);
    kitolt();
    kiir();
    return 0;
}