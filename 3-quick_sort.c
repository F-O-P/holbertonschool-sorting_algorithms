#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * using Lomuto partition scheme quick sort algorithm
 * @array: pointer to array to be sorted
 * @size: size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - sorts an array of integers in ascending order
 * using Lomuto partition scheme quick sort algorithm
 * @array: pointer to array to be sorted
 * @lo: lowest index of the partition
 * @hi: highest index of the partition
 * @size: size of the array
 * Return: void
 */

void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		quick_sort_helper(array, lo, p - 1, size);
		quick_sort_helper(array, p + 1, hi, size);
	}
}

/**
 * partition - partitions the array
 * @array: pointer to array to be sorted
 * @lo: lowest index of the partition
 * @hi: highest index of the partition
 * @size: size of the array
 * Return: index of the pivot
 */

int partition(int *array, int lo, int hi, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[hi];
	i = lo - 1;
	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[hi])
	{
		temp = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
