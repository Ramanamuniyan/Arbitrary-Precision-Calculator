
#include <stdio.h>
#include <ctype.h>
#include "valid.h"

int main(int argc ,char *argv[])
{

    if(argc < 4)
    {
        errorprint();
        return 0;
    }

    char *ptrop1=argv[1];

     if( isvalid(ptrop1)  != 0)
     {
        errorprint();
        puts("operand 1 is not a digit");

        return 0;
     }
     char *ptrop2=argv[3];
     if(isvalid(ptrop2) != 0)
      {
        errorprint();
        puts("operand 2 is not a digit");
        return 0;
        }

    char *ptrop=argv[2];
    if( operator_check(ptrop) != 0)
    {
        puts("operators should be '+','-','x','/'");
        return 0;
    }

    //puts ("Both op1 & op2 are digit");

    Dlist *op1_head=NULL,*op1_tail=NULL,*op2_head=NULL,*op2_tail=NULL,*res_head=NULL,*res_tail=NULL;
    
    int flag1=0,flag2=0;
    if(*ptrop1=='-')
    {
    flag1=1;
    ptrop1++;
    }
    if(*ptrop2=='-')
    {
        flag2=1;
        ptrop2++;
    }



    while(*ptrop1 != '\0')
    {

    insert_at_last(&op1_head,&op1_tail,(*ptrop1 -48));
    ptrop1++;
    }
    while(*ptrop2 != '\0')
    {
    insert_at_last(&op2_head,&op2_tail,( *ptrop2 - 48));
    ptrop2++;
    }

    print_list(op1_head);
    printf(" %s ",ptrop);
    print_list(op2_head);
    printf(" = ");



    if(*ptrop=='+')
    if((flag1 ^ flag2) )
    *ptrop='-';

    if(*ptrop=='-')
    if((flag1 ^ flag2) )
    *ptrop='+';

    

    switch (*ptrop)
    {
	case '+':
	    /* call the function to perform the addition operation */
        if(addition(&op1_head,&op1_tail,&op2_head,&op2_tail,&res_head,&res_tail) == SUCCESS)  
        {
          
            if(compare(op1_head,op2_head) !=SMALLER && flag1)
            printf("-");

            if(compare(op1_head,op2_head) == SMALLER && flag2)
            printf("-");

        print_list(res_head);
        printf("\n");

        }
        
        else
        puts("Addition not Possible");
        

	    break;
	case '-':	
	    /* call the function to perform the subtraction operation */
       
        if(subtraction(&op2_head,&op2_tail,&op1_head,&op1_tail,&res_head,&res_tail) == SUCCESS && compare(op1_head,op2_head) == SMALLER) 
        {        
       
        if(flag2)
        printf("-");

        
        print_list(res_head);
        printf("\n");
        }
        

        else
        {
        if(subtraction(&op1_head,&op1_tail,&op2_head,&op2_tail,&res_head,&res_tail) == SUCCESS)  
        {
            if(flag1)
            printf("-");
            print_list(res_head);
        printf("\n");}

        }
	    break;
	case 'x':	


	    /* call the function to perform the multiplication operation */
    if(multiplication(&op1_head,&op1_tail,&op2_head,&op2_tail,&res_head,&res_tail) == SUCCESS)  
        {
          if(flag1 ^ flag2)
          printf("-");
            print_list(res_head);
        printf("\n");}

	    break;
    case 'X':	
	    /* call the function to perform the multiplication operation */
    if(multiplication(&op1_head,&op1_tail,&op2_head,&op2_tail,&res_head,&res_tail) == SUCCESS)  
        {
             if(flag1 ^ flag2)
          printf("-");
            print_list(res_head);
        printf("\n");}

	    break;
    case '*':	
	    /* call the function to perform the multiplication operation */
    if(multiplication(&op1_head,&op1_tail,&op2_head,&op2_tail,&res_head,&res_tail) == SUCCESS)  
        {
             if(flag1 ^ flag2)
          printf("-");
        print_list(res_head);

        printf("\n");}

	    break;
	case '/':	
	    /* call the function to perform the division operation */
        if(division(&op1_head,&op1_tail,&op2_head,&op2_tail,&res_head,&res_tail) == SUCCESS)  
        { if(flag1 ^ flag2)
          printf("-");
            print_list(res_head);
        printf("\n");}

       
	    break;

case '%':	
	    /* call the function to perform the division operation */
        if(reminder(&op1_head,&op1_tail,&op2_head,&op2_tail,&res_head,&res_tail) == SUCCESS)  
        // { if(flag1 ^ flag2)
        //   printf("-");
            print_list(res_head);
        printf("\n");
       
	    break;
	default:
	    printf("Invalid Input:-( Try again...\n");
    }


    freefun(op1_head,op1_tail);
    op1_head=op1_tail=NULL;
    freefun(op2_head,op2_tail);
    op2_head=op2_tail=NULL;
}