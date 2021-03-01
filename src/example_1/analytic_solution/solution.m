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
T1 = 300
T2 = 400
T3 = 50
T4 = 75

% We'll have a plate that is 1.5m x 3m
a = 1.5
b = 3.0

function coefficients = getCoefficients(n, T1, T2, T3, T4, a, b)
%getCoefficients - Description
%
% Syntax: [A B C D] = getCoefficients(n)
%
% Long description
    An = (T1 * sin((n * pi)/a) * a) / sinh((n * pi * b)/a);
    Bn = (T2 * sin((n * pi)/a) * a) / sinh((n * pi * b)/a);
    Cn = (T3 * sin((n * pi)/b) * b) / sinh((n * pi * a)/b);
    Dn = (T4 * sin((n * pi)/b) * b) / sinh((n * pi * a)/b);

    coefficients = [An Bn Cn Dn];
end

% There are also four distinct infinite sum
% for a given (x, y) coordinate
for n = 1:100
    coeff = getCoefficients(n, T1, T2, T3, T4, a, b)

    % Just for fun let's find the mid-point temperature
    x = a/2
    y = b/2

    term1 = coeff(1) * sin((n*pi)/a) * x * sinh((n*pi)/a) * (b - y);
    term2 = coeff(2) * sin((n*pi)/a) * x * sinh((n*pi)/a) * y;
    term3 = coeff(3) * sinh((n*pi)/b) * (a-x) * sin((n*pi)/b) * y;
    term4 = coeff(4) * sinh((n*pi)/b) * x * sin((n*pi)/b) * y;

    theSum(n) = term1 + term2 + term3 + term4;
end