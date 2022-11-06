#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> tree[2000];
int par[2000], l[2000];


int main()
{
    cin>>n;
    int a;
    for(int i = 2; i <= n; i++)
    {
        cin>>a;
        tree[a].push_back(i);
        par[i] = a;
    }
    for(int i = 2; i <= n; i++)
    {
        if(tree[i].size() == 0)
            l[par[i]]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(tree[i].size() > 0 && l[i] < 3)
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}