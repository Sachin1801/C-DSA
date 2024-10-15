// hastable.h

template <typename T>
class Node{
public:
	string key;
	T val;
	Node* next;

	Node(string key, T val){
		this-> key = key ;
		this->val = val;
		next = NULL;
	}
};

class HashTable{

	Node<T> ** table;
	int cs=0; //total enteries that have been made so far
	int ts = 0;

public:
	HashTable(int default_size = 7){
		cs =0 ;
		ts = default_size;

		table = new Node<T>*[ts];

		for(int i=0;i<ts;i++){
			table[i]==NULL;
		}
	}

};