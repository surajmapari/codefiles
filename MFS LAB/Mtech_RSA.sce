funcprot(0);
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

alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
message = input("Enter the messsage: ", "string");
message_ascii = ascii(message);
disp(message_ascii);


p = input("Enter the prime number p: ");
q = input("Enter the prime number q: ");
e = input("Enter the prime number e: ");

n = p * q;
disp("N: ", n);
Phi = (p -1) * (q - 1);
disp("Phi: ", Phi);

gcd = euclidean_gcd(e, Phi);

disp("Gcd: ", gcd);

a = zeros(1, length(message));
disp("Empty array: ", a);

for i = 1:length(message)
    k = strindex(alpha, part(message, i)) - 1;
    disp("k: ", k);
    a(i) = modulo(modulo(k**e, n), 26);
end

disp("Encrypt: ", a);

en = "";
for i = 1:length(message)
    en = en + part(alpha, a(i)+1);
end

disp("Message: ", message);
disp("Ciphertext: ", en);







