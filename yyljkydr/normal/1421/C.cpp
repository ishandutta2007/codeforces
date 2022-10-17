#include<bits/stdc++.h>
using namespace std;

const int N=1e3+1e2+7;

int T,n;

char s[N][N];

int b[2][N][N];

vector<pair<int,int> >ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	int n=s.size();
	cout<<3<<endl;
	cout<<"R "<<n-1<<endl;
	cout<<"L "<<n<<endl;
	cout<<"L "<<2<<endl;
}