//1190728 amany khdair
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct N;//to let the program know that we have a Node
typedef struct N * POIN;//(pointer)
typedef POIN stack;

char m [MAX][MAX]; //here the data in 2 dimension array to read the statement

struct N
{
    char E [MAX][MAX];//CREATE ELEMENT FROM TYPE CHAR AND SIZE 100 IN THE 2 DIMENSION
    POIN next;
};

stack createS() //to create the stack
{
    stack CS;
    CS = (stack)malloc(sizeof(struct N));//casting ->> means that it will Go and book with node size in memory
    if (CS == NULL) //if CS(create stack) was empty
    {
        printf("SORRY, it is not enough\n");
        return -1;
    }
    CS -> next = NULL;//to solve the problem of -1
    return CS;
}
//every statement entered by the user it will be store in the stack via push method
void push (char h [MAX][MAX],stack CS ) //h means the element that will be added later to the stack
{
    POIN temp;//pointer
    temp = (POIN)malloc(sizeof(struct N));
    if (temp == NULL)//if temp was empty then
    {
        printf("SORRY ☹, OUT OF SPACE!\n");
    }
    else
    {
        //first node point to null &2nd also then the 1 st will point to the new one then the new will point to the first(1 st)
        strcpy(temp ->E, h);
        temp -> next = CS -> next;
        CS -> next = temp;
    }
}

int EMPTY(stack CS)  //top of the stack
{
    return (CS ->next == NULL);//automatically if there was NULL it will come out with one (1)
}

void redo (stack CS)
{
    push(m,CS);//call up the push method
}

void undo(stack CS)//it will delete the last statement entered
{
    POIN temp;
    if(EMPTY(CS))//if the stack is empty
        printf("there is nothing to undo :( , this Stack is already empty\n");//if the user enter from the beginning undo it will print this statement
    else
    {
        temp = CS ->next;//to delete the second node after the header of course
        strcpy(m, temp);
        CS ->next = CS->next->next;
        free(temp);//The free() function It frees up the memory blocks and returns the memory to heap
    }
}

void print (stack CS)//it will print all the statement that the the user will insert
{
    if(CS == NULL){
        return 0;//means don't return any thing
    }
    print(CS ->next);//call out the function again
    printf("%s\n", CS ->next->E);//it will see the first node then go to the next and then print what inside the next
}

void save(stack CS)//if the user write save it will save all the statements were entered inside a file named output.txt
{
    CS = CS ->next;
    FILE *FPO = fopen("output.txt", "w");//open the file and see if there is space (not null)then it will store the sentences entered in this file
    while (CS !=NULL)//it should not equal NULL & it move through through all the nodes to print all the sentences that were entered
    {
        fprintf(FPO,"%S\n", CS ->E );//to check the sentences in the stack (first stack will be empty then it will print what inside it in the file then go to the next node &print it in the file and so on)
        CS = CS ->next;
    }
    fclose(FPO);//to close the file
}

int main()
{
     system("color C0");//this statement isn't useful its just to make the user feel comfortable
    stack CS; //Definition for Stack
    CS = createS();
    int count;
    while(1)//allow the user to Continue to insert sentences & 1 means that its true
    {
        printf("O_OX_XO_OX_XO_OX_XO_OX_XO_OX_XO_O\n");//just for design :)
        printf("please enter any character or phrase you want..or just enter undo, redo,save,print or quit\n");
        char ASD [MAX];//as required in the project the maximum characters equal 100
        gets(ASD);//it will read every line entered by the user
        //here the compiler will start compare about what the user enter like redo, undo,save,print and quit
        if (strcmp(ASD,"redo") == 0)//if the user choose redo then
        {
            redo(CS);// it will call up the redo method
        }
        else if(strcmp(ASD,"undo") == 0)//if the user choose undo then
        {
            printf("this element was deleted\n");//if the user keep write undo then this statement will show
            undo(CS);//its like pop method and here it will call up the undo method
        }
        else if(strcmp(ASD,"print") == 0)//if the user choose print then
        {
            print(CS);//it will call up the print method
        }
        else if(strcmp(ASD,"save") == 0)//if the user choose save then
        {
            save(CS);//it will call up the save method
        }
        else if(strcmp(ASD,"quit") == 0)//here will exit the program if the user choose quit
        {
            save(CS);//to save the information in the file
            exit(0);//to exit from the program
        }
        else
            push(ASD,CS);//means that if the user did not enter any of these statement let the user enter another statement & add it to the stack
        count++;//it will count from the initial value to the upper limit
    }
    return 0;//it means that the program works very well
}
