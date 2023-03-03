#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(ll i = (a); i < (ll)(b); ++i)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define sz(x) (ll)x.size()
#define MOD 1000000007ll
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS 1e-9
#define DEG2RAD(d) (d)*M_PI / 180.0
#define RAD2DEG(r) (r)*180.0 / M_PI

struct Ponto {
    double x, y;
    Ponto(double _x = 0, double _y = 0):x(_x),y(_y){}
    Ponto operator-(const Ponto &p) const {
        return Ponto(x - p.x, y - p.y);
    }
    Ponto operator*(double k) const {
        return Ponto(x*k, y*k);
    }
    bool operator<(const Ponto &p) const {
        if (fabs(x - p.x) > EPS) return x < p.x;
        return y < p.y;
    }
    bool operator==(const Ponto &p) const {
        return (fabs(x - p.x) < EPS) && (fabs(y - p.y) < EPS);
    }

};

// Retorna o produto vetorial de 'p1' e 'p2'
double cross(const Ponto &p1, const Ponto &p2) {
    return p1.x*p2.y - p1.y*p2.x;
}

// Verifica se o ponto 'r' está no lado esquerdo da linha 'pq'
bool ttleft(const Ponto &p, const Ponto &q, const Ponto &r) {
    return cross(q-p, r-p) > 0;
}
bool ttright(const Ponto &p, const Ponto &q, const Ponto &r) {
    return cross(q-p, r-p) < 0;
}

// Verifica se o ponto 'r' está na mesma linha que a linha 'pq'
bool colinear(const Ponto &p, const Ponto &q, const Ponto &r) {
    return fabs(cross(p-q, r-p)) < EPS;
}

int main(){
    FASTIO;
    ll t, x1, y1, x2, y2, x3, y3;
    cin >> t;

    for(ll i = 0; i < t; i++){
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        if(ttleft(Ponto(x1, y1), Ponto(x2, y2), Ponto(x3, y3))) cout << "LEFT" << endl;
        else if(ttright(Ponto(x1, y1), Ponto(x2, y2), Ponto(x3, y3))) cout << "RIGHT" << endl;
        else if(colinear(Ponto(x1, y1), Ponto(x2, y2), Ponto(x3, y3))) cout << "TOUCH" << endl;
    }
    return 0;
}