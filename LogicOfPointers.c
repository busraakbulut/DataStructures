#include<stdio.h>

int main(){
	
	int x = 255;
	printf("X degiskeninin adresi => %d\n", &x);
	printf("X degiskeninin boyutu => %d", sizeof (x));
	
	
	int *ptr = &x;// x de�erinin adresini sakl�yor.
	printf("\n ptr degeri ==> %d", ptr);
	printf("\n &ptr degeri ==> %d", &ptr);
	printf("\n *ptr degeri ==> %d", *ptr);
	return 0;
	
}
