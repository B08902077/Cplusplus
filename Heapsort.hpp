#include <vector>
#include <algorithm>
using namespace std;
int command;

template <typename E>
bool Less(E &x, E &y){
	if(command > 0)	return x < y;
	else	return x > y;
}

template <typename E>
void balance(vector<E> &v, int p, int Size){
	int Opt;
	while(p*2+1 < Size){
		Opt= 1;
		if(p*2+2 < Size && Less(v.at(p*2+1), v.at(p*2+2)))	Opt = 2;
		if(Less(v.at(p), v.at(p*2+Opt))){
			swap(v.at(p), v.at(p*2+Opt));
			p = p*2+Opt;
		}else	break;
	}
}

template <typename E>
void initialization(vector<E> &v){
	int base = 1, Size = v.size();
	while(base <= Size/2)	base *= 2;
	while(base != 1){
		for(int i = base/2-1; i < base-1; i++){
			balance(v, i, Size);
		}
		base /= 2;
	}
}

template <typename E>
void Heapsort(vector<E> &v, int Command = 1){
	command = Command;
	initialization(v);
	int n = v.size();
	while(n > 1){
		swap(v.front(), v.at(--n));
		balance(v, 0, n);
	}
}
