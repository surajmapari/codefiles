funcprot(0);
function[gcd, x, y] = extended_euclidean(a, b)
    a = abs(a);
    b = abs(b);
    x0 = 1;
    y0 = 0;
    x1 = 0;
    y1 = 1;
    while b <> 0 do
        q = floor(a / b);
        r = a - q * b;
        
        a = b;
        b = r;
        
        x2 = x0 - q * x1;
        y2 = y0 - q * y1;
        
        x0 = x1;
        y0 = y1;
        x1 = x2;
        y1 = y2;
    end
    gcd = a;
    x = x0;
    y = y0;    
endfunction

function x = chinese_remainder_theorem(a, n)
    k = length(a);
    N = prod(n);
    x = 0;
    
    for i = 1:k do
        Ni = N/n(i);
        [gcd, Mi, y] = extended_euclidean(Ni, n(i));
        x = x + a(i)*Mi*Ni;
    end
    x = modulo(x, N);
endfunction
    
num_equations = input("Enter the number of equations: ");
a = zeros(1, num_equations);
n = zeros(1, num_equations);

for i = 1:num_equations do
    a(i) = input("Enter remainder a " + string(i) + " : ");
    n(i) = input("Enter modulus m " + string(i) + " : ");
end

x = chinese_remainder_theorem(a, n);
mprintf("The solution x = " + string(x) + " is the smallest solution.");
