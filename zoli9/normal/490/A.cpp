#include <iostream>
using namespace std;
int n;
int a;
int x1, x2, x3;
int t1[5001];
int t2[5001];
int t3[5001];
int main()
{
    cin>>n;
    x1=0;
    x2=0;
    x3=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a;
        if(a==1)
        {
            x1++;
            t1[x1]=i;
        }
        if(a==2)
        {
            x2++;
            t2[x2]=i;
        }
        if(a==3)
        {
            x3++;
            t3[x3]=i;
        }
    }
    int q=min(x1, min(x2, x3));
    cout<<q<<endl;
    for(int i=1; i<=q; i++)
    {
        cout<<t1[i]<<" "<<t2[i]<<" "<<t3[i]<<endl;
    }



    return 0;
}