#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace std;

struct values {
public:
	int len, wid;

	values(): len(5), wid(5){
	}

};

void* calArea(void* arg) {
	values* square = (values*)arg;

	cout << "Area: " << square->len * square->wid << endl;

	return 0;
}

void* calPerimeter(void* arg) {
	values* square = (values*)arg;

	cout << "Perimeter: " << 2 * (square->len + square->wid) << endl;

	return 0;
}

int main() {
	pthread_t thread_id;
	values* square = new values;

	pthread_create(&thread_id, NULL, calArea, (void*)square);
	pthread_create(&thread_id, NULL, calPerimeter, (void*)square);

	pthread_exit(NULL);	

	delete square;

	return 0;
}
