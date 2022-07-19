#include "page_80.h"

void SwapRef::swap_by_ref(int*a, int*b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}