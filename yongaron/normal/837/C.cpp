#include <iostream>

using namespace std;

int n, a, b;
pair<int, int> seal[105];

bool fit(int i, int j);

int main()
{
    int ma = 0;
    cin>>n>>a>>b;
    for(int i = 0; i < n; i++)
        cin>>seal[i].first>>seal[i].second;
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            if(seal[i].first*seal[i].second+seal[j].first*seal[j].second > ma && fit(i, j))
                ma = seal[i].first*seal[i].second+seal[j].first*seal[j].second;
    cout<<ma<<endl;
    return 0;
}
bool fit(int i, int j)
{
    int x1 = seal[i].first;
    int y1 = seal[i].second;
    int x2 = seal[j].first;
    int y2 = seal[j].second;
    if(a-x1 >= x2 && b >= y2 && b >= y1)
    {
        return true;
    }
    if(a-x1 >= y2 && b >= x2 && b >= y1)
    {
        return true;
    }
    if(b-x1 >= x2 && a >= y2 && a >= y1)
    {
        return true;
    }
    if(b-x1 >= y2 && a >= x2 && a >= y1)
    {
        return true;
    }
    if(a-y1 >= x2 && b >= y2 && b >= x1)
    {
        return true;
    }
    if(a-y1 >= y2 && b >= x2 && b >= x1)
    {
        return true;
    }
    if(b-y1 >= x2 && a >= y2 && a >= x1)
    {
        return true;
    }
    if(b-y1 >= y2 && a >= x2 && a >= x1)
    {
        return true;
    }
    return false;
}