#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> v;
    bool je[150];
    for(int i = 0; i < 150; i++)
        je[i] = false;
    int n, x;
    cin>>n>>x;
    int a;
    bool xx = false;
    for(int i = 0; i < n; i++)
    {
        cin>>a;
        je[a] = true;
    }
    int k = 0;
    for(int i = 0; i < x; i++)
    {
        if(!je[i])
            k++;
    }
    if(je[x])
        k++;
    cout<<k<<endl;

    return 0;
}