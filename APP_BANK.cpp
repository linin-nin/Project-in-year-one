#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
	char id[10];
   char name[20];
   char gender[10];
   char phone[12];
   char pass[20];
   int balance;
}USER;

USER user[20];
int n;

void password(char pass[20])
{
	char ch;
   int i;
  do{
   ch=getch();
   if(ch!=13)
   {
   	if(ch==8 && i>0)
      {
      	gotoxy(wherex()-3,wherey());
         printf("   ");
         gotoxy(wherex()-3,wherey());
         i-=1;
         pass[i]='\0';
         break;
      }
      else{
      	pass[i]=ch;
         	printf(" * ");
            i++;
      }
   }
   }while(getch()!=13);
}

void main()
{
	int i,j;
   int money=10000;//balance;
   //char password[20];
	A: clrscr();
	puts("1. Chack money in bank");
   puts("2. User account");
   puts("3. Show all user"); //show id, name, gender, balance
   puts("4. Update and delete");
   puts("L. Leave");
   switch(getch())
   {
   	case '1': 
      		  clrscr();
      			printf("balance : %d\n",money);
      			getch();
               goto A;
               
      case '2':B: clrscr();
      			puts("1.Sign up");
               puts("2.Sign in");
               puts("L.leave");
               switch(getch())
               {	clrscr();
               	case '1':puts("\n......SIGN UP.....\n");
                  	int balance;
                     char pass[20];
                  	do{
                     	printf("Input ID : ");gets(user[n].id);
                     	printf("Input name :");gets(user[n].name);
                        printf("Input gender :");gets(user[n].gender);
                        printf("Input phone_number :");gets(user[n].phone);
                        
                        a:clrscr();
                        
                        printf("Input password :");
                        password(pass);
                        strcpy(user[n].pass,pass);
                        printf("\nConfirm password :");password(pass);//gets(cpass);
                        if(strcmp(user[n].pass,pass)==0)
                          	printf("\n\n...Confirm password...");
                        else{
                        	printf("\n\n...Invalid password...");
                           puts("\nPlaese, <Enter> to write password again...");
                           getch();
                           goto a;
                           }
                        n++;
                     }while(getch()!=13);
                  		goto B;
                  case '2':
                        int f;
                        int deposit,withdraw;
                        int amount;			//amount=money to trainsfer
                        char pn[15]; 		//pn=phone_number reciever
                        b:clrscr();
                        puts("\n......SIGN IN.......\n");
                        printf("\ninput your password :");password(pass);
                            for(i=0;i<n;i++)
                            {  
                            	f=0;
                        		if(strcmp(user[i].pass,pass)==0)
                           		{
                              		f=1;
                                    printf("\n...Login sucessed....");
                                 
                              		printf("\n\nID : %d\n",i+1);
                                    printf("Name : %s\n",user[i].name);
                                    printf("Gender : %s\n",user[i].gender);
                                    printf("Phone number : %s\n",user[i].phone);
                                    user[i].balance=0;
                                    printf("Your balance : %d\n\n",user[i].balance);
                                    getch();
                                    C:clrscr();
                                    puts("1.deposit");
                                    puts("2.withdraw");
                                    puts("3.trainsfer");
                                    puts("4.Quit");
                                    switch(getch())
                                    {
                                 		case '1':printf("\nDeposit :");scanf("%d",&deposit);
                                    			user[i].balance+=deposit;
                                             money=money+deposit;
                                          	printf("your balance : %d\n",user[i].balance);
                                          	getch();goto C;
                                       case '2':printf("\nwithdraw :");scanf("%d",&withdraw);
                                    				if(withdraw<=user[i].balance)
                                                {
                                                	user[i].balance-=withdraw;
                                                   money=money-withdraw;
                                                }
                                                else
                                             		puts("no't enough money");
                                                printf("your balance :%d\n",user[i].balance);
                                            
                                               getch(); goto C;
                                        case '3':
                                        	   puts("......................................");
                                    			printf("\nAmount :");scanf("%d",&amount);
                                             user[i].balance-=amount;
                                             printf("\nTrainsfer to :");scanf("%s",&pn);

                                             for(j=0;j<=n;j++)
                                             {
                                             	if(strcmp(user[j].phone,pn)==0)
                                                {
                                                	f=1;
                                                   user[j].balance+=amount;
                                                  break;
                                                }
                                             }
                                             
                                             getch();
                                             goto C;
                                    case '4':goto B;
                                  }
                              }
                            }
                            if(f==0)
                            {
                            	puts("......Wrong password.......");
                            }
                        getch();
                  		goto B;
                  case 'l':
                  case 'L':goto A;
               }
               
       case '3':clrscr();
       			puts("\n......Show all record......\n\n");
       			puts("ID\tName\tGender\tPhone\tBalance");
       			for(i=0;i<n;i++)
               {
                 printf("......................................\n");
                 printf("%s\t%s\t%s\t%s\t%d\n",user[i].id,user[i].name,user[i].gender,user[i].phone,user[i].balance);	
               }getch();
       			goto A;
               
       case '4':clrscr();	// search have 3 option:
       			puts(".......UPDATE AND DELETE......\n");
       			char id[10];
               int f;
               
               printf("Input id :");scanf("%s",&id);
               for(i=0;i<n;i++)
               {	f=0;
                 if(strcmp(user[i].id,id)==0)
                 {
                 		f=1;
                 		printf("ID : %s\n",user[i].id);
                     printf("Name : %s\n",user[i].name);
                     printf("Gender : %s\n",user[i].gender);
                     printf("Phone_number : %s\n",user[i].phone);
                     printf("Password : %s\n",user[i].pass);
                     getch();
                     D: clrscr();
                     puts("1.delete");
                     puts("2.Update");
                     puts("L.leave");

                     switch(getch())
                     {
                     	case '1':
                        			int j;
                                 for(j=i;j<n;j++)
                                 {
                                 	user[j]=user[j+1];
                                 }n--;
                                 puts("\n.....Delete successed........!");
                                 getch();
                                 goto D;
                        case '2':
                        			getch();
                        			E:clrscr();
                        			puts("1.Update name");
                                 puts("2.Update gender");
                                 puts("L.leave");

                                 switch(getch())
                                 {
                                 	case '1':char name[20];
                                    			printf("New name : ");fflush(stdin);gets(name);
                                             strcpy(user[i].name,name);
                                             getch();
                                             goto E;
                                    case '2':char sex[10];
                                    			printf("New Gender : ");fflush(stdin);gets(sex);
                                             strcpy(user[i].gender,sex);
                                             getch();
                                             goto E;
                                    case 'l':
                                    case 'L':goto D;
                                 }
                        case 'l':
                        case 'L':goto A;
                     }
                 }
               }
               if(f==0){	puts(" No data");	getch(); goto A;}
         
                         
   }
	getch();
}
