#include "StaticStack.h"
#include "FixedSizeStack.h"
#include "LinkedStack.h"

template class StaticStack<int, 100>;
template class FixedSizeStack<int>;
template class LinkedStack<int>;

int main()
{


	return 0;
}