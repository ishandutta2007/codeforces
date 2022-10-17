#include <iostream>

using namespace std;

int gcd(int x,int y) {return (y?gcd(y,x%y):x);}

int num_of_divisor(int x)
{
    int ans=1;
    for(int i=2;i*i<=x;i++)
    {
        int cnt=1;
        while(!(x%i)) {cnt++; x/=i;}
        ans*=cnt;
    }
    if(x!=1) ans*=2;
    return ans;
}

int main()
{
    int T; cin>>T;
    while(T--)
    {
        int a,b,c; cin>>a>>b>>c;
        int ab=gcd(a,b); int bc=gcd(b,c); int ca=gcd(c,a);
        int abc=gcd(ab,bc);
        int x=num_of_divisor(a);
        int y=num_of_divisor(b);
        int z=num_of_divisor(c);
        int xy=num_of_divisor(ab);
        int yz=num_of_divisor(bc);
        int zx=num_of_divisor(ca);
        int xyz=num_of_divisor(abc);
        cout<<(x*y*z-xy*(xy-1)*z/2-yz*(yz-1)*x/2-zx*(zx-1)*y/2-(xy-xyz)*(yz-xyz)*(zx-xyz)+2*xyz*(xyz-1)*(xyz-2)/3+xyz*(xyz-1)*(xy+yz+zx-3*xyz+2)/2)<<endl;
    }
    return 0;
}