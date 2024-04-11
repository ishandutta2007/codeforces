#include <bits/stdc++.h>

using namespace std;

const int N=128;

int co[N];
int od,n;
string s;

int can(int x)
{
	return (x-od)%2==0;
}

void build(int x)
{
	string mids,ss;
	for(int i=0;i<N;i++)
	{
		if(co[i]%2) {mids+=i; co[i]--;}
	}
	for(int i=0;i<N&&mids.size()<n/x;i++)
	{
		while(co[i]>=2&&mids.size()<n/x)
		{
			co[i]-=2; mids+=i; mids+=i;
		}
	}
	//cout << mids << endl;
	for(int i=0;i<N;i++)
	{
		ss+=string(co[i]/2,i);
	}
	cout << n/x << endl;
	int len=x/2;
	for(int i=0;i<n/x;i++)
	{
		string cur=ss.substr(i*len,len);
		string rcur=cur;
		reverse(rcur.begin(),rcur.end());
		cur+=mids[i];
		cur+=rcur;
		cout << cur << " ";
	}
	cout << endl;
}

int main()
{
	cin >> n >> s;
	for(int i=0;i<n;i++)
		co[s[i]]++;
	for(int i=0;i<N;i++)
		od+=co[i]%2;
	if(od==0)
	{
		string ans="";
		for(int i=0;i<N;i++)
			ans+=string(co[i]/2,i);
		string rans=ans;
		reverse(rans.begin(),rans.end());
		cout << 1 << endl << ans+rans << endl;
		return 0;
	}
	for(int i=n;i>=1;i--)
	{
		if(n%i==0&& n/i>=od && i%2)
		{
			//cout << i << " " << can(i) << endl;
			if(can(n/i))
			{
				build(i);
				return 0;
			}
		}
	}

}