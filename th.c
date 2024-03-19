#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
void towers(int, char, char, char);
void eval(char postfix[30]);
void push(float op);
float pop();
float stack[30];
int
top=-1;
void main()
{
int ch,n;
char postfix[30];
while(1)
{
printf("Stack Application\n 1. Evaluation of postfix\n2.Tower of Hanoi\n 3.exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter the postfix expression\n");
scanf("%s",postfix);
eval(postfix);
break;
case 2:printf("Enter the number of disk\n");
scanf("%d",&n);
towers(n,'A','B','C');
break;
case 3:exit(0);
default: printf("Enter the valid choice\n");
}
}
}
void towers(int n, char A, char B, charC)
{
if(n==1)
 {
 printf("disk 1 is moved from peg %c to peg %c\n", A, C);
 return;
 }
	towers(n-1, A, C, B);
	printf("Disk %d is moved from peg %c to peg %c\n",n, A, C);
	towers(n-1, B, A, C);
}
void eval(char postfix[30])
{
float result,op1,op2;
int i=0;
while(postfix[i]!='\0')
{
if(isdigit(postfix[i]))
push(postfix[i]-'0');
else
{
op2=pop();
op1=pop();
switch(postfix[i])
{
case '+': result=op1+op2;
break;
case '-': result=op1-op2;
break;
case '*': result=op1*op2;
break;
case '/': result=op1/op2;
break;
case '%': result=fmod(op1,op2);
break;
case '^': result=pow(op1,op2);
break;
default : printf("Enter a valid operation\n");
}
 push(result);
}
  i++;
}
  if(top==0)
  printf("result=%f\n",result);
else
  {
  printf("invalid expression\n");
  exit(0);
  }
}
void push(float x){
	stack[++top]=x;
}
float pop(){
  if(top==-1)
  {
  printf("Invalid expression\n");
  exit(0);
 }
return(stack[top--]);
}
