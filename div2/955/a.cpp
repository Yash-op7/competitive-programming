#include<bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    int a, b, c, d;
    while(tt--) {
        cin >> a >> b >> c >> d;
        if(a > b) {
            swap(a, b);
            swap(c, d);
        }
        if(c < d) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}