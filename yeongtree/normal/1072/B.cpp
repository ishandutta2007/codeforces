#include <iostream>

using namespace std;

bool f(int*,int*,int,int[][4],int,int);

int main()
{
    int n; cin>>n;
    int a[n-1],b[n-1];
    for(int i=0;i<n-1;i++) cin>>a[i];
    for(int i=0;i<n-1;i++) cin>>b[i];
    int check[n][4];
    for(int i=0;i<n;i++){for(int j=0;j<4;j++) check[i][j]=-1;}
    bool flag=false;
    for(int i=0;i<4;i++)
    {
        if(f(a,b,n,check,0,i))
        {
            flag=true;
            cout<<"YES"<<endl;
            int ans=i;
            for(int j=0;j<n-1;j++)
            {
                cout<<ans<<" ";
                ans=check[j][ans];
            }
            cout<<ans;
            break;
        }
    }
    if(!flag) cout<<"NO";
    return 0;
}

bool f(int* _a,int* _b,int _n,int(*check)[4],int k,int t)
{
    if(check[k][t]!=-1) return false;
    if(k==_n-1) return true;
    check[k][t]=0;
    bool _flag=false;
    for(int i=0;i<4;i++)
    {
        if(((t|i)!=_a[k])||((t&i)!=_b[k])) continue;
        if(f(_a,_b,_n,check,k+1,i))
        {
            check[k][t]=i;
            _flag=true;
            break;
        }
    }
    return _flag;
}