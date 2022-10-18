#include <bits/stdc++.h>
using namespace std;

int n, m, s[2001], q;
string a, b;
int main()
{
//	freopen("a.out","w",stdout);
	cin>>n>>m>>q;
    cin>>a>>b;
    for(int i=0; i<=n-m; ++i)
    {
        int y=1;
        if(a.substr(i , m) != b) y = 0;
        s[i+m]=y;
    }
    for(int i=1; i<=n+m; ++i) s[i]+=s[i-1];
    for(int i=1; i<=q; ++i)
    {
        int l, r;
        cin>>l>>r;
//        cout<<l+m-1<<" "<<r<<endl;
        cout<<max(0,s[r]-s[l+m-2])<<endl;
//        cerr << r << "  " << l + m -  2<< endl; 
    }
    return 0;
}