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




int main(){
    FASTIO;
    int n, m, s, f, i, j, a, b;
    char c;
    cin >> n >> m;
    vector<vector<ll>> graph(n+1);

    char map[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> c;
            map[i][j] = c;
        }
    }

    for(int i = 0, a = 0; i < ; i = i + m, a++){
        for(int j = i, b = 0; j < m; j++, b++){

            if(map[i][j] == '.' || map[i][j] == 'A' || map[i][j] == 'B'){
                if('A') s = j+i;
                if('B') f = j+i;
                if(i > 0 && i < n*(m-1)){
                    if(map[i+1][j])
                }
                else{

                }

            };
        }
    }


    // for(int i = 0; i < n; i++){
    //     for(int j = (i-V); j < i; j++){
    //         cin >> a >> b >> c >> d;
    //         if(j==0) cout << "eh zero\n";
    //         if(a) G[j][j+V] = 1;
    //         if(b) G[j][j-V] = 1;
    //         if(c) G[j][j-1] = 1;
    //         if(d) G[j][j+1] = 1;
    //     }
    // }



    return 0;
}
