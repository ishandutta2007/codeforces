#include <iostream>

using namespace std;

int main()
{
    int times; cin>>times;
    while(times--)
    {
        int n; cin>>n;
        char c[n]; for(int i=0;i<n;i++) cin>>c[i];
        bool check=true;
        for(int i=0;i<n/2;i++)
        {
            int k=(int)c[i]-(int)c[n-i-1];
            if(k==2||k==0||k==-2) continue;
            check=false; break;
        }
        check?(cout<<"YES"):(cout<<"NO");
        cout<<endl;
    }
    return 0;
}