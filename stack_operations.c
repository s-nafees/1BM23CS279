#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int STACK[SIZE];
int top = -1;
void push(int value) {
    if (top == SIZE - 1){
        printf("Stack overflow!\n");
    }
    else {
        top++;
        STACK[top]=value;
        printf("%d pushed onto stack\n",value);
    }
}
void pop() {
    if(top==-1) {
        printf("Stack underflow!!\n");
    }
    else{
        int value = STACK[top];
        top--;
        printf("%d popped successfully!\n",value);
    }
}
void display(){
    if(top==-1){
        printf("stack is empty\n");
    }
    else{
        printf("stack elements :\n");
        for(int i=top;i>=0;i--){
            printf("%d",STACK[i]);
            printf("\n");
        }

    }
}
int main() {
    int choice,a;
    while(1) {
        printf("enter 1-push, 2-pop, 3-display, 4-exit :");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                scanf("%d",&a);
                push(a);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default :
                printf("Invalid choice! enter again");
        }
    }
    return 0;
}
