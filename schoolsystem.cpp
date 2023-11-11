#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
/**********declaration of functions********/
void welcome();
void header();
void login();
void menu();
void add();
void list();
void edit();
void search();
void del();
void end();
/***********structure***********/
struct student
{
	 char name[30];
	 char fname[20];
	 char gender[10];
	 int age;
	 char Class[5];
	 int rollno;
	 char address[20];
	 char email[20];

};
struct student st;
int main()
{
	welcome();
	header();
     login();
}
void welcome()
{
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t*********************************************************");
    printf("\n\t\t\t\t\t\t\t*\t\t\tWELCOME TO \t\t\t*");
    printf("\n\t\t\t\t\t\t\t*\t\t\t\t\t\t\t*");
    printf("\n\t\t\t\t\t\t\t* \t\t STUDENT MANAGEMENT SYSTEM \t \t*");
     printf("\n\t\t\t\t\t\t\t*********************************************************");
     printf("\n\t\t\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n\n\n\n\n\n\t\t\tPress Enter key to continue..........\n");
    getch();
    system("cls");
}

void header()
{
   printf("\n\n\n\n\t\t\t\t\t\t######################################################################");
    printf("\n\t\t\t\t\t\t!!!!!!!!!!!!!!\t\t\t\t\t\t!!!!!!!!!!!!!!");
    printf("\n\t\t\t\t\t\t\t\t\t  TAGORE INTERNATIONAL SCHOOL");
    printf("\n\t\t\t\t\t\t!!!!!!!!!!!!!!\t\t\t\t\t\t!!!!!!!!!!!!!!");
    printf("\n\t\t\t\t\t\t######################################################################");
}

void login()
{
	char username[20];
	char passcode[10];
	char setname[20]="jasdev";
	char setcode[20]="443322";
	int counter=0;
do
{
	printf("\n\n\n\n\n\t\t\t\t\t\tEnter the username: ");
	scanf("%s",username);
	printf("\n\n\t\t\t\t\t\tEnter passcode: ");
	scanf("%s",passcode);
	  if(strcmp(username,setname)==0&&strcmp(passcode,setcode)==0)
     {
         printf("\n\n\t\t\t\t\t\t\tLOGIN SUCCESSFULLY............");
         getch();
        menu();
         break;
     }
     else
     {
        printf("\n\n\t\t\t\t\t\tINCORRECT USERNAME AND PASSWORD.....!!\n");
        counter++;
        getch();
     }
}while(counter<3);
if(counter>=3)
{
	printf("/n/n/n\t\t\t\t\t");
	printf("!!!!!your attempt is failed!!!!!\n");
	printf("\t\t\t\t\t");
	printf("you can't login now....");
	exit(0);
}

}
/*****************************main menu of program*****************************************************************/

