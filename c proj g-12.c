// Bank Employee Management Project
/*

Members :

Lalit Chaudhary (AP21110010424)

Bhavana Sree Vemuri (AP21110010425)

Venkata Krishna Saadhvik Muddana (AP21110010426)

*/

#include<stdio.h>
#include<stdlib.h>




struct employee
{
    int emp_id;
    char name[30];
    char dep[10];
    char gender;
    char phone_num[15];
    char dob[15];
    char join_date[10];
    int age;
    float salary;
    char address[500];

};

typedef struct employee Emp;






void Insert();
void Display();
void Search();
void Update();
void Delete();
void main_menu();
void login();
void end();






int main()
{
    login();
    main_menu();
}





void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do{
        printf("\n__________________________________________________________________________________________________________\n");
        printf("\n ::::::::::::::::::::::::::::::::::::::::::::::::  LOGIN  :::::::::::::::::::::::::::::::::::::::::::::::\n");
        printf(" \n                                            ENTER USERNAME : ");
        scanf("%s", &uname);
        printf(" \n                                            ENTER PASSWORD : ");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13)
            break;
	    else
            printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0;

    if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
    {
        printf("\n__________________________________________________________________________________________________________\n");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  WELCOME TO TRIDENT BANK EMPLOYEE MANAGEMENT SYSTEM  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n__________________________________________________________________________________________________________\n");
        printf("\n\nC-Language Project\nGroup Members: \n\n1.Lalit Chaudhary (AP21110010424)\n2.Bhavana Sree Vemuri (AP21110010425)\n3.Venkata Krishna Saadhvik Muddana (AP2111001042)\n");
        printf("\n LOADING PLEASE WAIT... \n");
        for(i=0; i<5; i++)
        {
            printf(".");
            Sleep(500);
        }
        printf("\n\n\n                                       Press any key to continue...\n\n");
        getch();
        break;
	}
	else
	{
		printf("\nSORRY !!!!  LOGIN IS UNSUCESSFUL");
		printf("\nIncorrect Credentials !!!\n");
		a++;



	}
}
	while(a<=3);
	if (a>3)
	{
		printf("\nSorry you have entered the wrong username and password 4 times !!!\n");
		printf("Your Session has been terminated due to attempted incorrect logins !!!\n");
		end();

		}

}






void main_menu()
{

    int ch;
    do
    {
        printf("\n\n\n");
        printf("~~~~~~  Main Menu  ~~~~~~\n\n");
        printf("\n1. Add New Employee Record\n\n2. Display All Records\n\n3. Search Specific Employee Record\n\n4. Update Employee Record\n\n5. Delete Employee Record\n\n6. Exit The Program \n\n\nEnter your Choice : ");
        scanf("%d", &ch);
        printf("\n\n\n");

        switch (ch)
        {
        case 1:Insert();
            break;
        case 2:Display();
            break;
        case 3:Search();
            break;
        case 4:Update();
            break;
        case 5:Delete();
            break;
        case 6:
            end();
        default:
            printf("\nIncorrect Choice !!!\nTry Again...!\n");
        }
    } while (ch != 6);
}





