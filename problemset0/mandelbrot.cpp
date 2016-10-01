#include<bits/stdc++.h>

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
