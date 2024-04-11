#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int N = 128;

struct matrix {
  // N is the size of the matrix
  ld m[N][N];
  matrix()
  {
     memset(m,0,sizeof(m));
  }
  matrix operator * (matrix b)
  {
     matrix c = matrix();
     for (int i = 0; i < N; ++i)
     {
       for (int j = 0; j < N; ++j)
       {
         for (int k = 0; k < N; ++k) 
         {
           c.m[i][j] = c.m[i][j] + (m[i][k] * b.m[k][j]);
         }
        }
    }
     return c;
  }
};

matrix unit;
matrix magic;

matrix modPow(matrix m,int n)
{
  if ( n == 0 )
    return unit; // the unit matrix - that is 1 for principal diagonal , otherwise 0
  matrix half = modPow(m,n/2);
  matrix out = half * half;
  if ( n % 2 )
    out = out * m;
  return out; 
}

ld p[N];
matrix tmp;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
	for(int i = 0; i <= k; i++)
	{
		cin >> p[i];
	}
	for(int i = 0; i < N; i++)
	{
		unit.m[i][i] = 1;
	}
	for(int i = 0; i < N; i++)
	{
	    for(int j = 0; j < N; j++)
	    {
	        magic.m[i][j] = p[(i^j)];
	    }
	}
	tmp = modPow(magic, n - 1);
	ld ans = 0;
	for(int i = 0; i < N; i++)
	{
		ans += tmp.m[0][i]*p[i];
	}
	ans = 1 - ans;
	cout << fixed << setprecision(15) << ans << '\n';
}