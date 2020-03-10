#include<iostream>
#include<pthread.h>
#include<string.h>
#include<unistd.h>
using namespace std;
pthread_t id_1,id_2,id_3;
void *reverse(void *input){
	char * str = (char *)input;
	char * rev = new char[5];
	int j=5-1;
	for(int i=0;i<5;i++){
		rev[i]=str[j];
		j--;
	}
	str=rev;
	pthread_exit((void *)str);
}
void *upper(void *input){

	void * in;
	pthread_join( id_1,&in);
	char * str = (char *)in;
	for(int i=0;i<5;i++){
		str[i]-=32;
	}
	pthread_exit((void *)str);
}
void *Display(void * input){

	void * in;
	pthread_join( id_2,&in);
	char * str = (char *)in;
	for(int i=0;i<7;i++){
		cout<<str[i];
	}
	pthread_exit((void *)str);
}

int main(){

	char * arr=new char[5];
	for(int i=0;i<5;i++){
		cin>>arr[i];
	}

	pthread_create(&id_1, NULL, reverse, (void*)arr);
	pthread_create(&id_2, NULL, upper, NULL);
	pthread_create(&id_3, NULL, Display, NULL);

pthread_join( id_3,NULL);



	return 0;
}