void menu()
{   
    system("cls");
	header();
	printf("\n");
	int choice;
	   printf("\n\n\n\n\t\t\t\t\t\t\t\t!!!! MAIN MENU!!!!");
    printf("\n\n\n\t\t\t\t\t\t\t\t 1.Add student record.");
    printf("\n\n\t\t\t\t\t\t\t\t 2.list student record.");
    printf("\n\n\t\t\t\t\t\t\t\t 3.Edit student record.");
    printf("\n\n\t\t\t\t\t\t\t\t 4.Search student record.");
    printf("\n\n\t\t\t\t\t\t\t\t 5.Delete student record.");
    printf("\n\n\t\t\t\t\t\t\t\t 6.Exit.\n");
 option:  printf("\n\n\t\t\t\t Enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
    	case 1: 
    	      add();
    	      break;
    	case 2:
    		  list();
    		  break;
    	case 3:
    		  edit();
    		  break;
    	case 4:
    		search();
    		break;
    	case 5:
    		del();
    		break;
    	case 6: 
    	     end();
    	     break;
    	default: 
    	     printf("\t\t\t\tEnter correct choice");
    	     goto option;
    	     break;
    		
	}
}
/******************************** addition of record******************************/
void add()
{   
	system("cls");
	char ch;
	header();
	FILE *fp;
	fp=fopen("stfile.txt","a");
	printf("\n\n\n\n\t\t\t\t\t\t\t\t\t!!!!ADD STUDENTS RECORD!!!!\n");
	printf("\t\t\t\t\tEnter Student name: ");
	scanf("%s",st.name);
	printf("\n");
	printf("\t\t\t\t\tEnter Father's name: ");
	scanf("%s",st.fname);
	printf("\n");
	printf("\t\t\t\t\tEnter Gender: ");
	scanf("%s",&st.gender);
	printf("\n");
	printf("\t\t\t\t\tEnter Student age: ");
	scanf("%d",&st.age);
	printf("\n");
	printf("\t\t\t\t\tEnter Student class: ");
	scanf("%s",st.Class);
	printf("\n");
	printf("\t\t\t\t\tEnter student rollno: ");
	scanf("%d",&st.rollno);
	printf("\n");
	printf("\t\t\t\t\tEnter student address: ");
	scanf("%s",st.address);
	printf("\n");
	printf("\t\t\t\t\tEnter student email id: ");
	scanf("%s",st.email);
	printf("\n");
	
	fprintf(fp,"%s %s %s %d %s %d %s %s\n",st.name,st.fname,st.gender,st.age,st.Class,st.rollno,st.address,st.email);
	printf("\n\t\t\t\t\t!!!!!!!!!!!!!!!!!!!!Record Added Successfully!!!!!!!!!!!!!!!!!!!!!!!!!");
	fclose(fp);
	getch();
	fflush(stdin);
	printf("\n\t\tDo You Want To Add More Record(y/n)......");
	scanf("%c",&ch);
	if(ch=='y'||ch=='Y')
	{
		add();
	}
	else
	{
		menu();
	}
	
	
}
/**********************************list of records*********************************************/
void list()
{
	system("cls");
	header();
	FILE *fp;
	fp=fopen("stfile.txt","r");
	printf("\n\n\n\n\t\t\t\t\t\t\t\t\t!!!!!!!!!LIST OF STUDENTS RECORD!!!!!!!!!\n");
	printf("=========================================================================================================================================================================\n");
	printf("\t  Name\t\t\t Father name\t\t Gender\t\t Age\t Class\t\t RollNo\t\t Address\t\t Email \n");
	printf("__________________________________________________________________________________________________________________________________________________________________________\n");
	while(fscanf(fp,"%s %s %s %d %s %d %s %s",st.name,st.fname,st.gender,&st.age,st.Class,&st.rollno,st.address,st.email)!=EOF)
     {
     	printf("\t  %s\t\t\t   %s\t\t\t %s\t\t %d\t %s\t\t %d\t\t %s\t\t\t%s\t\t\n",st.name,st.fname,st.gender,st.age,st.Class,st.rollno,st.address,st.email);
	 }
	 printf("\n\n\t\t\t\t\tpress any key to continue.............");	
	 fclose(fp);
	 getch();
	 menu();
	 
}
/****************************************update record*****************************************************/
void edit()
{
	system("cls");
	header();
	char sname[20];
	char ch;
	char val;
	FILE *fp,*tm;
	fp=fopen("stfile.txt","r");
	tm=fopen("temp.txt","w+");
	 printf("\n\n\n");
   printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!edit student's records!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  printf("\n\t\t\t\t\t\tEnter name of student: ");
  scanf("%s",sname);
  printf("\n");
while(fscanf(fp,"%s %s %s %d %s %d %s %s",st.name,st.fname,st.gender,&st.age,st.Class,&st.rollno,st.address,st.email)!=EOF)
{
	if(strcmp(st.name,sname)==0)
	{
			printf("\t\t\t\t\t\t\t\t****existing record****");
         	printf("\n\n\t\t");
         	printf("\t%s\t\t %s\t\t %s\t\t %d\t\t %s\t\t %d\t\t %s\t\t %s\t\t\n",st.name,st.fname,st.gender,st.age,st.Class,st.rollno,st.address,st.email);
         	printf("\n\n");
         	   printf("\t\t\t\t\t\t\tProceed to change record(y/n): \n\n");
         	   val=getche();
         	   if(val=='y')
         	   {
		
         	   
         	   
	          printf("\t\t\t\t\t\t\tEnter new record \n\n");
	          printf("\t\t\t\t\tEnter Student name: ");
	scanf("%s",st.name);
	printf("\n");
	printf("\t\t\t\t\tEnter Father's name: ");
	scanf("%s",st.fname);
	printf("\n");
	printf("\t\t\t\t\tEnter Gender: ");
	scanf("%s",&st.gender);
	printf("\n");
	printf("\t\t\t\t\tEnter Student age: ");
	scanf("%d",&st.age);
	printf("\n");
	printf("\t\t\t\t\tEnter Student class: ");
	scanf("%s",st.Class);
	printf("\n");
	printf("\t\t\t\t\tEnter student rollno: ");
	scanf("%d",&st.rollno);
	printf("\n");
	printf("\t\t\t\t\tEnter student address: ");
	scanf("%s",st.address);
	printf("\n");
	printf("\t\t\t\t\tEnter student email id: ");
	scanf("%s",st.email);
	printf("\n\n");
	
	printf("\t\t\tPress 'u' to update!!!!! ");
	ch=getche();
	 if(ch=='u')
	 {
	 		fprintf(tm,"%s %s %s %d %s %d %s %s\n",st.name,st.fname,st.gender,st.age,st.Class,st.rollno,st.address,st.email); //changed data
	printf("\n\t\t\t\t\t!!!!!!!!!!!!!!!!!!!!Record Updated Successfully!!!!!!!!!!!!!!!!!!!!!!!!!");
	 }
    }
    else{printf("\t\t\t\t\tpress enter for menu!!!!!!!!!!");
    getch();
    menu();}
	}
	          
	
	else
	{
		fprintf(tm,"%s %s %s %d %s %d %s %s\n",st.name,st.fname,st.gender,st.age,st.Class,st.rollno,st.address,st.email); //orignal data
	}

}

fclose(fp);
fclose(tm);
remove("stfile.txt");
rename("temp.txt","stfile.txt");
	getch();
	menu();
}
/************************************search record***********************************************************/
void search()
{
	system("cls");
	header();
	char sname[20];
	char val;
	int flag=0;
	FILE *fp;
	fp=fopen("stfile.txt","r");

	 printf("\n\n\n");
   printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Search student's records!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  printf("\n\t\t\t\t\t\tEnter name of student: ");
  scanf("%s",sname);
  printf("\n");
while(fscanf(fp,"%s %s %s %d %s %d %s %s",st.name,st.fname,st.gender,&st.age,st.Class,&st.rollno,st.address,st.email)!=EOF)
{
	if(strcmp(st.name,sname)==0)
	{  flag=1;
			printf("\t\t\t\t\t\t\t\t*********student's record********");
         	printf("\n\n\t\t");
         
         	 printf("\n\n\t\t\t\t\t\t");
         	     printf("Student's name : %s",st.name);
         	     printf("\n\n\t\t\t\t\t\t");
         	    printf("Father's name : %s",st.fname);
         	   printf("\n\n\t\t\t\t\t\t");
         	    printf("Gender : %s",st.gender);
         	     printf("\n\n\t\t\t\t\t\t");
         	    printf("Student's Age : %d",st.age);
         	      printf("\n\n\t\t\t\t\t\t");
         	    printf("Student's Class : %s",st.Class);
          printf("\n\n\t\t\t\t\t\t");
         	    printf("Roll no : %d",st.rollno);
         	      printf("\n\n\t\t\t\t\t\t");
         	    printf("Address: %s",st.address);
         	      printf("\n\n\t\t\t\t\t\t");
         	    printf("Email id: %s",st.email);
         	 
}

}
 if(!flag)
 {
 	printf("\t\t\t\t\t\t\t!!!!! record not exist!!!!!!\n");
 	printf("\t\t\t\t\t\t\t press any key to continue.......");
 	getch();
 	menu();
 }


printf("\n\n\t\t\t\t\t\tDo you want to search more records(y/n)");
val=getche();
if(val=='y')
{
	search();
}
else
{
	printf("\n\t\t\t\t\t\t Press enter for menu..........");
	getch();
	menu();
}

		
}

