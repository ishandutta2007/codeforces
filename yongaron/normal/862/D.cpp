#include <iostream>
#include <cstdio>

using namespace std;

int n;
int l, p, jed, nul;
int pNula = 0, pJedna = 0;
bool c;

int main()
{
    int x, del, jed2, nul2;
    cin>>n;
    c = true;
    l = 1; p = n;
    cout<<"? ";
    for(int i = 0; i < n; i++)
        cout<<1;
    cout<<endl;
    fflush(stdout);
    cin>>nul;
    jed = n-nul;
    del = n/2;
    jed2 = jed;
    nul2 = nul;
    //cout<<nul<<" "<<jed<<endl;
    int jed3, nul3;
    while(c)
    {
        cout<<"? ";
        for(int i = 1; i <= del; i++)
            cout<<0;
        for(int i = del+1 ; i <= p; i++)
            cout<<1;
        for(int i = p+1; i <= n; i++)
            cout<<0;
        cout<<endl;
        fflush(stdout);
        cin>>x;
        x -= jed;
        x = -x;
        jed3 = (p+x-del)/2;
        nul3 = jed3-x;
        //cout<<nul3<<" "<<jed3<<endl;
        if(nul2-nul3 == 0)
        {
            pJedna = del;
            l = del+1;
            nul2 = nul3;
            jed2 = jed3;
        }
        else if(jed2-jed3 == 0)
        {
            pNula = del;
            l = del+1;
            nul2 = nul3;
            jed2 = jed3;
        }
        if(jed3 == 0)
        {
            pNula = del+1;
            p = del;
            nul2 = nul2-nul3;
            jed2 = jed2-jed3;
        }
        else if(nul3 == 0)
        {
            pJedna = del+1;
            p = del;
            nul2 = nul2-nul3;
            jed2 = jed2-jed3;
        }
        else
        {
            l = del+1;
            nul2 = nul3;
            jed2 = jed3;
        }
        //cout<<pNula<<" "<<pJedna<<endl;
        del = (p+l)/2;
        if(pJedna && pNula)
            break;
    }
    cout<<"! "<<pNula<<" "<<pJedna;
    fflush(stdout);
    return 0;
}