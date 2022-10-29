#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> piii;

#define F first
#define S second;

bool dp[1006][2022];

int par[1006][2022];

string s[1006];

int to_int(string s)
{
    int ret=0;
    for (char i:s)
    {
        ret*=10;
        ret+=(i-'0');
    }
    return ret;
}

int main ()
{
    int n;
    cin >> n;
    for (int i=1;n>=i;i++)
    {
        cin >> s[i];
    }
    if (n == 1)
    {
        cout << 1 << s[1][1] << s[1][2] << s[1][3] << endl;
        //cout << s[1] <<endl;
        return 0;
    }
    for (int i=1;n>=i;i++)
    {
        if (i == 1)
        {
            if (to_int(s[i]) <= 2011) dp[i][ to_int(s[i]) ] = true;
            for (int x=0;4>x;x++)
            {
                for (int y='0';'9'>=y;y++)
                {
                    if (x == 0 && y == '0') continue;
                    string ss=s[i];
                    ss[x] = y;
                    if (to_int(ss) <= 2011) dp[i][ to_int(ss) ] = true;
                }
            }
        }
        else
        {
            vector<int> nums;
            if (to_int(s[i]) <= 2011) par[i][ to_int(s[i]) ] = -1;  //nums.push_back(to_int(s[i]));
            for (int x=0;4>x;x++)
            {
                for (int y='0';'9'>=y;y++)
                {
                    if (x == 0 && y == '0') continue;
                    string ss=s[i];
                    ss[x] = y;
                    if (to_int(ss) <= 2011)par[i][ to_int(ss) ] = -1;
                    //if (to_int(ss) <= 2011) nums.push_back(to_int(ss));
                }
            }
            int pre = 0;
            int gee = 0;
            for (int j=1000;2011>=j;j++)
            {
                //pre |= dp[i-1][j];
                if (dp[i-1][j]) pre = j;
                if(par[i][j] == -1)
                {
                    if (pre)
                    {
                        par[i][j] = pre;
                        dp[i][j] = true;
                        gee = j;
                    }
                    else
                    {
                        par[i][j] = 0;
                    }
                }
            }
            //cout << "i = " << i << " , gee = " <<gee<<endl;
            if (i == n)
            {
                if (!gee)
                {
                    puts("No solution");
                }
                else
                {
                    int now=gee;
                    vector<int> ans;
                    int nowi = i;
                    while (gee != 0)
                    {
                        ans.push_back(gee);
                        gee = par[nowi][gee];
                        --nowi;
                    }
                    reverse(ans.begin(),ans.end());
                    for (int i:ans)
                    {
                        printf("%d\n",i);
                    }
                }
                return 0;
            }
        }
    }
}