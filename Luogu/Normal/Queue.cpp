/**
 * P1540 Machine Translation
 * 手动实现队列
 * FIFO
*/

#include <iostream>
#include <stdio.h>

using namespace std;

void memChange(int key, int mem[], int l);

bool search(int key, int mem[], int l);

int main(int argc, char const *argv[])
{
	// Definition and initialization
	int m, n;
	cin >> m >> n;
	int mem[m], length[n];
	for(int i = 0; i < n; i++) {
		cin >> length[i];
	}
	for(int i = 0; i < m; i++) {
		mem[i] = -1;
	}
	// Main
	int count = 0;
	for(int i = 0; i < n; i++) {
		if(search(length[i], mem, m) == false) {
			count ++;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}

// Change mem[] everytime when it fails to find the key. 
void memChange(int key, int mem[], int l) {
	if(l == 1) {
		mem[0] = key;
	}
	else {
		int temp[l - 1];
		for(int i = 0; i < l - 1; i++) {
			temp[i] = mem[i + 1];
		}
		mem[l-1] = key;
		for(int i = l - 2; i >= 0; i--) {
			mem[i] = temp[i];
		}
	}
	
}

// Search the key in mem[] and count the result. Return whether it finds or fails to find the key.
bool search(int key, int mem[], int l) {
	bool find = false;
	for(int i = 0; i < l; i++) {
		if(mem[i] == key) {
			find = true;
		}
	}
	if(find != true) {
		memChange(key, mem, l);
	}

	return find;
}