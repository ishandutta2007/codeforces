#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,a;
    cin>>T;
    while (T--)
    {
        cin>>a;
        for (int i=3;;++i)
            if (a*i%180==0&&i*a<=180*(i-2))
            {
                cout<<i<<endl;
                break;
            }
    }
    return 0;
}