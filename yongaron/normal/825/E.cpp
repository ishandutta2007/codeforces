#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int sous[100005], cis[100005];
vector<int> graf[100005], halda;

bool oper(int a, int b)
{
    return a < b;
}
void nacti();
void vyres();

int main()
{
    nacti();
    vyres();
    for(int i = 1; i <= n; i++)
        cout<<cis[i]<<" ";
    cout<<endl;
    return 0;
}
void nacti()
{
    int a, b;
    cin>>n;
    cin>>m;
    for(int i = 1; i <= n; i++)
        sous[i] = 0;
    for(int i = 0; i < m; i++)
    {
        cin>>a;
        cin>>b;
        graf[b].push_back(a);
        sous[a]++;
    }
}
void vyres()
{
    int a, x = n;
    for(int i = 1; i <= n; i++)
    {
        if(!sous[i])
        {
            halda.push_back(i);
            push_heap(halda.begin(), halda.end(), oper);
        }
    }
    while(!halda.empty())
    {
        /*for(int i = 0; i < halda.size(); i++)
            cout<<halda[i]<<" ";
        cout<<endl;*/
        a = halda.front();
        pop_heap(halda.begin(), halda.end(), oper);
        halda.pop_back();
        cis[a] = x;
        x--;
        for(int i = 0; i < graf[a].size(); i++)
        {
            sous[graf[a][i]]--;
            if(!sous[graf[a][i]])
            {
                halda.push_back(graf[a][i]);
                push_heap(halda.begin(), halda.end(), oper);
            }
        }
    }
}