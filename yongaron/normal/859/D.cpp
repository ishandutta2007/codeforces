#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int n, m;
vector<double> prob[200];
vector<double> pay[200];
double maxpay[200];
int win[100][100];

int exp(int a)
{
    if(a == 0)
        return 1;
    return 2*exp(a-1);
}
int log(int a)
{
    if(a == 1)
        return 0;
    return log(a/2)+1;
}


int main()
{
    double s;
    cin>>n;
    m = exp(n);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            cin>>win[i][j];
    vector<double> v(m);
    for(int i = m; i < 2*m; i++)
    {
        v[i-m] = 1;
        prob[i] = v;
        v[i-m] = 0;
    }
    for(int i = m-1; i > 0; i--)
    {
        v.clear();
        for(int a = 0; a < m; a++)
        {
            s = 0;
            for(int b = 0; b < m; b++)
            {
                s += prob[2*i][a]*prob[2*i+1][b]*win[a][b]/100+prob[2*i][b]*prob[2*i+1][a]*win[a][b]/100;
            }
            v.push_back(s);
        }
        prob[i] = v;
    }
    for(int i = 0; i < m; i++)
        v[i] = 0;
    for(int i = m; i < 2*m; i++)
    {
        pay[i] = v;
        maxpay[i] = 0;
    }
    int k;
    for(int i = m-1; i > 0; i--)
    {
        double ma = 0;
        v.clear();
        for(int a = 0; a < m; a++)
        {
            s = 0;
            k = exp(n-log(i)-1);
            s += prob[i][a]*k;
            if(prob[2*i][a] != 0)
            {
                s += pay[2*i][a]+maxpay[2*i+1];
            }
            if(prob[2*i+1][a] != 0)
            {
                s += pay[2*i+1][a]+maxpay[2*i];
            }
            v.push_back(s);
            if(s > ma)
                ma = s;
        }
        maxpay[i] = ma;
        pay[i] = v;
    }
    printf("%.9f", maxpay[1]);
    cout<<endl;
    return 0;
}