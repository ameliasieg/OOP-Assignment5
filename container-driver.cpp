#include "container.h"
#include <iostream>
using namespace std;

int main()
{
    DoubleContainer A; // Taking in this one
    DoubleContainer B; // Taking in this one
    DoubleContainer C; // Returning this one
    A.AddToEnd(2);
    B.AddToEnd(3);
    A.AddToEnd(5);
    B.AddToEnd(5);
    C = A + B;
    cout << "\nAddition: " << C;

    DoubleContainer D; // Taking in this one
    DoubleContainer E; // Taking in this one
    DoubleContainer F; // Returning this one
    D.AddToEnd(6);
    E.AddToEnd(4);
    D.AddToEnd(8);
    E.AddToEnd(3);
    F = D - E;
    cout << "Subtraction: " << F;
    
    DoubleContainer N;
    DoubleContainer O;
    DoubleContainer P;
    DoubleContainer Q;
    N.AddToEnd(8);
    O.AddToEnd(9);
    N.AddToEnd(1);
    O.AddToEnd(3);
    P = N + O;
    cout << "Negation: \n\tOriginal Array: " << P;
    Q = -P;
    cout << "\tNew Array: " << Q;
    
    DoubleContainer G; // Taking in this one
    DoubleContainer H; // Returning this one
    G.AddToEnd(6);
    G.AddToEnd(5);
    H = 7 * G;
    cout << "Multiplication (DoubleContainer): " << H;
    
    DoubleContainer I; // Taking in this one
    DoubleContainer J; // Taking in this one
    I.AddToEnd(5); // Multiplying by 2
    J.AddToEnd(2); // Multiplying by 3
    cout << "Multiplication (Dot Product): " << I * J << endl; 

    // Test for Clear
    DoubleContainer L;
    L.AddToEnd(4);
    L.AddToEnd(7);
    cout << "\nTest for Clear: \n\tBefore Clear: " << L; // Should be < 4, 7 >
    L.Clear();
    cout << "\tAfter Clear: " << L; // Should be < > right?

    // Test for Remove
    DoubleContainer M;
    M.AddToEnd(9);
    M.AddToEnd(11);
    cout << "Test for Remove: \n\tBefore Remove: " << M; // Should be < 9, 11 >
    M.Remove();
    cout << "\tAfter Remove: " << M; // Should be 11
}