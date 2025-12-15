#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact{
    char name[50];
    char phone_number[20];
    char email[50];
};

/* ---------- ADD CONTACT ---------- */
void Add_contact()
{
     FILE *file = fopen("contacts.txt","a");
 if (!file) {
        printf("error opening the file.\n");
        return;
 }
    struct contact c;
    printf("enter name = ");
    scanf("%s",c.name);
    printf("enter phone_number = ");
    scanf("%s",c.phone_number);
    printf("enter email = ");
    scanf("%s",c.email);

fprintf(file, "%s|%s|%s\n",c.name,c.phone_number,c.email);
fclose(file);

printf("Contact added successfully!!!\n");    

}

/* ---------- VIEW CONTACTS ---------- */
void View_contact()
{
    FILE *file = fopen("contacts.txt","r");
 if (!file) {
        printf("No contacts found\n");
        return;
    }
    char line[200];
     char name[50];
    char phone_number[20];
    char email[50];
    printf("\n------- Contact list--------\n");
    
    while (fgets(line, sizeof(line), file))
    {
       sscanf(line, "%[^|]|%[^|]|%[^\n]", name, phone_number, email);

        
        printf("\nName : %s\n",name);
        printf("\nPhone_number : %s\n",phone_number);
        printf("\nEmail : %s\n",email);
        
        printf("---------------------------------------\n");
        
    }
    fclose(file);
}

/* ---------- SEARCH CONTACT ---------- */
void Search_contact()
{
  FILE *file = fopen("contacts.txt","r");
 if (!file) {
        printf("No contacts found\n");
        return ;
    }
    char Searchname [50];
    char line[200];
    char name[50];
    char phone_number[20];
    char email[50];
    int found = 0;
    
    printf("Enter name of contact you want to find = ");
    scanf("%s",Searchname);
 while( fgets(line, sizeof(line), file))
    {
        sscanf(line, "%[^|]|%[^|]|%[^\n]", name, phone_number, email);
        
        if(strcmp(name,Searchname) == 0)
        {
            printf("\n------------Contact found-----------\n!");
            printf("\nName : %s\n",name);
            printf("\nPhone_number : %s\n",phone_number);
            printf("\nEmail : %s\n",email);
            printf("---------------------------------------\n");
            found = 1;
           break;
        }
    }
       fclose(file);
}


/* ---------- DELETE CONTACT ---------- */
void Delete_contact()
{
     FILE *file = fopen("contacts.txt","r");
 FILE *temp = fopen("temp.txt","w");
 if (file == NULL || temp == NULL) {
        printf("No contacts found\n");
        return ;
    }
    char deletename [50];
    char line[200];
    char name[50];
    char phone_number[20];
    char email[50];
    int found = 0;
    
    printf("Enter name of contact you want to delete= ");
    scanf("%s",deletename);
while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%[^|]|%[^|]|%[^\n]", name, phone_number, email);
        
        if(strcmp(name,deletename) == 0)
        {
            found =1;
            continue;
        }
       
         fprintf(temp,"%s|%s|%s\n",name,phone_number,email); 
    }
    fclose(file);
   fclose(temp);
   
       remove("contacts.txt");
       rename ("temp.txt","contacts.txt");
if (found)
{
printf("Contact deleted successful!!");
}
else
{
printf("contact not found");
}    
}


/* ---------- UPDATE CONTACT ---------- */
void Update_contact()
{
    FILE *file = fopen("contacts.txt","r");
 FILE *temp = fopen("temp.txt","w");
 if (file == NULL || temp == NULL) 
 {
        printf("No contacts found\n");
        return ;
 }
         char updatename [50];
    char line[200];
    char name[50];
    char phone_number[20];
    char email[50];
    int found = 0;
    
    printf("Enter name of contact you want to delete= ");
    scanf("%s",updatename);
    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%[^|]|%[^|]|%[^\n]", name, phone_number, email);
        
        if(strcmp(name,updatename) == 0)
        {
            found =1;
      printf("enter new name = ");
      scanf("%s",name);
      printf("enter new phone_number = ");
      scanf("%s",phone_number);
      printf("enter new email = ");
      scanf("%s",email);
      }
        fprintf(temp,"%s|%s|%s\n",name,phone_number,email);
    }
     fclose(file);
     fclose(temp);
     
    remove("contacts.txt");
    rename ("temp.txt","contacts.txt");
if (found)
{
printf("Contact updated successful!!");
}
else
{
printf("contact not found");
}   
}

/* ---------- MAIN FUNCTION ---------- */
int main ()
{    
    int choice;
        printf("\n-------- Contact Management System -------\n");
        printf("1. Add a contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete contact\n");
        printf("5. Update Contact\n");
        printf("6. Exit\n");
        printf("enter your choice = ");
        scanf("%d",&choice);
        getchar();
        
        if (choice == 1)
        {
           Add_contact(); 
        }
       else if (choice == 2)
        {
            View_contact(); 
        }
       else if (choice == 3)
        {
            Search_contact(); 
        }
       else if (choice == 4)
        {
            Delete_contact(); 
        }
       else if (choice == 5)
        {
           Update_contact(); 
        }
       else if (choice == 6)
        {
          printf("code exited sucessfully!!!");
          exit(0);
        }
        else
        {
            printf("invalid input!!");
}
}