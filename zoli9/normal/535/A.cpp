#include <iostream>
using namespace std;
int n, nn, a, b;
string t1[15];
string t2[15];
string spec[100];
int main()
{
    cin>>n;
    nn=n;
    b=n%10;
    n=n-b;
    n=n/10;
    a=n;
    t1[0]="zero";
    t1[1]="one";
    t1[2]="two";
    t1[3]="three";
    t1[4]="four";
    t1[5]="five";
    t1[6]="six";
    t1[7]="seven";
    t1[8]="eight";
    t1[9]="nine";
    t1[10]="ten";
    if(nn<=10)
    {
        cout<<t1[nn];
        return 0;
    }
    spec[10]="ten";
    spec[11]="eleven";
    spec[12]="twelve";
    spec[13]="thirteen";
    spec[14]="fourteen";
    spec[15]="fifteen";
    spec[16]="sixteen";
    spec[17]="seventeen";
    spec[18]="eighteen";
    spec[19]="nineteen";

    t2[2]="twenty";
    t2[3]="thirty";
    t2[4]="forty";
    t2[5]="fifty";
    t2[6]="sixty";
    t2[7]="seventy";
    t2[8]="eighty";
    t2[9]="ninety";

    if(nn<20)
    {
        cout<<spec[nn];
        return 0;
    }

    cout<<t2[a];
    if(b==0)
    {
        return 0;
    }
    cout<<"-"<<t1[b];
    return 0;
}