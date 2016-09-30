#include<bits/stdc++.h>
#define endl '\n'
#define needforspeed ios_base::sync_with_stdio (false);cin.tie();
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
#define ms(a,b) memset( (a), (b), sizeof( (a) ) )
#define xx first
#define yy second
#define LL long long
#define DB 0
#define MAXN 5000050
#define inf 0x3f3f3f3f
using namespace std;

int main()
{
    freopen("different_input.txt","r",stdin);
    LL a,b;
    needforspeed;
    while(cin >> a >> b)
        cout << abs(a-b) << endl; 
    return 0;
}
