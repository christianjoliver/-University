#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, j, a = 0;
    cin >> t;
    stack<char> s;
    for(int i = 0; i < t; i++){
        string p;
        cin >> p;
        a=1;
        for(j = 0; j < p.size(); j++){
            if(p[j] == '(' || p[j] == '[' || p[j] == '{') s.push(p[j]);
            else{
                if(s.size()){
                    if(p[j] == ')' && s.top() == '(') s.pop();
                    else if(p[j] == ']' && s.top() == '[') s.pop();
                    else if(p[j] == '}' && s.top() == '{') s.pop();
                    else{a = 0; break;}
                }else{a=0; break;}
            }
        }
        if(a && s.empty()) cout << "Balanceada\n";
        else{
            cout << "Erro de balanceamento\n";
        }
    }
    return 0;
}