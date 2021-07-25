#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 3 == 0)
            cout << n / 3 << " " << n / 3 << endl;
        else if (n % 3 == 1)
        {
            int c1 = (n + 2) / 3;
            int c2 = (n - c1) / 2;
            cout << c1 << " " << c2 << endl;
        }
        else
        {
            int c2 = ((n + 1) / 3);
            int c1 = n - 2 * c2;
            cout << c1 << " " << c2 << endl;
        }
    }
    return 0;
}