#include <cmath>

extern "C" _declspec(dllexport) double Recursive_func(int begin, int index, double* arr)
{
	double com = arr[index] * arr[index] + cos(arr[index]);
	if (index == begin)
		return com;
	return com * Recursive_func(begin, index - 1, arr);
}