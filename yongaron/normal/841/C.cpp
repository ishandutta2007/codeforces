#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int n;
vector<int> a;
vector<pair<int, int> > b;
int c[250000];

bool v(int x, int y)
{
    return x > y;
}
bool m(pair<int, int> x, pair<int, int> y)
{
    return x.first < y.first;
}

int main()
{
    cin>>n;
    int x;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        a.push_back(x);
    }
    cin>>x;
    b.push_back(make_pair(x, 0));
    for(int i = 1; i < n; i++)
    {
        scanf("%d", &x);
        b.push_back(make_pair(x, i));
    }

    sort(a.begin(), a.end(), v);
    sort(b.begin(), b.end());
    for(int i = 0; i < n; i++)
    {
        c[b[i].second] = a[i];
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d ", c[i]);
    }
    cout<<endl;
    return 0;
}