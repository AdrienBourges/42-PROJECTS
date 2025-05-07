#include "PmergeMe.hpp"
#include <vector>
#include <deque>

static void mergeVector(std::vector<int>& v, int l, int m, int r) 
{
	int n1 = m - l + 1;
	int n2 = r - m;
	std::vector<int> L(n1);
	std::vector<int> R(n2);
	for (int i = 0; i < n1; ++i) 
		L[i] = v[l + i];
	for (int j = 0; j < n2; ++j) 
		R[j] = v[m + 1 + j];
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) 
	{
		if (L[i] <= R[j]) 
			v[k++] = L[i++];
		else 
			v[k++] = R[j++];
	}
	while (i < n1) 
		v[k++] = L[i++];
	while (j < n2) 
		v[k++] = R[j++];
}

static void mergeSortVector(std::vector<int>& v, int l, int r) 
{
	if (l < r) 
	{
		int m = l + (r - l) / 2;
		mergeSortVector(v, l, m);
		mergeSortVector(v, m + 1, r);
		mergeVector(v, l, m, r);
	}
}

void mergeInsertSort(std::vector<int>& v) 
{
	if (!v.empty())
		mergeSortVector(v, 0, static_cast<int>(v.size()) - 1);
}

static void mergeDeque(std::deque<int>& d, int l, int m, int r) 
{
	int n1 = m - l + 1;
	int n2 = r - m;
	std::deque<int> L;
	std::deque<int> R;
	for (int i = 0; i < n1; ++i) 
		L.push_back(d[l + i]);
	for (int j = 0; j < n2; ++j) 
		R.push_back(d[m + 1 + j]);
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) 
	{
		if (L[i] <= R[j]) 
			d[k++] = L[i++];
		else 
			d[k++] = R[j++];
	}
	while (i < n1) 
		d[k++] = L[i++];
	while (j < n2) 
		d[k++] = R[j++];
}

static void mergeSortDeque(std::deque<int>& d, int l, int r) 
{
	if (l < r) 
	{
		int m = l + (r - l) / 2;
		mergeSortDeque(d, l, m);
		mergeSortDeque(d, m + 1, r);
		mergeDeque(d, l, m, r);
	}
}

void mergeInsertSort(std::deque<int>& d) 
{
	if (!d.empty())
		mergeSortDeque(d, 0, static_cast<int>(d.size()) - 1);
}
