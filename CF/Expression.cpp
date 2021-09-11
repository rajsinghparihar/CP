#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;
    int br1[4];
    int br2[4];

    for (int i = 0; i < 4; i++)
    {
        br1[i] = 0;
        br2[i] = 0;
    }

    // ++, +*, *+, **
    //  0,  1,  2,  3

    br1[0] = (a + b) + c;
    br1[1] = (a + b) * c;
    br1[2] = (a * b) + c;
    br1[3] = (a * b) * c;

    br2[0] = a + (b + c);
    br2[1] = a + (b * c);
    br2[2] = a * (b + c);
    br2[3] = a * (b * c);

    int ans = INT_MIN;
    for (int i = 0; i < 4; i++)
    {
        ans = max(ans, br1[i]);
        ans = max(ans, br2[i]);
    }
    cout << ans << endl;
    return 0;
}