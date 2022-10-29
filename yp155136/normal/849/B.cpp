#include <bits/stdc++.h>
using namespace std;

const int N = 1006;

int y[N];

bool used[N];

int main ()
{
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&y[i]);
    }
    for (int i=1;2>=i;i++)
    {
        for (int j=i+1;n>=j;j++)
        {
            //one line contains points (i,y[i]), (j,y[j])
            vector<int> v;
            for (int k=1;n>=k;k++)
            {
                if (i==k || j==k)
                {
                    ;
                    //v.push_back(k);
                }
                else if ((y[j]-y[i])*1LL*(k-i) == (y[k]-y[i])*1LL*(j-i))
                {
                    ;
                }
                else
                {
                    v.push_back(k);
                }
            }
            if (v.size() == 0) continue;
            if (v.size() == 1)
            {
                puts("Yes");
                return 0;
            }
            bool flag=true;
            //for (int i:v) cout << i<<' ';
            //cout << "i = "<<i<<" , j = "<<j<<endl;
            for (int k=1;v.size()>k;k++)
            {
                if ((y[j]-y[i])*1LL*(v[k]-v[0]) == (y[ v[k] ] - y[ v[0] ])*1LL*(j-i))
                {
                    //flag=false;
                    //break;
                }
                else
                {
                    flag = false;
                    break;
                    //flag=true;
                }
            }
            //cout << "result is "<<flag<<endl;
            if (flag)
            {
                puts("Yes");
                return 0;
            }
        }
    }
    puts("No");
    return 0;
}