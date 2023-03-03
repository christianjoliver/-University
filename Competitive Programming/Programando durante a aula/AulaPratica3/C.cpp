#include <bits/stdc++.h>

using namespace std;

int main(){
    long long T, M, N, u;
    string s1, s2, s3;
    char x;

    cin >> T;
    for(int i = 0; i < T; i++){
        map<string, string> lista;
        cin >> M >> N; getchar();

        for(int j = 0; j < M; j++){
            getline(cin, s1);
            getline(cin, s2);
            lista[s1] = s2;
        }

        for(int j=0; j<N; j++){
            u = 1;
            getline(cin, s1);
            stringstream aux(s1);
            while(aux >> s2){
                if(u==1){
                    if(lista.find(s2) == lista.end()) cout << s2;
                    else cout << lista[s2];
                    u = 0;
                }
                else{
                    cout << ' ';
                    if(lista.find(s2) == lista.end()) cout << s2;
                    else cout << lista[s2];
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}