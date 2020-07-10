#include "Assemble.h"
#include "Elements.h"

#include <iostream>

using namespace std;

int main()
{
    Elements e = Elements(0, 1, 4);

    Assemble assemble(e, varition_f);

    assemble.AssembleA();

    assemble.AssembleD();

    return 0;
}