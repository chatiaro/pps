#include <stdio.h>
typedef struct student{
  char name[20];
  float marks;
}student;
int c=0;
void writetofile(student std){
  char l[0];
  l[0]=c==0?'w':'a',c++;
  FILE *fptr;
  fptr=fopen("bruh.bin",l);
  fprintf(fptr, "\nname: %s", std.name);
  fprintf(fptr, "\tMarks: %f", std.marks);
  fclose(fptr);
}
void input(student std){
  printf("\nEnter name: "); gets(std.name);
  printf("\nEnter mks: ");  scanf("%f%*c", &std.marks);
  writetofile(std);
}
void print(){
  FILE *fptr;
  fptr=fopen("bruh.bin", "r");
  char c;
  c=fgetc(fptr);
  while(c != EOF){
    printf("%c", c);
    c=fgetc(fptr);
  }
  fclose(fptr);
}
void main(){
  student std[20];
  int n;
  printf("\nEnter num of stds: ");
  scanf("%d%*c", &n);
  for(int i=0; i<n; i++){
    input(std[i]);
  }
  print();
}
