funcprot(0);

function result = fermat_mod_exp(a, b, p)
    b_mod = modulo(b, p-1);
    result = modular_exponential(a, b_mod, p);
endfunction

function result = modular_exponential(a, b, p)
    result = 1;
    a = modulo(a, p);
    while b > 0 do
        if modulo(b, 2) == 1 then 
            result = modulo(result * a, p);           
        end
        b = floor(b / 2);
        a = modulo(a * a, p);
    end
endfunction

a = input("Enter the base(a): ");
b = input("Enter the exponent(b): ");
p = input("Enter the modulus(p): ");

result = fermat_mod_exp(a, b, p);
disp("The result of " + string(a) + "^" + string(b) + " mod " + string(p) + " using Fermat''s Little Theorem is: " + string(result));

