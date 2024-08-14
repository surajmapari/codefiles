function gcd = euclidean_gcd(a, b)
    a = abs(a);
    b = abs(b);
    while b<> 0 do
        temp = b;
        b = modulo(a, b);
        a = temp;
    end
    gcd = a;
endfunction


a = input("Enter the first number(a): ");
b = input("Enter the first number(b): ");
gcd = euclidean_gcd(a, b);
disp(gcd);

