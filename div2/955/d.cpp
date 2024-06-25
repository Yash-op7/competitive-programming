#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long

int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;
 
    // Base case
    if (a == b)
        return a;
 
    // a is greater
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}
 

int main() {
    int tt;
    cin >> tt;
    int n, m, k;

    while(tt--) {
        cin >> n >> m >> k;
        vvi h(n, vi(m, 0));
        vvi c(n, vi(m, 0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin >> h[i][j];
            }
        }
        string cc;
        getline(cin, cc);
        for(int i=0;i<n;i++) {
            getline(cin, cc);
            for(int j=0;j<m;j++) {
                // cin >> c[i][j];
                c[i][j] = cc[j]-'0';
            }
        }
        vvi t(n, vi(m, 0));
        vvi pref_col(n+1, vi(m+1, 0));
        vvi pref_row(n+1, vi(m+1, 0));

        for(int j=0;j<m;j++) {
            for(int i=0;i<n;i++) {
                pref_col[i+1][j+1] = pref_col[i][j+1] + c[i][j];
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                pref_row[i+1][j+1] = pref_row[i+1][j] + c[i][j];
            }
        }
        int sum = 0;
        for(int i=0;i<k;i++) {
            sum += pref_col[k][i+1];
        }
        for(int i=k-1;i<n;i++) {
            for(int j=k-1;j<m;j++) {
                if(i == k-1 &&  j == k-1) {
                    t[i][j] = sum;
                } else {
                    if(j == k-1) {
                        t[i][j] = t[i-1][j] - (
                            pref_row[i-k+1][j+1] - pref_row[i-k+1][j-k+1]
                        ) + (
                            pref_row[i+1][j+1] - pref_row[i+1][j-k+1]
                        );
                    } else {
                        t[i][j] = t[i][j-1] - (
                            pref_col[i+1][j-k+1] - pref_col[i-k+1][j-k+1]
                        ) + (
                            pref_col[i+1][j+1] - pref_col[i-k+1][j+1]
                        );
                    }
                }
            }
        }
        ll s1 = 0, s0 = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(c[i][j] == 0) {
                    s0 += h[i][j];
                } else {
                    s1 += h[i][j];
                }
            }
        }
        ll delta = abs(s1 - s0);
        if(delta == 0) {
cout << "YES\n";
        continue;}
        bool flag = false;
        vi factors;
        for(int i=k-1;i<n;i++) {
            for(int j=k-1;j<m;j++) {
                int val = abs(t[i][j] - (k*k - t[i][j]));
                if(val== 0) continue;
                factors.push_back(val);
            }
            if(flag) break;
        }
        if(factors.empty()) {cout << "NO\n";continue;}
        int gcd1 = factors.back();
        for(int x:factors) {
            gcd1 = gcd(x, gcd1);
        }

        if(delta%gcd1 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}