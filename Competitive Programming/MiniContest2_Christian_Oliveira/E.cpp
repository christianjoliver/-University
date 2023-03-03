#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

#define filhoEsq(i) (2*(i) + 1)
#define filhoDir(i) (2*(i) + 2)

class SegTree {
    private:
        vll st, lazy;
        vector<bool> marked;
        ll size;
        ll funcao(ll a, ll b) {
            return a + b;
        }

        void propagate(ll p, ll L, ll R) {
            if (marked[p]) {
                st[p] += lazy[p] * (R - L + 1);
                if (L != R) {
                    lazy[filhoDir(p)] = lazy[filhoEsq(p)] += lazy[p];
                    marked[filhoDir(p)] = marked[filhoEsq(p)] = true;
                }
                marked[p] = false;
                lazy[p] = 0;
            }
        }

        ll query(ll no, ll tl, ll tr, ll l, ll r){
            propagate(no, tl, tr);
            if(tr < l || r < tl)
                return 0;

            if(tl >= l and tr <= r)
                return st[no];

            ll m = tl + (tr - tl) / 2;
            return funcao(query(filhoEsq(no), tl, m, l, r), query(filhoDir(no), m + 1, tr, l, r));
        }

        void update(ll no, ll tl, ll tr, ll l, ll r, ll novoValor){
            propagate(no, tl, tr);
            if (tl >= l && tr <= r) {
                lazy[no] += novoValor;
                marked[no] = true;
                propagate(no, tl, tr);
                return;
            }

            if (tl > r || tr < l)
                return;

            ll m = tl + (tr - tl) / 2;
            update(filhoEsq(no),    tl,  m, l, r, novoValor);
            update(filhoDir(no), m + 1, tr, l, r, novoValor);
            st[no] = funcao(st[filhoEsq(no)], st[filhoDir(no)]);
        }

        void build(ll no, ll L, ll R, const vll &A) {

            if (L == R)
                st[no] = A[L];
            else {
                ll m = L + (R - L) / 2;
                build(filhoEsq(no),     L, m, A);
                build(filhoDir(no), m + 1, R, A);
                st[no] = funcao(st[filhoEsq(no)], st[filhoDir(no)]);
            }
        }

    public:
        SegTree(ll n) : st(4 * n, 0), lazy(4 * n, 0), marked(4 * n, false), size(n) {}
        SegTree(const vll &a) {
            size = a.size();
            st.resize(4 * size, 0);
            lazy.resize(4 * size, 0);
            marked.resize(4 * size, false);
            build(0, 0, size - 1, a);
        }
        ll query(ll l, ll  r) {
            return query(0, 0, size - 1, l, r);
        }
        void update(ll i, ll x){
            update(0, 0, size - 1, i, i, x);
        }
        void update(ll l, ll r, ll x){
            update(0, 0, size - 1, l, r, x);
        }
};


int main(){
    FASTIO;
    ll a, b, n, q, c, u, x;
    cin >> n >> q;
    vll v(n);
    for(ll i = 0; i < n; i++){cin >> x; v[i] = x;}
    SegTree st(v);

    for(ll i = 0; i < q; i++){
        cin >> c >> a;
        if(c==1){
            cin >> b >> u;
            st.update(a-1, b-1, u);
        }
        else if(c==2) cout << st.query(a-1, a-1) << "\n";
    }
    return 0;
}