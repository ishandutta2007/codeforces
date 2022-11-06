#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int n;
vector < int > strom[100005];
bool byl[100005];

double hl(int vr);

int main()
{
    int a, b;
    cin>>n;
    for(int i = 0; i < n-1; i++)
    {
        cin>>a>>b;
        strom[a].push_back(b);
        strom[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
    {
        byl[i] = false;
    }
    double x = hl(1);
    if(n == 1)
        cout<<0<<endl;
    else
    {
        printf("%lf", x);
        cout<<endl;
    }
    return 0;
}

double hl(int vr)
{
    byl[vr] = true;
    double sum = 0;
    if(strom[vr].size() == 1 && vr != 1)
        return 1;
    for(int i = 0; i < strom[vr].size(); i++)
    {
        if(!byl[strom[vr][i]])
            sum += hl(strom[vr][i]);
    }
    if(vr != 1)
        return sum/(strom[vr].size()-1)+1;
    return sum/(strom[vr].size());
}