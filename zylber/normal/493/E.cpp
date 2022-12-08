#include <iostream>
#include <vector>
using namespace std;
typedef long long tint;

int main()
{
    tint t,a,b;
    cin >> t >> a >> b;
    
    if(a==1 || b==1)
    {
        if(a==1 && b==1){ if(t!=1) cout << 1 << endl; else cout << "inf" << endl; } else cout << 0 << endl;
        return 0;
    }
    
    int ans=0;
    if(a==b) ans++;
    
        vector<tint> base;
        tint tmp=b;
        int d=0;
        while(tmp>0)
        {
            if(tmp%a)d++;
            base.push_back(tmp%a);
            tmp/=a;
        }
        int bs=base.size();
    
    if(d>1)
    {   
        if(t>1)
        {
            tmp=a;
            for(int i=0; i<bs; ++i)
            {
                if(tmp%t!=base[i])
                {
                    cout << ans << endl;
                    return 0;
                }
                tmp/=t;
            }
            if(tmp==0) ans++;
            cout << ans << endl;
        }
        else
        {
            if(d>1)
            {
                tmp=0;
                for(int i=0; i<bs; ++i)
                {
                    tmp+=base[i];
                }
                if(tmp==a) ans++;
            }
            cout << ans << endl;
        }
    }
    else
    {
        tmp=a;
        tint c=b;
        do{
            c/=a;
            if(a%t!=0) break;
            tmp/=t;
            if(c>0 && tmp==c)
            {
                ans++;
            }
        }while(c>0);
        cout << ans << endl;
    }
}