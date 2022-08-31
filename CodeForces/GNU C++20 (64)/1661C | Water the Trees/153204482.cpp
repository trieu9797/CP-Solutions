/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you spy
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 3e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N], dp[N];
 
void solve()
{
    int n, ma = 0; cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        ma = max(ma, a[i]);
    }
    int l = -1, r = 3e14 + 2;
    while (l + 1 < r){
        int mid = (l + r) >> 1;
        int pl = (mid + 1) >> 1, pr = mid - pl;
        bool f = false;
        for(int m = ma; m <= ma + 1; ++m){
            int p1 = pl, p2 = pr, le = 0;
            for(int i = 1; i <= n; ++i){
                int g = (m - a[i]) / 2;
                int de = min(p2, g);
                p2 -= de;
                le += (m - a[i] - 2 * de);
            }
            if (p1 >= le) f = true;
        }
        if (f) r = mid;
        else l = mid;
    }
    cout << r << endl;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("codeforces.inp","r",stdin);
    // freopen("codeforces.out","w",stdout);
 
    int t = 1;  cin >> t;
    while (t--)
    {
        solve();
    }
}