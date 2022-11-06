#include <iostream>

using namespace std;

int n, v[4];

int abs(int x)
{
    return min(x, 4*n*n-x);
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int c = 0; c < 4; c++)
    {
        char b;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin>>b;
                b -= '0';
                int k = ((i+j)%2);
                if((k && b)||(!k && !b))
                    v[c]++;
            }
        }
    }
    if(n%2 == 0)
    {
        cout<<abs(v[0]+v[1]+v[2]+v[3])<<endl;
        return 0;
    }
    int ma = abs(2*n*n+v[0]+v[1]-v[2]-v[3]);
    ma = min(ma, abs(2*n*n+v[0]-v[1]+v[2]-v[3]));
    ma = min(ma, abs(2*n*n+v[0]-v[1]-v[2]+v[3]));
    ma = min(ma, abs(2*n*n+-v[0]+v[1]+v[2]-v[3]));
    ma = min(ma, abs(2*n*n+-v[0]+v[1]-v[2]+v[3]));
    ma = min(ma, abs(2*n*n+-v[0]-v[1]+v[2]+v[3]));
    cout<<ma<<endl;
    return 0;
}