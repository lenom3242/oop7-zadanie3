#include <iostream>
using namespace std;
class Array {
private:
	int arrsize, * p_first;
public:
	void setbyindex(int index, int number){
		if (index > arrsize - 1)
			cout << "The element does not exist";
		else
			p_first[index] = number;
	}
	 int getbyindex(int index) const {
		if (index > arrsize - 1)
			cout << "The element does not exist";
		else
			return p_first[index];
	}
	 void printarr() const {
		for (int i = 0; i < arrsize; i++) {
			cout << p_first[i] << " ";
		}
		cout << endl;
	}
	void changearr(int newsize) {
		if (newsize > arrsize) {
			int *p_temp = new int[newsize]();
			for (int i = 0; i < arrsize; i++) {
				p_temp[i] = p_first[i];
			}
			delete[] p_first;
			p_first = p_temp;
			arrsize = newsize;
		}
		if (newsize < arrsize) {
			int* p_temp = new int[newsize];
			for (int i = 0; i < newsize; i++) {
				p_temp[i] = p_first[i];
			}
			delete[] p_first;
			p_first = p_temp;
			arrsize = newsize;
		}
	}
	Array() :arrsize(5) {
		p_first = new int[5];
		for (int i = 0; i < 5; i++)
			p_first[i] = 1;
	}
	 Array(int size) : arrsize(size) {
		p_first = new int [size];
		for (int i = 0; i < size; i++) {
			p_first[i] = rand() % 100 - 10;
		}
	}
	~Array() {
		delete[] p_first;
	}

};
void main(){
	Array test;
	test.printarr();
	test.changearr(20);
	test.printarr();
	test.setbyindex(0, 666);
	test.printarr();
	const Array test2(10);
	test2.printarr();
}