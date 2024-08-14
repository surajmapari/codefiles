funcprot(0);

function result = modular_exponential(a, b, n)
    result = 1;
    a = modulo(a, n);
    while b > 0 do
        if modulo(b, 2) == 1 then 
            result = modulo(result * a, n);           
        end
        b = floor(b / 2);
        a = modulo(a * a, n);
    end
endfunction

a = input("Enter the base(a): ");
b = input("Enter the exponent(b): ");
n = input("Enter the modulus(n): ");

result = modular_exponential(a, b, n);
disp("The result of " + string(a) + "^" + string(b) + " is: " + string(result));
