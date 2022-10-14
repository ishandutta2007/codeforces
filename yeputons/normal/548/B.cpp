#include <bits/stdc++.h>

using namespace std;

int n, m;
bool t[510][510];
int s[510];

void sc(int l)
{
   s[l] = 0;
   for(int i=0, c=0; i<m; i++)
   {
      if(t[l][i])
         c++;
      else
         c = 0;
      s[l] = max(s[l], c);
   }
}

int best()
{
   int r = 0;
   for(int i=0; i<n; i++)
      r = max(r, s[i]);
   return r;
}

int main()
{
   int q;
   cin >> n >> m >> q;
   for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
         scanf("%d", &t[i][j]);
   for(int i=0; i<n; i++)
      sc(i);
   while(q--)
   {
      int l, c;
      cin >> l >> c;
      l--; c--;
      t[l][c] = !t[l][c];
      sc(l);
      cout << best() << endl;
   }
   return 0;
}