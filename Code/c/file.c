#include<stdio.h>

int main(){
FILE *p;

p =fopen("text.txt","r");
if(p == NULL){
    return -1;
}
char c;

c =fgetc(p);
printf("%c\n",c);

fclose(p);
}
