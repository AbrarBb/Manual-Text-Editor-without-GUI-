#include <stdio.h>       //include standard input/output library
#include <stdlib.h>     //include standard library functions
#include <conio.h>     //include console input/output library
#include <ctype.h>    //include library for character classification functions
#include <stdint.h>  //include library for integer data types

#define MAX_TEXT_LENGTH 1000  //define a macro constant with value 1000
char file_name[100];         //declare a character array to store file name
char ch;                    //declare a character variable
uint8_t choice, a, position;   //declare unsigned integer variables
char text[MAX_TEXT_LENGTH];   //declare a character array of size 1000

int main()        //main function
{
    FILE *fp;   //declare file pointer

    printf("File name to create: ");  //display message to enter file name
    gets(file_name);                 //get file name input from user

    fp = fopen(file_name, "w");    //open the file with write mode

    if (fp == NULL)   //check if file is successfully created
    {
        printf("Error creating file.\n");  //display error message
        exit(1);   //exit program
    }

    printf("File Created Successfully!\n");  //display message that file is created successfully

    printf("Enter text :");   //display message to enter text

    uint8_t a = 0;   //initialize unsigned integer variable 'a' to zero
    do              //execute the following block of code at least once
    {
        ch = getch();       //get character input from user

        if (isprint(ch))   //check if character is printable
        {
            text[a] = ch;   //store character in text array
            a++;   //increment value of 'a'
            printf("%c", ch);   //display the character on console
        }
        else if (ch == 13)      //check if character is Enter key '\n' or '\r'
        {
            text[a] = '\0';   //set the last character in text array to null character
            break;           //break out of the loop
        }
        else if (ch == 8 && a > 0)   //check if character is Backspace key and 'a' is greater than zero
        {
            a--;   //decrement value of 'a'
            printf("\b \b");   //delete the previous character from console
        }
    } while (1);   //execute the loop infinitely

    fputs(text, fp);   //write the text to the file

    fclose(fp);   //close the file

    printf("\nFile saved successfully!\n");   //display message that file is saved successfully

    do   //execute the following block of code at least once
    {
        printf("\n1. Read \n");    //display option to read the file
        printf("2. Insert \n");  //display option to modify the file
        printf("3. Delete \n");
        printf("4. Exit \n");             //display option to exit the program
        printf("Enter your choice: ");  //display message to enter choice
        scanf("%d", &choice);          //get integer input from user

        switch (choice)   //check the value of choice
        {
            case 1:     //if choice is 1
                fp = fopen(file_name, "r");   //open the file in read mode

                if (fp == NULL)   //check if file is successfully opened
                {
                    printf("Error opening file.\n");   //display error

                    exit(1);
                }

                printf("\nText in %s:\n", file_name);

                while ((ch = fgetc(fp)) != EOF)
                {
                    printf("%c", ch);
                }

                fclose(fp);

                break;
            case 2:
                for(int b=0;text[b]!='\0';b++)
                {
                    if(text[b]==' ')
                    {
                         printf("\t Position[%d]=' '\t\n",b); //space
                         b++;
                    }
                    else if(text[b]!=' ');
                    {
                        printf("\t Position[%d]=%c \t\n",b,text[b]);
                    }


                }
                printf("\nEnter position to insert text: ");
                scanf("%d",&position);

                printf("Enter text: ");

                a = 0;
                do
                {
                    ch = getch();

                    if (isprint(ch))
                    {
                        text[a] = ch;
                        a++;
                        printf("%c", ch);
                    }
                    else if (ch == 13) // Enter key
                    {
                        text[a] = '\0';
                        break;
                    }
                    else if (ch == 8 && a > 0) // Backspace key
                    {
                        a--;
                        printf("\b \b");
                    }
                } while (1);

                fp = fopen(file_name, "r");

                if (fp == NULL)
                {
                    printf("Error opening file.\n");
                    exit(1);
                }

                a = 0;
                while ((ch = fgetc(fp)) != EOF)
                {
                    a++;
                }

                fclose(fp);

                fp = fopen(file_name, "r+");

                if (fp == NULL)
                {
                    printf("Error opening file.\n");
                    exit(1);
                }

                fseek(fp, position, SEEK_SET);

                fputs(text, fp);

                fclose(fp);

                printf("\nText inserted successfully!\n");

                break;
            case 3: // pending
                {
                    int c=0;
                    while(1)
                    {
                        if(text[c]!='\0')
                        {
                            text[c]='\0';
                            c++;
                            exit(1);
                            //break;

                        }
                    }
                }
            case 4:
                printf("\nExiting...\n");

                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    } while (1);

    return 0;
}
