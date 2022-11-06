#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, b[200005];
pair<int, int> a[200005];
int fen[200005];
vector<pair<int, int> > h;

void add(int k, int x)
{
    while(k <= n)
    {
        fen[k] += x;
        k += k&-k;
    }
}
int sum(int k)
{
    int s = 0;
    while(k > 0)
    {
        s += fen[k];
        k -= k&-k;
    }
    return s;
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>b[i];
        a[i] = make_pair(b[i], i);
    }
    sort(a, a+n);
    long long s = 0;
    int c = 0;
    for(int i = 1; i <= n; i++)
    {
        while(a[c].first < i)
        {
            add(a[c].second+1, 1);
            c++;
        }
        //cout<<"!"<<c<<endl;
        /*for(int j = 0; j < n; j++)
            cout<<min(b[j], n)-sum(min(b[j], n)-1)-1<<" ";
        cout<<endl;*/
        //cout<<min(b[i-1], n)<<" "<<i<<endl;
        //cout<<min(b[i-1], n)-sum(min(b[i-1], n))-1<<" "<<(i-sum(i-1))-1<<endl;
        s += min(b[i-1], n)-sum(min(b[i-1], n))-(min(i, b[i-1])-sum(min(i, b[i-1])));
    }
    cout<<s<<endl;
    return 0;
}