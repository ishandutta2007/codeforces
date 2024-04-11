#include <iostream>
using namespace std;
int a, b, c, d;
bool aa, bb, cc, dd;
string s;
int main()
{
    cin>>s;
    a=s.length()-2;
    cin>>s;
    b=s.length()-2;
    cin>>s;
    c=s.length()-2;
    cin>>s;
    d=s.length()-2;

    if( (a>=2*b and a>=2*c and a>=2*d) or (a*2<=b and a*2<=c and a*2<=d)) aa=true;
    if( (b>=2*a and b>=2*c and b>=2*d) or (b*2<=a and b*2<=c and b*2<=d)) bb=true;
    if( (c>=2*b and c>=2*a and c>=2*d) or (c*2<=b and c*2<=a and c*2<=d)) cc=true;
    if( (d>=2*b and d>=2*c and d>=2*a) or (d*2<=b and d*2<=c and d*2<=a)) dd=true;
    int db=0;
    if(aa) db++;
    if(bb) db++;
    if(cc) db++;
    if(dd) db++;
    if(db==1)
    {
        if(aa) cout<<"A";
        if(bb) cout<<"B";
        if(cc) cout<<"C";
        if(dd) cout<<"D";
    }
    else
    {
        cout<<"C";
    }
    return 0;
}