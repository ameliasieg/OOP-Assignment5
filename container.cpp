#include "container.h"
#include <iostream>

DoubleContainer::DoubleContainer() // Default constructor
{
    Content = new double[5];
    currentDoubles = 0;
    maxContainerSize = 5;
}

DoubleContainer::~DoubleContainer() // Destructor
{
    delete [] Content;
}

DoubleContainer::DoubleContainer(double* newContent, int arraySize) // A constructor
{
    Content = new double[arraySize];
    currentDoubles = arraySize;
    maxContainerSize = arraySize;
    
    for (int i = 0; i < currentDoubles; i++)
        Content[i] = newContent[i];

}

DoubleContainer::DoubleContainer(const DoubleContainer& newDoubleContainer) // A (deep) copy constructor
{
    currentDoubles = newDoubleContainer.currentDoubles;
    maxContainerSize = newDoubleContainer.maxContainerSize;
    Content = new double[currentDoubles];

    for (int i = 0; i < currentDoubles; i++)
        Content[i] = newDoubleContainer.Content[i];

}

ostream& operator<<(ostream& o, const DoubleContainer& d) // Insertion operator overload
{
    int counter = 0;

    o << "< ";
    if(d.currentDoubles > 0)
    {
        for(int i = 0; i < d.currentDoubles - 1; i++)
        {
            o << d.Content[i];
            counter++;
            if(counter != d.currentDoubles)
            {
                o << ", ";
            }
        }
                
        o << d.Content[d.currentDoubles - 1];
        
    }
    o <<  " >\n" << endl;
    return o;
}

DoubleContainer& DoubleContainer::operator=(const DoubleContainer& dc) // Deep copy assignment operator overload
{
    if(this != &dc) // "this" keyword is a pointer to the calling object
    {
        delete [] Content;
        Content = new double[dc.maxContainerSize];
        currentDoubles = dc.currentDoubles;
        maxContainerSize = dc.maxContainerSize;

        for(int i = 0; i < currentDoubles; i++)
            Content[i] = dc.Content[i];
    }

    return *this; // Returning the dereferenced "this" object
}

void DoubleContainer::GrowContainer()
{
    maxContainerSize = currentDoubles + 10;                 
    double* newArray = new double[maxContainerSize];
    
    for (int i = 0; i < currentDoubles; i++)
        newArray[i] = Content[i];
    
    delete [] Content;
    Content = newArray; 
}

void DoubleContainer::AddToEnd(double d) // Adds given double value to end of Content array
{
    if (currentDoubles == maxContainerSize) // If the array is full, grow it
        GrowContainer();
    
    Content[currentDoubles]= d;
    currentDoubles++;
}

DoubleContainer operator+(DoubleContainer one, DoubleContainer two) // Addition
{
    if(one.currentDoubles != two.currentDoubles) // If sizes are NOT equal, return a default value
    {   
        cout << "ERROR. Validation issue inside of the operator's implementation." << endl;
        return one;
    }

    // If sizes ARE equal, continue...
    DoubleContainer temp;
   
    for(int i = 0; i < one.currentDoubles; i++)
        temp.AddToEnd(one.Content[i] + two.Content[i]);

    return temp;

}

DoubleContainer operator-(DoubleContainer one, DoubleContainer two) // Subtraction
{
    if(one.currentDoubles != two.currentDoubles) // If sizes are NOT equal, return a default value
    {   
        cout << "ERROR. Validation issue inside of the operator's implementation." << endl;
        return one;
    }

    // If sizes ARE equal, continue...
    DoubleContainer temp;
   
    for(int i = 0; i < one.currentDoubles; i++)
        temp.AddToEnd(one.Content[i] - two.Content[i]);

    return temp;

}

DoubleContainer operator-(DoubleContainer dc) // Negation
{
    DoubleContainer temp;

    for(int i = 0; i < dc.currentDoubles; i++)
        temp.AddToEnd(dc.Content[i] * (-1));

    return temp;

}

DoubleContainer operator*(double d, DoubleContainer dc) // Multiplication DoubleContainer
{
    DoubleContainer temp;

    for(int i = 0; i < dc.currentDoubles; i++)
        temp.AddToEnd(d * dc.Content[i]);

    return temp;

}

double operator*(DoubleContainer& one, DoubleContainer& two) // Multiplication Dot Product
{
    if(one.currentDoubles != two.currentDoubles) // If sizes are NOT equal, return a default value
    {   
        cout << "ERROR. Validation issue inside of the operator's implementation." << endl;
        return 0;
    }

    // If sizes ARE equal, continue...
    double temp1 = 2;
    double temp2 = 3;

    for(int i = 0; i < one.currentDoubles; i++)
    {
        temp1 *= one.Content[i];
        temp2 *= two.Content[i];
    }
        
    return temp1 + temp2;
}

void DoubleContainer::Clear() // Clear ?
{
    currentDoubles = 0;

}

double DoubleContainer::Remove() // Remove ? Help
{
    double d = Content[currentDoubles - 1];
    currentDoubles--;
    return d;
}