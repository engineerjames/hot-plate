% Analytic solution provided by:
% Partial Differential Equations, by Nakhle H. Asmar
% Chapter 3, Section 3.8, pg. 168.

% f1(x) = T1, bottom temperature
% f2(x) = T2, top temperature
% g1(y) = T3, left temperature
% g2(y) = T4, right temperature
% a is the width of the plate, and b is the height of the plate

% Embedded in the analytic solution is four coefficients: An, Bn, Cn, and Dn

% First, let us set up the variables used in our analytic proof:
%
%           T2
%     _______________      ^ b
%    |               |     |
% T3 |               | T4  |
%    |               |     |
%    |_______________|     | 0
%           T1
%    ---------------->
%    0               a

% We'll prescribe T1 = 300K, T2 = 400K, T3 = 50K, and T4 = 75K
T1 = 200;
T2 = 500;
T3 = 200;
T4 = 200;

% We'll have a plate that is 1.5m x 3m
a = 1.5;
b = 3.0;

function coefficients = getCoefficients(n, T1, T2, T3, T4, a, b)
%getCoefficients - Description
%
% Syntax: [A B C D] = getCoefficients(n)
%
% Long description
    nPiOverA = (n * pi)/a;
    nPiOverB = (n * pi)/b;

    nPiAOverB = (n*pi*a) / b;
    nPiBOverA = (n*pi*b) / a;

    % Old calculations based on misinterpretation of sin term
    %An = (T1 * sin(nPiOverA) * a) / sinh(nPiBOverA);
    %Bn = (T2 * sin(nPiOverA) * a) / sinh(nPiBOverA);
    %Cn = (T3 * sin(nPiOverB) * b) / sinh(nPiAOverB);
    %Dn = (T4 * sin(nPiOverB) * b) / sinh(nPiAOverB);
    %An = ( 2 * T1 * (1 - cos(pi*n))) / (pi * n * sinh(nPiBOverA));
    %Bn = ( 2 * T2 * (1 - cos(pi*n))) / (pi * n * sinh(nPiBOverA));
    An = (2 * T1 * (a - a * cos(pi*n)) * csch(nPiBOverA)) / (pi * a * n);
    Bn = (2 * T2 * (a - a * cos(pi*n)) * csch(nPiBOverA)) / (pi * a * n);
    Cn = (2 * T3 * (b - b * cos(pi*n)) * csch(nPiAOverB)) / (pi * b * n);
    Dn = (2 * T4 * (b - b * cos(pi*n)) * csch(nPiAOverB)) / (pi * b * n);

    coefficients = [An Bn Cn Dn];
end

% There are also four distinct infinite sum
% for a given (x, y) coordinate

X_STEPS = 100;
Y_STEPS = 100;

for x = 0:a/X_STEPS:a
    for y = 0:b/Y_STEPS:b

        %x = 0.75;
        %y = 0.00;
        printf("Getting value for x=%1.3f, y=%1.3f\n", x, y);

        for n = 1:100
            coeff = getCoefficients(n, T1, T2, T3, T4, a, b);

            nPiOverA = (n * pi) / a;
            nPiOverB = (n * pi) / b;

            term1(n) = coeff(1) * sin(nPiOverA * x) * sinh(nPiOverA * (b - y));
            term2(n) = coeff(2) * sin(nPiOverA * x) * sinh(nPiOverA * y);
            term3(n) = coeff(3) * sinh(nPiOverB * (a-x)) * sin(nPiOverB * y);
            term4(n) = coeff(4) * sinh(nPiOverB * x) * sin(nPiOverB * y);
        end

        theSum = term1 + term2 + term3 + term4;
        printf("Populating index (%i, %i).\n", int32(x/a * X_STEPS), int32(y/b * Y_STEPS));
        u(int32(x/a * X_STEPS) + 1, int32(y/b * Y_STEPS) + 1) = sum(theSum);

    end
end
surf(0:a/X_STEPS:a, 0:b/Y_STEPS:b, u)
