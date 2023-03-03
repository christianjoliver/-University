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

vll aux;
void preProcessing(string pattern){
    aux.resize(pattern.size());
    aux[0] = 0;
    ll i = 1, j = 0;

    while(i < pattern.size()){
        if(pattern[i]==pattern[j]){
            j++;
            aux[i] = j;
            i++;
        }
        else{
            if(j) j = aux[j-1];
            else{ aux[i] = 0; i++; }
        }
    }
}

void myKMP(string txt, string pattern){
    
    ll itxt = 0, ipatt = 0, qnt = 0;

    while(itxt < txt.size()){
        if(pattern[ipatt] == txt[itxt]){
            itxt++;
            ipatt++;
        }
        if(ipatt == pattern.size()){ 
            ipatt = aux[ipatt-1];
            qnt++; 
        }
        if(itxt < txt.size() && pattern[ipatt] != txt[itxt]){
            if(ipatt) ipatt = aux[ipatt-1];
            else itxt++;
        }
    }
    cout << qnt << endl;
}

int main(){
    FASTIO;
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);
    preProcessing(pattern);
    myKMP(text, pattern);
    return 0;
}