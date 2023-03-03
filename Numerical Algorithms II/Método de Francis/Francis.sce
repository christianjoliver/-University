clear
clc
//                  QUESTÕES DO SLIDE
//A={1 0 0; 1 1 -2;0 1 -1}; // NAO DÁ PRA CALCULAR, NUMERO COMPLEXO;
//A={3 2 1; 1 4 1;1 2 3}; // DEU CERTO, SPEC = (2 6 2)
//A={3 3 -2; 0 -1 0; 8 6 -5}; // NAO DÁ PRA CALCULAR, NUMERO COMPLEXO;
//A={1 -1 0; 2 3 2; 1 1 2}; // DEU CERTO, SPEC = (2 3 1)
//A={3 -1 -3; 0 2 -3;0 0 -1}; // DEU CERTO, SPEC = (3 2 -1)
//A={1 2 1; -1 3 1;0 2 2}; // DEU CERTO, SPEC = (3 2 1)


//                 QUESTÕES PASSADAS NO CLASSROOM
//A = {7 3 1; -1 4 1; 9 1 -1};              //LETRA A
A = {1 2 1; -1 3 1; 0 2 2};               //LETRA B
//A = {3 2 1; -1 8 1; 9 2 2};               //LETRA C
//A = {3 2 1; 1 4 1; 1 2 3};                //LETRA D

exec("CalculaA.sci");
exec("CalculaErro.sci");

erro = 0.0001;
k=0;
while(CalculaErro(A)>=erro)
      k=k+1;
    if(A(2, 1)<>0 & CalculaErro(A)>=erro )
        s = A(2, 1)/(sqrt(A(1, 1)^2 + A(2, 1)^2));
        c = A(1, 1)/(sqrt(A(1, 1)^2 + A(2, 1)^2));
        U = {c s 0; -s c 0; 0 0 1};        
        A = CalculaA(U,A);        
    end
    
    if(A(3, 1)<>0 & CalculaErro(A)>=erro )
        s = A(3, 1)/(sqrt(A(1, 1)^2 + A(3, 1)^2));
        c = A(1, 1)/(sqrt(A(1, 1)^2 + A(3, 1)^2));
        U = {c 0 s; 0 1 0; -s 0 c};
        A = CalculaA(U,A);        
    end
    
    if(A(3, 2)<>0 & CalculaErro(A)>=erro)
        s = A(3, 2)/(sqrt(A(2, 2)^2 + A(3, 2)^2));
        c = A(2, 2)/(sqrt(A(2, 2)^2 + A(3, 2)^2));
        U = {1 0 0; 0 c s; 0 -s c};
        A = CalculaA(U,A);
    end    
    
    disp(k);
    disp(A);
end
