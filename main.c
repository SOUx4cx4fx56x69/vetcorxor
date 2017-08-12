#include "main.h"
#include <stdio.h>
#include <stdlib.h>

unsigned long int __strlen(const char * string){
unsigned long int result;
while(*string++)
 result++;
return result;
}

/*
Test shit-code
*/

#define ASARRAY

#ifdef ASVECTOR
bigcharvector strToBigVector(const char * str,unsigned long int * psize){
 bigcharvector result;
 while(*str){
	result[(*psize)++]=*str++;
 }
 return result;

}

void xorbigchar(bigcharvector * vec,bigchar N){
(*vec)^=N;
}

void printBigCharVector(bigcharvector vec,unsigned long int size){
for(unsigned long int t = 0;t<size;t++){
printf("%c",vec[t]);
}
printf("\n");
}
#elif defined(ASARRAY)
void strtobigchar(const char * string,bigchar * bigc){
while(*string)
	*bigc++=*string++;
}
void toXor(void*what,unsigned long int to,unsigned long int size){
bigchar * tmp=what;
while(size--)
	tmp[size]^=to;
}
void printbigchar(bigchar * chars,unsigned long int size){
//printf("Size is %d\n",size);
while(size--){
printf("%c",*chars++);
}
printf("\n");
}

#endif

int main(int argcount,char**arguments){
if(argcount < 3) return 0;
#ifdef ASVECTOR
unsigned long int size;
bigcharvector myvec=strToBigVector(arguments[1],&size);
xorbigchar(&myvec,atoi(arguments[2])); 
printBigCharVector(myvec,size);
#elif defined(ASARRAY)
auto len = __strlen(arguments[1]);
bigchar * bigchararray = malloc(sizeof(bigchar)*len+1);
strtobigchar(arguments[1],bigchararray);
toXor((bigchar*)bigchararray,atoi(arguments[2]),len);
printbigchar(bigchararray,len);
toXor((bigchar*)bigchararray,atoi(arguments[2]),len);
printbigchar(bigchararray,len);
free(bigchararray);
#endif
}
