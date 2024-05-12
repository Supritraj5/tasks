/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>
#include<conio.h>

int main() {
    int choice;
    int runAgain = 0;
    int a, b;
float c,d;

    while(1) {
        printf("onec\n\n");
        printf("\n\n\tCALCULATOR\n\n");
        printf("\n1) For Addition 2) For Subtraction 3) For Multiplication 4) For Division\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n\n\t-------ADDITION-------");
                printf("\n\nEnter first number : ");
                scanf("%d", &a);
                printf("\nEnter second number : ");
                scanf("%d", &b);
                printf("\nSum of %d and %d = %d", a, b, a + b);
                break;

            case 2:
                printf("\n\n\t-------SUBTRACTION-------"); 
                printf("\n\nEnter first number : ");
                scanf("%d", &a);
                printf("\nEnter second number : ");
                scanf("%d", &b);
                printf("\nDifference of %d and %d = %d", a, b, a - b);
                break;
                
            case 3:
                printf("\n\n\t-------MULTIPLICATION-------"); 
                printf("\n\nEnter first number : ");
                scanf("%d", &a);
                printf("\nEnter second number : ");
                scanf("%d", &b);
                printf("\nProduct of %d and %d = %d", a, b, a * b);
                break;

            case 4:
                printf("\n\n\t-------DIVISION-------"); 
                printf("\n\nEnter Dividend : ");
                scanf("%f", &c);
                printf("\nEnter Divisor : ");
                scanf("%f", &d);
                if(d==0.0){
                    printf("\n Err, Cannot divide by 0");
                }
                else if(d>0.0{
                    printf("\nQuotient of %.2f / %.2d = %.2d", a, b, a / b);
                }
                
                break;
                
            default:
                break;
        }
        int ans = 0;
        printf("\n\nWant to do more calculations, press 1 for yes 0 for no : ");
        scanf("%d",&ans);
        //getch();
        if(ans == 1){
            continue;
        }else{
            printf("bye");
            break;
        }
        
    } ;

    return 0;
}

