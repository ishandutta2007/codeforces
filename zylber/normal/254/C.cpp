#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

string s,t;
int ls[26], lt[26];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    memset(ls,0,sizeof(ls));
    memset(lt,0,sizeof(lt));
    cin >> t >> s;
    int N = s.size();
    int ans = 0;

    for(int i=0; i<N; i++)
    {
        ls[s[i]-'A']++;
        lt[t[i]-'A']++;
    }

    for(int i=0; i<26; i++)
        ans+=max(0,ls[i]-lt[i]);

    cout << ans << endl;

    for(int i=0; i<N; i++)
    {
        int code=t[i]-'A';
        if(lt[code]>ls[code])
        {
            int top=27;
            if(ls[code])
                top = code;

            for(int j=0; j<top; j++)
                if(ls[j]>lt[j])
                    top = j;

            t[i] = top+'A';

            if(top == code)
            {
                lt[code]--;
                ls[code]--;
            }
            else
            {
                lt[code]--;
                lt[top]++;
            }
        }
    }
    cout << t << endl;
}