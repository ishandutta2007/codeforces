#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first	
#define se second
#define pb push_back
#define mp make_pair
 
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
int digits(int x)
{
	if(x < 0) return 0;
	if(x == 0) return 1;
	int cnt = 0;
	while(x)
	{
		x /= 10;
		cnt++;
	}
	return cnt;
}
 
int ma[10];
 
string ans;
 
void insertchar(int m)
{
	char c = m + '0';
	ans.append(" ");
	ans[ans.length() - 1] = c;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string number;
	string sub;
	cin >> number;
	for(int i = 0; i < number.length(); i++)
	{
		ma[number[i] - '0']++;
	}
	cin >> sub;
	int n = int(number.length());
	int d = 0;
	for(int i = 1; i <= 6; i++)
	{
		if(digits(n - i) == i)
		{
			d = n - i;
		}
	}
	//if(number == "01" || number == "10") cout << 0;
	while(d)
	{
		ma[d%10]--;
		d /= 10;
	}
	for(int i = 0; i < sub.length(); i++)
	{
		ma[sub[i] - '0']--;
	}
	if(sub[0] == '0')
	{
		for(int i = 1; i <= 9; i++)
		{
			if(ma[i])
			{
				insertchar(i);
				ma[i]--;
				break;
			}
		}
		while(ma[0])
		{
			insertchar(0);
			ma[0]--;
		}	
		for(int i = 0; i < sub.length(); i++)
		{
			insertchar(sub[i] - '0');
		}
		for(int i = 1; i <= 9; i++)
		{
			while(ma[i])
			{
				insertchar(i);
				ma[i]--;
			}
		}
	}
	else
	{
		int substart = sub[0] - '0';
		bool exist = false;
		bool larger = false;
		for(int i = 1; i < sub.length(); i++)
		{
			if((sub[i] - '0') != (sub[0] - '0'))
			{
				if((sub[i] - '0') > (sub[0] - '0')) larger = true;
				break;
			}
		}
		for(int i = 1; i < substart; i++)
		{
			if(ma[i])
			{
				insertchar(i);
				ma[i]--;
				exist = true;
				break;
			}
		}
		if(!exist)
		{
			//all digits are either 0 or >= d
			string a1,a2;
			a2+=sub;
			int tmp[10];
			for(int i=0;i<10;i++) tmp[i]=ma[i];
			for(int i=0;i<10;i++)
			{
				while(ma[i]){ma[i]--; a2+=char('0'+i);}
			}
			for(int i=0;i<10;i++) ma[i]=tmp[i];
			bool ex=0;
			for(int i=1;i<10;i++)
			{
				if(ma[i])
				{
					ma[i]--; a1+=char('0'+i); ex=1; break;
				}
			}
			if(ex)
			{
				for(int i = 0; i < substart; i++)
				{
					while(ma[i])
					{
						ma[i]--;
						a1+=char('0'+i);
					}
				}
				
				if(larger)
				{
					while(ma[substart]){ma[substart]--;  a1+=char('0'+substart);}
					a1+=sub;
					for(int i=0;i<10;i++)
					{
						while(ma[i]){ma[i]--;  a1+=char('0'+i);}
					}
				}
				else
				{
					a1+=sub;
					for(int i=0;i<10;i++)
					{
						while(ma[i]){ma[i]--;  a1+=char('0'+i);}
					}
				}
				ans = min(a1,a2);
			}
			else ans=a2;
			cout<<ans<<'\n'; return 0;
		}
		
		for(int i = 0; i < substart; i++)
		{
			while(ma[i])
			{
				ma[i]--;
				insertchar(i);
			}
		}
		
		if(larger)
		{
			while(ma[substart]){ma[substart]--; insertchar(substart);}
			ans+=sub;
			for(int i=0;i<10;i++)
			{
				while(ma[i]){ma[i]--; insertchar(i);}
			}
		}
		else
		{
			ans+=sub;
			for(int i=0;i<10;i++)
			{
				while(ma[i]){ma[i]--; insertchar(i);}
			}
		}
	}
	cout << ans;
	return 0;
}