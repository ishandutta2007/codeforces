#include <iostream>
#include <vector>

using namespace std;

int n, m;
int mi, ma;

int main()
{
    int a[102], b[102], x;
    vector<int> y;
    cin>>n>>m;
    mi = 1;
    ma = 999999999;
    for(int i = 0; i < m; i++)
    {
        cin>>a[i]>>b[i];
        /*for(int j = 1; j < 150; j++)
        {
            if(j*(b-1) < a && j*b >= a)
            {
                if(j > mi)
                    mi = j;
                break;
            }
        }
        for(int j = 150; j >= 1; j--)
        {
            if(j*(b-1) < a && j*b >= a)
            {
                if(j < ma)
                    ma = j;
                break;
            }
        }*/
    }
    bool fck;
    x = 0;
    for(int i = 1; i < 105; i++)
    {
        fck = false;
        for(int j = 0; j < m; j++)
        {
            if(!(i*(b[j]-1) < a[j] && i*b[j] >= a[j]))
            {
                fck = true;
                //cout<<i<<" "<<j<<endl;
            }
        }
        if(fck)
            continue;
        y.push_back(i);
        //cout<<i<<endl;
    }
    fck = true;
    for(int i = 0; i < y.size(); i++)
    {
        if(i == y.size()-1)
            break;
        if((n-1)/y[i] != (n-1)/y[i+1])
            fck = false;
    }
    if(fck)
        cout<<(n-1)/y[0]+1<<endl;
    else
        cout<<-1<<endl;
    /*cout<<mi<<" "<<ma<<endl;
    if(n == 1)
        cout<<1<<endl;
    else if((n-1)/mi == (n-1)/ma)
        cout<<n/mi+1<<endl;
    else
        cout<<-1<<endl;*/
    return 0;
}