void Insert()
{
    FILE *fp;
    fp=fopen("emp.txt","a+");
    if(fp==NULL)
    {
        printf("\nUnable to access file........Try Again....!!");
    }
    else
    {
        printf("\n_______________________________________________\n");
        printf("\n~~~~~~~~~~~ INSERT EMPLOYEE RECORDS ~~~~~~~~~~~\n");
        printf("\n_______________________________________________\n");
        int n,a;
        printf("\nEnter the number of Records you want to insert : ");
        scanf("%d",&n);
        Emp *e;
        e=(Emp*)calloc(n,sizeof(Emp));


        for(int i=0;i<n;i++)
        {
            printf("\n\n~~~~~~~~~~~~~~~~~~ EMPLOYEE - %d ~~~~~~~~~~~~~~~~~~\n",i+1);

            printf("\nEnter Employee ID : ");
            scanf("%d",&e[i].emp_id);

            printf("\nEnter Full Name of Employee : ");
            scanf("\n");
            scanf("%[^\n]s",&e[i].name);


            printf("\nEnter Department of Employee : ");
            scanf("\n");
            scanf("%[^\n]s",&e[i].dep);


            printf("\nEnter Employee Age : ");
            scanf("%d",&a);
            if (a<18)
            {
                printf("\n\nUnder Age for job !!!\nGive Age above 18\n");
                printf("\nEnter Employee Age : ");
                scanf("%d",&e[i].age);
            }

            else if(a>60)
            {
                printf("\n\nOver Aged for job !!!\nGive age below 60\n");
                printf("\nEnter Employee Age : ");
                scanf("%d",&e[i].age);
            }

            else
            {
                e[i].age=a;
            }


            printf("\nEnter Employee Salary : ");
            scanf("%f",&e[i].salary);


            printf("\nEnter Employee Gender : ");
            scanf("%s",&e[i].gender);


            printf("\nEnter Employee Phone Number : ");
            scanf("%s",&e[i].phone_num);


            printf("\nEnter Employee DOB : ");
            scanf("\n");
            gets(e[i].dob);

            printf("\nEnter Employee joining date : ");
            scanf("\n");
            gets(e[i].join_date);

            printf("\nEnter Employee Address : ");
            scanf("\n");
            scanf("%[^\n]s",&e[i].address);



            fwrite(e+i,sizeof(Emp),1,fp);
        }
        printf("\n~~~~~~~~~~~ RECORD INSERTED SUCCESFULLY ~~~~~~~~~~~\n");
    }
    fclose(fp);
}






void Display()
{
    FILE *fp;
    fp=fopen("emp.txt","r");
    Emp e;
    if(fp==NULL)
    {
        printf("\nUnable to access file ........Try Again........ !!");
    }

    else
    {
        printf("\n_______________________________________________________\n");
        printf("\n~~~~~~~~~~~ DISPLAY ALL EMPLOYEE RECORD ~~~~~~~~~~~\n");
        printf("\n_______________________________________________________\n\n");
        printf("\n\n_______________________________________________________________________________________________________________________________________________________________________________________________");
        char *h[] = {"ID","NAME","GENDER","DOB","DEPARTMENT","JOIN DATE","AGE","SALARY","PHONE NUMBER","ADDRESS"};
        printf("\n\n\t%-5s %-30s %-8s %-15s %-20s %-10s %-8s %-25s %-20s %-30s\n",h[0],h[1],h[2],h[3],h[4],h[5],h[6],h[7],h[8],h[9]);
        printf("_______________________________________________________________________________________________________________________________________________________________________________________________\n\n");
        while(fread(&e, sizeof(Emp),1,fp))
        {
            /*printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n\n\n\tID \t: %d \n\n",e.emp_id);
                printf("\tNAME \t: %s \n\n",e.name);
                printf("\tGENDER \t: %c \n\n",e.gender);
                printf("\tDOB \t: %s \n\n",e.dob);
                printf("\tPHONE NUMBER \t: %d \n\n",e.phone_num);
                printf("\tAGE \t: %d \n\n",e.age);
                printf("\tJOIN DATE \t: %s \n\n",e.join_date);
                printf("\tDEPARTMENT \t: %s \n\n",e.dep);
                printf("\tSALARY \t: %0.2f \n\n",e.salary);
                printf("\tADDRESS \t: %s \n\n\n\n",e.address);
                printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");*/
            printf("\n\t%-5d %-30s %-8c %-15s %-20s %-10s %-8d %-25.2f %-20s %-30s\n",e.emp_id,e.name,e.gender,e.dob,e.dep,e.join_date,e.age,e.salary,e.phone_num,e.address);
        }
    }
    fclose(fp);
}







