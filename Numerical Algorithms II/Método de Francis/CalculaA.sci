function [outA] = CalculaA(U,A)
    R = U * A;
    Q = U';
    A = R*Q;
    outA=A;
endfunction
