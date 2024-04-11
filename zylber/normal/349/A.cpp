#include <iostream>
#include <cstring>
using namespace std;

int cant[5];

int main()
{
    int n;
    cin >> n;
    memset(cant,0,sizeof(cant));
    int can=1;
    for(int i=0; i<n; i++)
    {
        int act;
        cin >> act;
        
        act/=25;
        int pay=act-1, it=2;
        
        while(pay>0 && it>0)
        {
            it=min(pay,it);
            if(cant[it]){ pay-=it; cant[it]--; } else {it--;}
        }
        
        if(it==0) { cout << "NO" << endl; can=0; break;}
        cant[act]++;
    }
    
    if(can) cout << "YES" << endl;
}