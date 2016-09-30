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
#define MAXN 1005
#define inf 0x3f3f3f3f
using namespace std;


int main()
{
    freopen("mandelbrot_input.txt","r",stdin);
    double x, y, R;
    for(int i = 1;cin >> x >> y >> R;i++)
    {
        complex<double>zn(0,0), zn1(0,0);
        bool diverge = false;
        for(int j = 0;j < R;j++)
        {
            zn1 = zn*zn + complex<double>(x,y); 
            zn = zn1;
            if(abs(zn) > 2)
            {
                diverge = true;
            }
        } 
        printf("Case %d: %s\n", i, diverge ? "OUT":"IN");
    }
    return 0;
}
