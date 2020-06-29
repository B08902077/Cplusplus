#include <vector>
using namespace std;
struct node{
	uint8_t n[4];
};

void intToNode(int &N, node &tmp){
	for(int i = 0; i < 4; i++){
		tmp.n[i] = N % 256;
		N /= 256;
	}
}

void nodeToInt(node &N, int &Num){
	for(int i = 3; i > 0; i--){
		Num += N.n[i];
		Num = Num << 8;	
	}
	Num += N.n[0];
}

void Radixsort(vector<int> &v, int Command){	// increasing if Command is positive, decreasing otherwise
	int Size = v.size(), id;
	node tmp;
	vector<node> v_node;
	vector<node> bucket[256];
	for(int i = 0; i < Size; i++){
		intToNode(v.at(i), tmp);
		bucket[tmp.n[0]].emplace_back(tmp);
	}
	for(int i = 0; i < 256; i++){
		for(int j = 0; j < bucket[i].size(); j++){
			v_node.emplace_back(bucket[i].at(j));
		}
		bucket[i].clear();
	}
	for(int i = 1; i < 4; i++){
		for(int j = 0; j < Size; j++){
			tmp = v_node.at(j);
			bucket[tmp.n[i]].emplace_back(tmp);
		}
		id = 0;
		for(int j = 0; j < 256; j++){
			for(int k = 0; k < bucket[j].size(); k++){
				v_node.at(id++) = bucket[j].at(k);
			}
			bucket[j].clear();
		}
	}
	if(Command > 0){
		for(int i = 0; i < Size; i++){
			nodeToInt(v_node.at(i), v.at(i));
		}
	}else{
		for(int i = 0; i < Size; i++){
			nodeToInt(v_node.at(i), v.at(Size-1-i));
		}
	}
}
