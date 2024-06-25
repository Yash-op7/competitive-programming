#include<bits/stdc++.h>
using namespace std;

int f(int x, int y, int k) {
    if(x < y) {
        int req = y - x;
        if(k >= req) {
            k-=req;
            return 1 + k%(y-1);
        } else {
            return x + k;
        }
    } else {
        int req = y - (x%y);
        if(k < req) {
            return x+k;
        } else {
            k -= req;
            x += req;
            while(x % y == 0) x/=y;
            return f(x, y, k);
        }
    }
}

int main() {
    int tt;
    cin >> tt;
    int x, y, k;
    while(tt--) {
        cin >> x >> y >> k;
        cout << f(x, y, k) << '\n';
    }
}