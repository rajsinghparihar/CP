#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    bool flag = false;
    int arr[14] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
    for (int x : arr)
    {
        if (n % x == 0)
        {
            cout << "YES" << endl;
            flag = true;
            break;
        }
        else
        {
            flag = false;
        }
    }
    if (!flag)
        cout << "NO" << endl;
    return 0;
}