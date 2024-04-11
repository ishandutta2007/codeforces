#include <iostream>

using namespace std;

int main()
{
    int d,n; cin>>n>>d;
    int m; cin>>m;
    int x[m],y[m];
    for(int i=0;i<m;i++) cin>>x[i]>>y[i];
    for(int i=0;i<m;i++)
    {
        int a=x[i]; int b=y[i];
        if((a+b)<=(2*n-d)&&(a+b)>=d&&(a-b)<=d&&(a-b)>=(-d)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}