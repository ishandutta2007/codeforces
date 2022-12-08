#include <iostream>
using namespace std;

double pow(double x, int y)
{
    if(y==0) return 1;
    double ans=pow(x,y/2);
    ans*=ans;
    if(y%2) ans*=x;
    return ans;
}

int main()
{
    double res=0;
    int n; double m;
    cin >> m >> n;
    for(int i=1; i<=m; i++)
        res+=i*(pow(i/m,n)-pow((i-1)/m,n));
    
    cout << res << endl;
}