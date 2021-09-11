#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        k--;
        int arr[n];
        int mx = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mx = max(mx, arr[i]);
        }
        long long int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int pos = i + k;
            if (pos < n && arr[pos] == mx)
            {
                ans += (n - pos);
            }
        }
        cout << ans << endl;
    }
    return 0;
}