/************************************************************deletion of records******************************************************/
void del()
{
	char sname[20];
		int flag=0;
		char val;
	system("cls");
	header();
	
	FILE *fp,*tm;
	fp=fopen("stfile.txt","r");
	tm=fopen("temp.txt","w+");
		printf("\n\n\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Delete records!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	 printf("\n\t\t\t\t\t\tEnter name of student: ");
	 fflush(stdin);
  scanf("%s",sname);
  printf("\n");
while(fscanf(fp,"%s %s %s %d %s %d %s %s",st.name,st.fname,st.gender,&st.age,st.Class,&st.rollno,st.address,st.email)!=EOF)
{
	
if(strcmp(st.name,sname)!=0){

fprintf(tm,"%s %s %s %d %s %d %s %s\n",st.name,st.fname,st.gender,st.age,st.Class,st.rollno,st.address,st.email);
}
else
{
printf("%s %s %s %d %s %d %s %s\n",st.name,st.fname,st.gender,st.age,st.Class,st.rollno,st.address,st.email);	
flag=1;
}
}
if(flag==0)
{
	printf("\n\t\t\t\t**********record not found*************");
	getch();
	menu();
}
else
{
	
fclose(fp);
fclose(tm);
remove("stfile.txt");
rename("temp.txt","stfile.txt");
printf("\n\t\t\t\t!!!!!!!!Record Deleted successfully!!!!!!!!!!!!!! ");
printf("\n\n\t\t\t\t\tpress any key for menu.........");
	getch();
	menu();
}
}

/*************************************************************exit****************************************************************/
void end()
{
	system("cls");
	header();
	printf("\n\n\n\n");
	printf("\t\t\t\t**************************************************************************************");
	printf("\n\t\t\t\t*                                                                                    *");
    printf("\n\t\t\t\t*                                                                                    *");
    printf("\n\t\t\t\t*                     !!!!!!!!!THANK YOU FOR USING :) !!!!!!!!!!                     *");
   	printf("\n\t\t\t\t*                                                                                    *");
   	printf("\n\t\t\t\t*                                                                                    *");
   	printf("\n\t\t\t\t**************************************************************************************");
   	getch();
   	exit(0);
   	system("cls");
}
