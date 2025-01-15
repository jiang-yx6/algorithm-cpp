#pragma once

template<typename Type>
Type RandomizedPartition(Type* array, int left, int right);

template<typename Type>
Type RandomizedSelectThreeParts(Type* array, int left, int right, int index)
{
	if (left == right)
		return array[left];
	int i = RandomizedPartition(array, left, right);
	int j = i - left + 1;
	if (j == index)
		return array[i];
	else if (j > index)
		return RandomizedSelectThreeParts(array, left, i - 1, index);
	else
		return RandomizedSelectThreeParts(array, i + 1, right, index - (i - left + 1));
}

template<typename Type>
Type RandomizedSelectTwoParts(Type* array, int left, int right, int index)
{
	if (left == right)
		return array[left];
	int i = RandomizedPartition(array, left, right);
	int j = i - left + 1;
	if (j >= index)
		return RandomizedSelectTwoParts(array, left, i , index);
	else
		return RandomizedSelectTwoParts(array, i + 1, right, index - j);
}


template<typename Type>
Type RandomizedPartition(Type* array, int left, int right)
{
	int i = left;
	int j = right;
	while (i < j)
	{
		while (i < j && array[j] >= array[left])
			j--;
		while (i < j && array[i] <= array[left])
			i++;

		swap(array[i], array[j]);
	}
	swap(array[j], array[left]);

	return j;
}


