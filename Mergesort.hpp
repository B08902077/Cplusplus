#include <vector>
#include <algorithm>
using namespace std;
int command;	// increasing if positive, decreasing otherwise

template <typename E>
bool Less(E &x, E &y){
	if(command > 0)	return x < y;
	else	return x > y;
}

template <typename E>
void Merge(vector<E> &in, vector<E> &out, int p, int base){
	int i = p, j = p + base, k = p, N = in.size(), limit_i = p + base, limit_j = min(p+2*base, N);
	while(i < limit_i && j < limit_j){
		if(Less(in.at(i), in.at(j)))	out.at(k++) = in.at(i++);
		else	out.at(k++) = in.at(j++);
	}
	while(i < limit_i){
		out.at(k++) = in.at(i++);
	}
	while(j < limit_j){
		out.at(k++) = in.at(j++);
	}
}

template <typename E>
void Mergesort(vector<E> &v, int Command = 1){
	command = Command;
	int N = v.size(), i;
	vector<E> v1(v), v2(v), *in = &v1, *out = &v2;
	for(int base = 1; base < N; base *= 2){
		for(i = 0; i + base < N; i += 2*base){
			Merge(*in, *out, i, base);
		}
		while(i < N){
			out->at(i) = in->at(i);
			i++;
		}
		swap(in, out);
	}
	v = *in;
}