void Search()
{
    FILE *fp;
    fp=fopen("emp.txt","r");
    if(fp==NULL)
    {
        printf("\nUnable to access file ........Try Again........ !!");
    }
    else
    {
        printf("\n_______________________________________________________\n");
        printf("\n~~~~~~~~~~~ DISPLAY SEPECIFIC EMPLOYEE RECORD ~~~~~~~~~~~\n");
        printf("\n_______________________________________________________\n\n");
        Emp e;
        printf("\nEnter the Employee ID you want to search : ");
        int ID,found=0;
        scanf("%d",&ID);

         while(fread(&e, sizeof(Emp),1,fp))
        {
            if(e.emp_id==ID)
            {
                printf("\nEmployee Record is Found !!!!!!!!\n");
                printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n\n\n\tID \t: %d \n\n",e.emp_id);
                printf("\tNAME \t: %s \n\n",e.name);
                printf("\tGENDER \t: %c \n\n",e.gender);
                printf("\tDOB \t: %s \n\n",e.dob);
                printf("\tPHONE NUMBER \t: %s \n\n",e.phone_num);
                printf("\tAGE \t: %d \n\n",e.age);
                printf("\tJOIN DATE \t: %s \n\n",e.join_date);
                printf("\tDEPARTMENT \t: %s \n\n",e.dep);
                printf("\tSALARY \t: %0.2f \n\n",e.salary);
                printf("\tADDRESS \t: %s \n\n\n\n",e.address);
                printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                found=1;
                break;
            }
        }
        if(found==0)
        {
            printf("\nEmployee Record not found ........Try Again........ !!");
        }
    }
    fclose(fp);
}






void Update()
{
    FILE *fp,*fp1;

    if(fp==NULL)
    {
        printf("\nUnable to access file ........Try Again........ !!");
    }
    else
    {
        printf("\n_______________________________________________________\n");
        printf("\n~~~~~~~~~~~ UPDATE EMPLOYEE RECORD ~~~~~~~~~~~\n");
        printf("\n_______________________________________________________\n\n");
        fp=fopen("emp.txt","r");
        fp1=fopen("temp.txt","w");
        Emp e;
        int ch;
        printf("\nEnter the Employee ID you want to Update : ");
        int ID,found=0;
        scanf("%d",&ID);

         while(fread(&e, sizeof(Emp),1,fp))
        {
             if(e.emp_id==ID)
            {
                printf("\n\nCurrent Details Available for this Employee ID -  %d : \n",ID);
                printf("\n\nEmployee Record is Found !!!!!!!!\n\n\n");
                printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n\n\n\tID \t: %d \n\n",e.emp_id);
                printf("\tNAME \t: %s \n\n",e.name);
                printf("\tGENDER \t: %c \n\n",e.gender);
                printf("\tDOB \t: %s \n\n",e.dob);
                printf("\tPHONE NUMBER \t: %d \n\n",e.phone_num);
                printf("\tAGE \t: %d \n\n",e.age);
                printf("\tJOIN DATE \t: %s \n\n",e.join_date);
                printf("\tDEPARTMENT \t: %s \n\n",e.dep);
                printf("\tSALARY \t: %0.2f \n\n",e.salary);
                printf("\tADDRESS \t: %s \n\n\n\n",e.address);
                printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                found=1;

                do
                {
                printf("\n________________________________\n\n\n");
                printf("\nWhat would you like to update : \n\n\n1. Name\n\n2. Department\n\n3. Age\n\n4. Salary\n\n5. Phone Number\n\n6. Address\n\n7.All Information !\n\n8.Exit\n\n\nEnter Your Choice : ");
                scanf("%d",&ch);
                printf("\n\n");
                switch(ch)
                {
                    case 1:
                        printf("\nEnter Full Name of Employee : ");
                        scanf("\n");
                        gets(e.name);
                        break;

                    case 2:
                        printf("\nEnter Department of Employee : ");
                        scanf("\n");
                        scanf("%s",&e.dep);
                        break;

                    case 3:
                        printf("\nEnter Employee Age : ");
                        scanf("%d",&e.age);
                        break;

                    case 4:
                        printf("\nEnter Employee Salary : ");
                        scanf("%f",&e.salary);
                        break;

                    case 5:
                        printf("\nEnter Employee Phone Number : ");
                        scanf("%s",&e.phone_num);
                        break;

                    case 6:
                        printf("\nEnter Employee Address : ");
                        scanf("\n");
                        gets(&e.address);
                        break;

                    case 7:
                        printf("\nEnter Employee ID : ");
                        scanf("%d",&e.emp_id);
                        printf("\nEnter Full Name of Employee : ");
                        scanf("\n");
                        gets(e.name);
                        printf("\nEnter Department of Employee : ");
                        scanf("\n");
                        scanf("%s",&e.dep);
                        printf("\nEnter Employee Age : ");
                        scanf("%d",&e.age);
                        printf("\nEnter Employee Salary : ");
                        scanf("%f",&e.salary);
                        printf("\nEnter Employee Gender : ");
                        scanf("%s",&e.gender);
                        printf("\nEnter Employee Phone Number : ");
                        scanf("%s",&e.phone_num);
                        printf("\nEnter Employee DOB : ");
                        scanf("\n");
                        gets(&e.dob);
                        printf("\nEnter Employee joining date : ");
                        gets(&e.join_date);
                        printf("\nEnter Employee Address : ");
                        gets(&e.address);
                        break;

                    case 8:
                        break;

                    default: printf("\nIncorrect Choice............Try Again....!\n"); break;
                }
                if(ch!=8)
                {
                    printf("\nWould You like to do some more updations with this record...{Y/N) : ");
                    char c;
                    scanf("\n");
                    scanf("%c",&c);
                    if(c=='y' || c=='Y')
                    {
                      continue;
                    }
                    else
                    {
                        break;
                    }
                }

                }while (ch!=8);

            }
            fwrite(&e,sizeof(Emp),1,fp1);
        }
        fclose(fp);
        fclose(fp1);

        if(found==1)
        {
             fp=fopen("emp.txt","w+");
             fp1=fopen("temp.txt","r+");
             while(fread(&e, sizeof(Emp),1,fp1))
             {
                  fwrite(&e,sizeof(Emp),1,fp);
             }
            fclose(fp);
            fclose(fp1);
            if(ch!=8)
            {
            printf("\nRecord Updated Successfully..........!\n");
            }
        }
        else
        {
            printf("\nThe Eployee ID is not found........Try Again.........!\n");
        }
    }
}






