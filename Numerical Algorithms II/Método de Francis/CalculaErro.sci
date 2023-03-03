function [E] = CalculaErro(A)
    e(1) = abs(A(2, 1)); 
    e(2) = abs(A(3, 1)); 
    e(3) = abs(A(3, 2)); 
    E=max(e);
endfunction
