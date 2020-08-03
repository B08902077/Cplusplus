#include <iostream>
#include <vector>
using namespace std;

template <typename E>
void Shell_sort_increasing(vector<E> &v, int gap){
	E tmp;
	int j;
	for(int i = gap; i < v.size(); i++){
		tmp = v[i];
		for(j = i - gap; j >= 0 && v[j] > tmp; j -= gap)
			v[j+gap] = v[j];
		v[j+gap] = tmp;
	}
	if(gap > 1)	Shell_sort_increasing(v, gap/2);
}

template <typename E>
void Shell_sort_decreasing(vector<E> &v, int gap){
	E tmp;
	int j;
	for(int i = gap; i < v.size(); i++){
		tmp = v[i];
		for(j = i - gap; j >= 0 && v[j] < tmp; j -= gap)
			v[j+gap] = v[j];
		v[j+gap] = tmp;
	}
	if(gap > 1)	Shell_sort_decreasing(v, gap/2);
}

template <typename E>
void Shellsort(vector<E> &v, int Opt = 1){
	if(Opt > 0)	Shell_sort_increasing(v, v.size() / 2);
	else	Shell_sort_decreasing(v, v.size() / 2);
}
