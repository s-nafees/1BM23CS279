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
                printf("Enter value :");
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

OUTPUT :
enter 1-push, 2-pop, 3-display, 4-exit :1
Enter value :20
2 pushed onto stack
enter 1-push, 2-pop, 3-display, 4-exit :1
Enter value :30
3 pushed onto stack
enter 1-push, 2-pop, 3-display, 4-exit :1
Enter value :40
4 pushed onto stack
enter 1-push, 2-pop, 3-display, 4-exit :1
Enter value :50
5 pushed onto stack
enter 1-push, 2-pop, 3-display, 4-exit :1
Enter value :60
6 pushed onto stack
enter 1-push, 2-pop, 3-display, 4-exit :1
Enter value :70
Stack overflow!
enter 1-push, 2-pop, 3-display, 4-exit :3
stack elements :
60
50
40
30
20
enter 1-push, 2-pop, 3-display, 4-exit :2
60 popped successfully!
enter 1-push, 2-pop, 3-display, 4-exit :2
50 popped successfully!
enter 1-push, 2-pop, 3-display, 4-exit :2
40 popped successfully!
enter 1-push, 2-pop, 3-display, 4-exit :2
30 popped successfully!
enter 1-push, 2-pop, 3-display, 4-exit :2
20 popped successfully!
enter 1-push, 2-pop, 3-display, 4-exit :2
Stack underflow!!
enter 1-push, 2-pop, 3-display, 4-exit :3
stack is empty
enter 1-push, 2-pop, 3-display, 4-exit :4

Process returned 0 (0x0)   execution time : 40.180 s
Press any key to continue.
