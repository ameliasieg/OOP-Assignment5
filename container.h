#include <iostream>
using namespace std;

class DoubleContainer
{
    // Friend Functions
    friend ostream& operator<<(ostream&, const DoubleContainer&);
    friend DoubleContainer operator+(DoubleContainer, DoubleContainer); // Addition
    friend DoubleContainer operator-(DoubleContainer, DoubleContainer); // Subtraction
    friend DoubleContainer operator-(DoubleContainer);                  // Negation - operator! ? Does this need to be a friend?
    friend DoubleContainer operator*(double, DoubleContainer);          // Multiplication 1
    friend double operator*(DoubleContainer&, DoubleContainer&);        // Multiplication 2

    public:

    void AddToEnd(double);    // Adds the given double value to the end of the content array
    void Clear();        // Removes all doubles from the content array
    double Remove();     // Removes the last double from the content array and returns it to the caller
    void GrowContainer();
    DoubleContainer& operator=(const DoubleContainer&);

    DoubleContainer();                          // Default constructor - initialize content array to size 5
    ~DoubleContainer();                         // Destructor
    DoubleContainer(double*, int);              // A constructor
    DoubleContainer(const DoubleContainer&);    // A copy constructor
    
    private:

    double* Content;        // Dynamically allocated array of doubles
    int maxContainerSize;   // Max size of the DoubleContainer
    int currentDoubles;     // Same thing as currentSize

};