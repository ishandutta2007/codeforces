#include <iostream>
using namespace std;
int n;
int db=1;
struct pont
{
    int x, y;
};
pont o;
pont t[1005];
bool ok(pont k, pont a, pont b)
{
    if((a.x-k.x)*(b.y-k.y)==(a.y-k.y)*(b.x-k.x))
    {
        return true;
    }
    return false;
}
int main()
{
    cin>>n;
    cin>>o.x>>o.y;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i].x>>t[i].y;
    }
    for(int i=2; i<=n; i++)
    {
        bool v=false;
        for(int j=1; j<i; j++)
        {
            if(ok(o, t[i], t[j]))
            {
                v=true;
            }
        }
        if(!v)
        {
            db++;
        }
    }
    cout<<db;


    return 0;
}