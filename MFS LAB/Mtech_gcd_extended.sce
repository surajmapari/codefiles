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

a = input("Enter the first number(a): ");
b = input("Enter the first number(b): ");
[gcd, x, y] = extended_euclidean(a, b);
disp("Linear combination: " + string(gcd) + " = " + string(x) + "*" + string(a) + " + " + string(y) + "*" + string(b));
