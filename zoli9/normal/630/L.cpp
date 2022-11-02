#include <bits/stdc++.h>
using namespace std;
long long n;
long long k;
char a1, a2, a3, a4, a5;
long long b1, b2, b3, b4, b5;
int main()
{
    cin>>a1>>a2>>a3>>a4>>a5;
    n=10000*(a1-'0')+1000*(a3-'0')+100*(a5-'0')+10*(a4-'0')+1*(a2-'0');
    k=n;
    //cout<<n<<endl;
    n*=k;
    n%=100000;
    //cout<<n<<endl;
    n*=k;
    n%=100000;
    //cout<<n<<endl;
    n*=k;
    n%=100000;
    //cout<<n<<endl;
    n*=k;
    n%=100000;
    //cout<<n<<endl;


    b5=n%10;
    n/=10;
    b4=n%10;
    n/=10;
    b3=n%10;
    n/=10;
    b2=n%10;
    n/=10;
    b1=n%10;
    cout<<b1<<b2<<b3<<b4<<b5;



    return 0;
}