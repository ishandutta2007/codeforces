#include <iostream>

using namespace std;

int n = 100002;
int fen[200005];
int foo[200005];

void add(int k, int x);
int sum(int k);

int m;

int main()
{
    cin>>m;
    int ma = -1, mai = 0;
    for(int i = 0; i <= m; i++)
        fen[i] = foo[i] = 0;
    for(int i = 0; i < m; i++)
    {
        int p;
        cin>>p;
        int x = sum(p);
        if(x == i-1)
        {
            //cout<<p<<" ";
            int l = p;
            int r = m;
            while(l < r)
            {
                int m = (l+r)/2;
                if(sum(m) == i)
                {
                    r = m;
                }
                else
                    l = m+1;
            }
            foo[l]++;
            //cout<<l<<endl;
        }
        if(x != i)
            foo[p]++;
        add(p, 1);
    }
    for(int i = 1; i <= m; i++)
    {
        if(foo[i] > ma)
        {
            mai = i;
            ma = foo[i];
        }
    }
    cout<<mai<<endl;
    return 0;
}
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