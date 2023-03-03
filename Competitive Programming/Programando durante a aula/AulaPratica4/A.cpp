#include <bits/stdc++.h>
using namespace std;


typedef long long  ll;
typedef vector<ll> vll;

#define lsb(i) ((i) & -(i))
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


class  FenwickTree {
private:
    vll ft;
public:
    FenwickTree(ll m) { ft.resize(m + 1, 0); }
    FenwickTree(const vll &a) { build(a); }

    ll sum(ll i) {
        ll s = 0;
        while (i >= 1) {
            s += ft[i];
            i -= lsb(i);
        }
        return s;
    }
    ll sum(ll a, ll b) {
        return sum(b) - sum(a-1);
    }

    void add(ll i, ll x) {
        while (i < (ll)ft.size()) {
            ft[i] += x;
            i += lsb(i);
        }
    }

    void build(const vll& a) {
        ll m = (ll)a.size() - 1;
        ft.resize(m + 1, 0);
        for (ll i = 1; i <= m; i++) {
              ft[i] += a[i];
              if (i + lsb(i) <= m)
                  ft[i + lsb(i)] += ft[i];
        }
    }
};


int main(){
    FASTIO;
    ll a, b, k, n, q, x;
    cin >> n >> q;
    vll v(n+1);
    v[0] = 0;
    for(int i = 1; i <= n; i++){cin >> x; v[i] = x;}
    FenwickTree ft(v);
    
    for(int i = 0; i < q; i++){
        cin >> k >> a >> b;
        if(k==1){
            x = b - v[a];
            ft.add(a, x);
            v[a] = b;
        }
        else if(k==2) cout << ft.sum(a, b) << "\n";
    }
    return 0;
}