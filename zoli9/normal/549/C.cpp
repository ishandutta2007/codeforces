#include <iostream>
using namespace std;
int n, k;
int evens, odds, lepes, kor;
int main()
{
    cin>>n>>k;
    evens=0;
    odds=0;
    for(int i=1; i<=n; i++)
    {
        int a;
        cin>>a;
        if(a%2==0)
        {
            evens++;
        }
        else
        {
            odds++;
        }
    }

    lepes=n-k;
    if(lepes==0)
    {
        if(odds%2==0)
        {
            cout<<"Daenerys";
                return 0;
        }
        else
        {
            cout<<"Stannis";
                return 0;
        }
    }
    if(lepes%2==0)
    {
        kor=lepes/2;
        if(odds>kor and evens>kor)
        {
            cout<<"Daenerys";
            return 0;
        }
        if(odds<=kor)
        {
            cout<<"Daenerys";
            return 0;
        }
        if(evens<=kor)
        {
            if(k%2==0)
            {
                cout<<"Daenerys";
                return 0;
            }
            else
            {
                cout<<"Stannis";
                return 0;
            }
        }
    }
    else
    {
        kor=(lepes-1)/2;
        if(odds>kor and evens>kor)
        {
            cout<<"Stannis";
            return 0;
        }
        if(odds<=kor)
        {
            cout<<"Daenerys";
            return 0;
        }
        if(evens<=kor)
        {
            if(k%2==0)
            {
                cout<<"Daenerys";
                return 0;
            }
            else
            {
                cout<<"Stannis";
                return 0;
            }
        }
    }
    return 0;
}