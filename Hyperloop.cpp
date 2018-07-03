//Dominik Albiniak
#include <iostream>
using namespace std;

template <class Temp> class Tunnel {
public:
	//-----------
	Tunnel() {
		arr = new Temp[1];
		size = -1;
		next = NULL;
	}
	Tunnel(const Tunnel & wiel) {
		this->size = wiel.size;
		this->arr = new Temp[wiel.size];
		this->next = wiel.next;
		for (int i = 0; i < wiel.size; i++) {
			this->arr[i] = wiel.arr[i];
		}
		//cout << next << endl;
		//Tunnel *p = wiel.next;
		//for (; p != NULL; p = p->next) insert_new(p);
	}
	~Tunnel() {
		//cout << next << endl;
		//if (next) pop_front(next);
		delete[] arr;
	}
	//-----------
	int retSize() {
		return size;
	}
	Temp retMap(int i) {
		return arr[i];
	}
	void placeSize(int i) {
		size = i;
	}
	void setArr(int* x) {
		arr = x;
	}
	int* retArr() {
		return arr;
	}
	void pop_front(Tunnel* head) {
		//cout << head << endl;
		if (head->next != NULL) pop_front(head->next);
		delete head;
	}
	void printl() {
		Tunnel *p = next;
		for (; p; p = p->next) cout << p->data << endl;
		cout << endl;
	}
	void insert_new(Tunnel *x) {
		Tunnel * p, *e;
		e = new Tunnel;
		e->next = NULL;
		e->arr = x->arr;
		e->size = x->size;
		p = next;
		if (p) {
			while (p->next) p = p->next;
			p->next = e;
		}
		else next = e;
	}
	Tunnel* retNext() {
		return next;
	}
	void Tick() {

	}
	//-----------
	void operator >> (Tunnel x) {
		Tunnel * p, *e;
		e = new Tunnel;
		e->next = NULL;
		delete[] e->arr;
		e->arr = new Temp[x.size];
		e->size = x.size;
		for (int i = 0; i < x.size; i++) {
			//cout << x.arr[i] << endl;
			e->arr[i] = x.arr[i];
		}
		p = next;
		if (p) {
			while (p->next) p = p->next;
			p->next = e;
		}
		else next = e;
		//cout << next << endl;
	}
	/*operator>>(Tunnel head) {
	bool t = true;
	for (int i = 0; i < connect.size(); i++)
	if(connect[i] == head || head == *this)
	t = false;
	if (t) {
	connect.insert(head);
	}
	}*/
	int& operator[] (int x) {
		//int q = 0;
		//cout << x << "  " << size << endl;
		if (x >= size) {
			int Bsize = size;
			if (Bsize < 0) {
				Bsize = 1;
				size = 0;
			}
			Temp* newArray = new Temp[Bsize];
			//cout << q++ << endl;
			for (int i = 0; i < size; i++) {
				newArray[i] = arr[i];
			}
			//cout << q++ << endl;
			delete[] arr;
			//cout << q++ << endl;
			arr = new Temp[x + 1];
			//cout << q++ << endl;
			for (int i = 0; i < size; i++) {
				arr[i] = newArray[i];
			}
			//cout << q++ << endl;
			for (int i = size; i < x; i++) {
				arr[i] = (Temp)(0);
			}
			//cout << q++ << endl;
			size = x + 1;
			delete[] newArray;
		}
		return arr[x];
	}
	//-----------
	//std::vector<Temp> connect;
	Tunnel* next;
private:
	Temp* arr;
	int size;

};
template <class Temp> ostream& operator<<(ostream& os, Tunnel<Temp> x) {
	//cout << x.next << endl;
	for (int i = 0; i < x.retSize() - 1; i++) {
		if (x.retMap(i) == (Temp)(0)) {
			os << "_, ";
		}
		else {
			os << x.retMap(i) << ", ";
		}
	}
	if (x.retMap(x.retSize() - 1) == (Temp)(0)) {
		os << "_";
	}
	else {
		os << x.retMap(x.retSize() - 1);
	}
	if (x.next != NULL) {
		//cout << "TAK" << endl;
		Tunnel<Temp> *p = x.next;
		for (; p != NULL; p = p->next) {
			os << " > ";
			for (int j = 0; j < p->retSize() - 1; j++) {
				//cout << p->retSize() << endl;
				if (p->retMap(j) == (Temp)(0)) {
					os << "_, ";
				}
				else {
					os << p->retMap(j) << ", ";
				}
			}
			if (p->retMap(p->retSize() - 1) == (Temp)(0)) {
				os << "_";
			}
			else {
				os << p->retMap(p->retSize() - 1);
			}
		}
	}
	return os;
}
/*template <class Temp>
ostream& operator<<(ostream& os, Tunnel<Temp> x) {
for (int i = 0; i < x.retSize(); i++) {
if (x.retMap(i) == '\0') {
os << "_, ";
} else {
os << x.retMap(i);
}
}
vector < int >::iterator it_tab = x.connect.begin();
for (; it_tab != x.connect.end(); it_tab++) {
Tunnel<Temp> tmp = it_tab;

os << ">";
for (int j = 0; j < tmp.retSize(); j++) {
if (tmp.retMap(j) != '\0') {
os << "_, ";
} else {
os << tmp.retMap(j);
}
}
}
return os;
}*/
int main() {
	Tunnel<int> a;
	a[1] = 91;
	a[2] = 3;
	a[5] = 7;
	Tunnel<int> b;
	b[4] = 11;
	a >> b;
	//cout << b << endl;
	cout << "TAK" << endl;
	cout << a << endl;
	return 0;
}
