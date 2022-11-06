#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> graf[100005];
bool byl[100005];
long long red = 0;
long long blue = 0;

void hl(int vr, bool col)
{
    byl[vr] = true;
    if(col)
        red++;
    else
        blue++;
    for(int i = 0; i < graf[vr].size(); i++)
    {
        if(!byl[graf[vr][i]])
            hl(graf[vr][i], !col);
    }
}

int main()
{
    int a, b;
    cin>>n;
    for(int i = 0; i < n-1; i++)
    {
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    for(int i = 0; i < n+1; i++)
        byl[i] = false;
    hl(1, true);
    cout<<red*blue-(long long)n+(long long)1<<endl;
    return 0;
}