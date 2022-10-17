#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    int _a=abs(rand());
    int bger[30]={0,};
    int A=0,B=0;
    bool flag=false;
    int a;
    for(int i=29;i>=0;i--)
    {
        if(flag)
        {
            cout<<"? "<<(A^(1<<i))<<" "<<B<<endl;
            fflush(stdout);
            cin>>a;
            if(a==-1) {A^=(1<<i); B^=(1<<i);}
            continue;
        }

        if(bger[i]==0)
        {
            cout<<"? "<<A<<" "<<B<<endl;
            fflush(stdout);
            cin>>a;
            if(a==0) {flag=true; i++; continue;}
            bger[i]=a;
        }

        cout<<"? "<<(A^(1<<i))<<" "<<(B^(1<<i))<<endl;
        fflush(stdout);
        cin>>a;

        if(a==bger[i])
        {
            bger[i-1]=bger[i];
            cout<<"? "<<(A^(1<<i))<<" "<<B<<endl;
            fflush(stdout);
            cin>>a;
            if(a==-1) {A^=(1<<i); B^=(1<<i);}
        }

        else
        {
            if(bger[i]==1) A^=(1<<i);
            else B^=(1<<i);
        }
    }
    cout<<"! "<<A<<" "<<B<<endl;
    fflush(stdout);
    return 0;
}