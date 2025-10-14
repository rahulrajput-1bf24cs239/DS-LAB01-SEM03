#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX];
int top=-1;
void push(){
int item;
if(top==MAX-1){
    printf("\n STACK OVERFLOW \n");
}
else{
    printf("Enter the element to push :");
    scanf("%d",&item);
    top++;
    stack[top]=item;
    printf("Element %d pushed into the stack \n");
}
}
void pop (){
if(top==-1){
    printf("\n Stack Underflow \n");
}else{
    printf("Element %d popped out of the stack \n",stack[top]);
    top--;
}
}
void display(){
if(top==-1){
    printf("\n Stack is empty \n");
}else{
    printf("Stack elements are :\n");
    for (int i=top;i>=0;i--){
        printf("%d \n",stack[i]);
}
}
}
int main(){
int choice;
while(1){
    printf("STACK MENU : \n");
    printf("1.PUSH\n");
    printf("2.POP\n");
    printf("3.DISPLAY\n");
    printf("4.EXIT\n");
    printf("Enter your choice :");
    scanf("%d",&choice);
    switch(choice){
case 1:
    push();
    break;
case 2:
    pop();
    break;
case 3:
    display();
    break;
case 4:
    exit(0);
default:
    printf("Invalid choice!\n");
    }
}
return 0;
}
