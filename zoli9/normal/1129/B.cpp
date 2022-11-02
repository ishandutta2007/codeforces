#include <bits/stdc++.h>
using namespace std;
long long K;
long long N=2000;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>K;
    cout<<N<<endl;
    for(int i=1; i<=N-2; i++)
    {
        cout<<0<<" ";
    }
    long long mar;
    long long h=K/(N-1);
    if(K%(N-1)==0) mar=N-1;
    else mar=(h+1)*(N-1)-K;
    long long poz=(K+mar)/(N-1)+mar;
    cout<<(-mar)<<" "<<poz<<endl;
    return 0;
}