#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int tt;
    cin >> tt;
    int n, L, R;
    while(tt--) {
        cin >> n >> L >> R;
        int l = 0, r = 0;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        int ans = 0;
        ll sum = 0;
        while(r < n) {
            sum += a[r];
            if(sum >= L && sum <= R) {
                l = r+1;
                r++;
                sum = 0;
                ans++;
                continue;
            } else if(sum > R) {
                while(sum > R && l <= r) {
                    sum -= a[l];
                    l++;
                }
                if(l > r) {
                    r++;
                    continue;
                } else {
                    if(sum >= L) {
                        ans++;
                        sum=0;
                        r++;
                        l=r;
                        continue;
                    } else {
                        r++;
                    }
                }
            } else {
                r++;
            }
        }
        cout << ans << '\n';
    }
}