void Delete()
{
    FILE *fp,*fp1;

    if(fp==NULL)
    {
        printf("\nUnable to access file........Try Again....!!");
    }
    else
    {
        printf("\n_______________________________________________________\n");
        printf("\n~~~~~~~~~~~ DELETE EMPLOYEE RECORD ~~~~~~~~~~~\n");
        printf("\n_______________________________________________________\n\n");
        fp=fopen("emp.txt","r");
        fp1=fopen("temp.txt","w");
        Emp e;
        printf("\nEnter the Employee ID you want to Delete : ");
        int ID,found=0;
        scanf("%d",&ID);






        while(fread(&e, sizeof(Emp),1,fp))
        {
            if(e.emp_id==ID)
            {
                found=1;
            }
            else
            {
                 fwrite(&e,sizeof(Emp),1,fp1);
            }
        }
        fclose(fp);
        fclose(fp1);

        if(found==1)
        {
            fp=fopen("emp.txt","w+");
            fp1=fopen("temp.txt","r+");
             while(fread(&e, sizeof(Emp),1,fp1))
             {
                  fwrite(&e,sizeof(Emp),1,fp);
             }
              fclose(fp);
             fclose(fp1);
             printf("\nRecord Deleted Successfully..........!\n");
        }
        else
        {
            printf("\nThe Eployee ID is not found........Try Again.........!\n");
        }
    }
}





void end()
{
    printf("Thanks for using our program !!!\n");
    printf("Have a great day !!!\n");
    exit(10);
}
