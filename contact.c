#include <stdio.h>
#include<ctype.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
void listContacts(AddressBook *addressBook) {
          printf("\t\t\tList of Contacts:\t\n");
	  printf("---------------------------------------------------------------\n");
	  printf("%-8s%-20s%-20s%-20s\n","s.No","name","phone","mail");
	  printf("---------------------------------------------------------------\n");
    for (int i = 0; i < addressBook->contactCount; i++) {    //logic for printing array elemts in contact list.
          printf("%d.   %-20s%-20s%-20s\n", i + 1, 
		addressBook->contacts[i].name,
		addressBook->contacts[i].phone,
		addressBook->contacts[i].email);   }	    
    printf("---------------------------------------------------------------\n");
}    
void initialize(AddressBook *addressBook) {
    //addressBook->contactCount = 0;
    //populateAddressBook(addressBook)
     loadContactsFromFile(addressBook);
	
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}
void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

void createContact(AddressBook *addressBook){
    char name[20];
    while(1){
	     printf("Enter the Name : ");
	     scanf(" %[^\n]",name);//Reading the name
	     if (!isvalidName(name)) {//checking whether the name is valid or not .
                 printf("Invalid name! Please enter only alphabets.\n");
                 continue;   
	     }
             strcpy(addressBook->contacts[addressBook->contactCount].name, name);//store  in the array ie,addressBook array variable.
             printf("name added succussfull\n");
	     break;
    }
    char number[20];
     while(1){
             printf("Enter the Number ");
	     scanf(" %s",number);//read the number
	     if(!isvalidnumber(number))//checking whether the number is valid or not
	    {
		    printf("Invalid number ! please enter the correct number\n");
		    continue;
	    }
	    if(isDuplicatenumber(addressBook,number)!=-1)//checking whether the number is duplicate or not 
	    {
		    printf("Number already exists Try a different number.\n");
                    continue;
	    }
	     strcpy(addressBook->contacts[addressBook->contactCount].phone,number);//store phone number in the array ie,addressBook array variable.
	     printf("Number added succussfull\n");
	     break;
    } 
    char mail[20];
    while(1){
	    printf("Enter the mail\n");
	    scanf(" %s",mail); // Read the email ID
	    if(!isvalid_mail(mail))//checking whether the mail is valid or not
	    {
		    printf("Invalid email id ,please enter correct mailid\n");
	            continue;
	    }
	    if(isDuplicate_mail(addressBook,mail)!=-1)//checking whether the mail is duplicate or not
	    {
		    printf("MailId already exist,Try a different mailid\n");
                    continue;	    
            }
	     strcpy(addressBook->contacts[addressBook->contactCount].email,mail);// store mail in the array ie,addressBook array variable.
      	     printf("Emailid added successful\n");
	     printf("Contact added sucessful\n");
	     break;
    }
            (addressBook->contactCount)++;
}
int isvalidName(char*name)//these fun tells the name entered is valid or not.
{
	for(int i=0;name[i]!='\0';i++){
		if(!isalpha(name[i])&&(name[i]!=' '))
		{
			return 0;
		}
	}
	return 1;
}
int isDuplicateName(AddressBook *addressBook,char*name)//these fun tells about the name present in the list or not .
{
        int count=0;
        int i;
        for ( i = 0; i < addressBook->contactCount; i++)
        {
		if (strcmp(addressBook->contacts[i].name, name)==0)//comparing the particular name with list of contacts.
                {
                      printf("\n%s\n", addressBook->contacts[i].name);
                      printf("%s\n", addressBook->contacts[i].phone);
                      printf("%s\n", addressBook->contacts[i].email);
		      printf("\n");
                      count++;
                }

        }if(count==1) { return -2;}
        if(count>1) { return count;}
        if(count==0) {return -1;}
} 
int isvalidnumber(char*number)//these fun tells about the number is valid or not .
{
	int len=strlen(number);
	if(len!=10) return 0;
	for(int i=0;i<10;i++)
	{
		if(!isdigit(number[i]))
		{
			return 0;
		}
	}
	return 1;
}
int isDuplicatenumber(AddressBook *addressBook,char*number)//these fun tells about the number presnt in the list of contact or not.
{
	for (int i = 0; i < addressBook->contactCount; i++) 
	{
               if (strcmp(addressBook->contacts[i].phone, number) == 0)//comparing the number to the list of contacts .
	       {
                       printf("Number exisit\n ");
		      return i;
	       }
	}
	return -1;
}
int isvalid_mail(char*mail)//these fun tells about the mailid is valid or not .
{
       int len = strlen(mail);

    // Check minimum length required for "a@b.com" (7 chars)
    if (len < 7) return 0;

    // Check if first character is an alphabet (A-Z or a-z)
    if (!isalpha(mail[0])) return 0;

    // Check if email ends with ".com"
    if (strcmp(mail + len - 4, ".com") != 0) return 0;

    int at_pos = -1, dot_pos = -1;

    // Finding the positions of '@' and '.'
    for (int i = 0; i < len; i++)
    {
        if (mail[i] == '@') 
	{
            if (at_pos != -1) return 0; // More than one '@'
            at_pos = i;
        } else if (mail[i] == '.' && i > at_pos)
       	{
            dot_pos = i;
        } 
        // Allow only letters, digits, '@' and '.'
        else if (!isalnum(mail[i])) {
            return 0;
        }
    }

    // Check if '@' exists and is followed by at least one char before '.'
    if (at_pos < 1 || dot_pos < at_pos + 2) return 0;

    return 1; // Valid email
}
int isDuplicate_mail(AddressBook *addressBook,char*mail)//these fun tells about the mail is presnt in the contact list or not
{ 
	for (int i = 0; i < addressBook->contactCount; i++)
        {
               if (strcmp(addressBook->contacts[i].email,mail) == 0)//comparing mail to the list of contacts.
               {
                       printf("Mail exisit\n ");
                       return i;
               }
        }
        return -1;
}
void print_all(AddressBook *addressBook,int i)//it prints particular index of the contact list
{
	 printf("%s\n", addressBook->contacts[i].name); 
	 printf("%s\n", addressBook->contacts[i].phone);
	 printf("%s\n", addressBook->contacts[i].email);
			printf("\n"); }
	      
void searchContact(AddressBook *addressBook) 
{
    while (1) {  // Keep showing the search menu until user exits
        int searchResult = search_by(addressBook);

        if (searchResult ) {
            printf("Returning to main menu...\n");
            return;  // Exit search function
        }

    }
}
int fun_no(AddressBook *addressBook,char*name,char* number)//these fun gives correct list when u see multiple names found
{
	int flag=0;
	for(int i=0; i < addressBook->contactCount; i++)
	{
	if((strcmp(addressBook->contacts[i].name,name)==0))
	{
		if((strcmp(addressBook->contacts[i].phone,number)==0))
				{
					 printf("%s\n", addressBook->contacts[i].name);
                                         printf("%s\n", addressBook->contacts[i].phone);
                                         printf("%s\n", addressBook->contacts[i].email);
			
					 flag++;
					 return i;
				}
	}
	}
	if(flag==0) {printf("enterd number is invalid\n");return -1;}

}
int fun_mail(AddressBook *addressBook,char*name,char* mail)//these fun gives correct list when u see multiple names found
{
	int flag=0;
        for(int i=0; i < addressBook->contactCount; i++)
        {
        if((strcmp(addressBook->contacts[i].name,name)==0))
        {
                if((strcmp(addressBook->contacts[i].email,mail)==0))
                                {
                                         printf("%s\n", addressBook->contacts[i].name);
                                         printf("%s\n", addressBook->contacts[i].phone);
                                         printf("%s\n", addressBook->contacts[i].email);
                                         flag++;
					 return i;
		   		}
        }
        }
	if(flag==0) {printf("enterd mail is invalid\n");return -1;}

}
int search_by_mul(AddressBook *addressBook,char*name)//when multiple names are found , it goes to display only phone and mail
{
	int i=1;
	while(i)
{
	int opt1,opt2,opt3;
	char phone[20];
	char mail[20];
     printf("::search menu::\n1.search by phone\n2.search by mail\n3.Exit\n");
     scanf(" %d",&opt1);
     if(opt1==1)
     {
	     printf("Enter the ph no :");
	     scanf(" %s",phone);
	     if(!isvalidnumber(phone))//checking whether the number is valid or not
            {
                    printf("Invalid number ! please enter the correct number\n");
                    continue;
            }
	     int z=fun_no(addressBook,name,phone);//checkinng the no is presnt in tha multiple name or not
	     if(z!=-1)
	     {
		     printf("Do you want to search again press 1 for that or press 0 for main menu : \n");
		     scanf(" %d",&opt2);
		     if(opt2==1) return 1;
		     else return -1;
	     }
     }
     else if(opt1==2)
     {
	     printf("Enter the mail id : ");
	     scanf(" %s",mail);
	     if(!isvalid_mail(mail))//checking whether the mail is valid or not
            {
                    printf("Invalid email id ,please enter correct mailid\n");
                    continue;
            }
	     int k=fun_mail(addressBook,name, mail);//checkinng the no is presnt in tha multiple name or not
	    if(k!=-1)
	     {
		      printf("Do you want to search again press 1 for that or press 0 for main menu : \n");
                     scanf(" %d",&opt3);
                     if(opt3==1) return 1;
                     else return -1;
             }
     }
     else if(opt1==3) return -1;
     else  {printf("Invalid choice! Try again.\n");continue;}
}
}
int search_by(AddressBook *addressBook)//these fun is used to search the elements  
{
        int i=1;
      	while (i) {
        char name[50], phone[20], email[50];
        int result=0, option,opt1,opt2,opt3,z=0;

        printf("\n::search menu::\n1. Search by Name\n2. Search by Phone\n3. Search by Email\n4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &option);
	if(option==1)
	{
		printf("Enter the Name: ");
                getchar();
                scanf("%[^\n]", name);
                if (!isvalidName(name)) //these fun tells about the valid name or not
		{
  			printf("Invalid name! Please enter only alphabets.\n");
                        continue;
                }
	      	z= isDuplicateName(addressBook, name);
                if (z> 1)
	       	{  // If multiple contacts are found
                    printf("Multiple contacts found with this name.\nPlease search by phone or email.\n");
                    if( search_by_mul(addressBook,name)==1)		   
		   {
				    continue;
		   }  // Ask again for phone/email search
		    else return -1;
                }

                if (z == -1) {
                    printf("Name not found. Try again.\n");
                    continue;
                }
		if(z==-2)
		{
			printf("Do you want to search again Press 1 for that or for main menu press 0 : ");
			scanf(" %d",&opt1);

			if(opt1==1)
			{
				continue;
			}
			else 
			{
				return -1;//returning to main menu.
			}
		}
	}
	else if(option==2)
	{
		printf("Enter the Phone Number: ");
                scanf(" %s", phone);
		if(!isvalidnumber(phone))//checking whether the number is valid or not
                {
                         printf("Invalid number ! please enter the correct number\n");
                         continue;
                }
		result = isDuplicatenumber(addressBook, phone);//checks dupilicate no presnt or not.
                if (result == -1)
		 {
                         printf("Number not found. Try again.\n");
                         continue;
                 }
                if(result>=0) 
		 {
		         print_all(addressBook,result);//it prints all elemts of the contact.
			 printf("Do you want to search again Press 1 for that or for main menu press 0 : ");
                         scanf(" %d",&opt2);
			 if(opt2==1)
			 {
			 continue;
			 }
			 else return -1;
                }
	}
	else if(option==3)
        {
                printf("Enter the Mail Id: ");
                scanf("%s", email);
                if(!isvalid_mail(email))//checking whether the mail is valid or not
               {
                    printf("Invalid email id ,please enter correct mailid\n");
                    continue;
               }
		result = isDuplicate_mail(addressBook,email);
                if (result == -1)
                {
                         printf("Mail not found. Try again.\n");
                         continue;
                }
                if(result>=0)
		{
			 print_all(addressBook,result);
	       		 printf("Do you want to search again Press 1 for that or for main menu press 0 : ");
                         scanf(" %d",&opt3);
                         if(opt3==1)
                         {
                         continue;
                         }
                         else return -1;
                }
        }
	 else if(option==4)
	 {

		return -1;
       	 }
	 else  {printf("Invalid choice! Try again.\n");continue;}
}
}
int find_ind(AddressBook *addressBook,char*name)//these fun helps in finding the index for the name
{
        for(int i=0; i < addressBook->contactCount; i++)
        {
        if((strcmp(addressBook->contacts[i].name,name)==0))
        {
		return i;
	}
	}
	return -1;
}
int edit_fun(AddressBook *addressBook, int ind)//these fun helps to edit the particular contact. 
{
    while (1) {
        int editOption,opt1,opt2,opt3;
        printf("\nWhich field do you want to edit?\n");
        printf("::Edit menu::\n1. Name\n2. Phone\n3. Email\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &editOption);

        if (editOption == 1) {  // Edit Name
            char newName[50];
            printf("Enter new Name: ");
            getchar();
            scanf("%[^\n]", newName);

            if (!isvalidName(newName)) {
                printf("Invalid name! Please enter only alphabets.\n");
                continue;
            }
            strcpy(addressBook->contacts[ind].name, newName);
            printf("Name updated successfully!\n");
	    printf("Do you want to edit more in these contact press 1 for that or 0 for main menu : \n");
	    scanf(" %d",&opt1);
	    if(opt1==1)
	    {continue;
	    }
	    else return -1;
        }

        else if (editOption == 2) {  // Edit Phone
            char newPhone[20];
            printf("Enter new Phone: ");
            scanf("%s", newPhone);

            if (!isvalidnumber(newPhone)) {
                printf("Invalid phone number! Please enter a correct number.\n");
                continue;
            }

            if (isDuplicatenumber(addressBook, newPhone) != -1) {
                printf("This phone number already exists. Try a different one.\n");
                continue;
            }

            strcpy(addressBook->contacts[ind].phone, newPhone);
            printf("Phone number updated successfully!\n");
	    printf("Do you want to edit more in these contact press 1 for that or 0 for main menu : \n");
            scanf(" %d",&opt2);
            if(opt2==1)
            {continue;}
            else return -1;
        }

        else if (editOption == 3) {  // Edit Email
            char newEmail[50];
            printf("Enter new Email: ");
            scanf("%s", newEmail);

            if (!isvalid_mail(newEmail)) {
                printf("Invalid email! Please enter a correct email.\n");
                continue;
            }

            if (isDuplicate_mail(addressBook, newEmail) != -1) {
                printf("This email already exists. Try a different one.\n");
                continue;
            }

            strcpy(addressBook->contacts[ind].email, newEmail);//copying if the mail is valid
            printf("Email updated successfully!\n");
             printf("Do you want to edit more in these contact press 1 for that or 0 for main menu : \n");
            scanf(" %d",&opt3);
            if(opt3==1)
            {continue;}
            else return -1;
	}

        else if (editOption == 4) {  // Exit
            printf("Exiting edit mode.\n");
            return-1;
        }

        else {
            printf("Invalid choice! Try again.\n");
        }
    }
}
int search_edit(AddressBook *addressBook)//showing display ,for edit menu. 
{
 
 int option;
    char name[50], phone[20], email[50];
    int result = 0,result1=0;

    while (1) {
        printf("\n::search menu::\n1. Search by Name\n2. Search by Phone\n3. Search by Email\n4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &option);

        if (option == 1) {
            printf("Enter the Name: ");
            getchar();
            scanf("%[^\n]", name);
	    if (!isvalidName(name)) {//checking whether the name is valid or not .
                 printf("Invalid name! Please enter only alphabets.\n");
                 continue;
             }


                int z= isDuplicateName(addressBook, name);
                if (z> 1)
                {  // If multiple contacts are found
                    printf("Multiple contacts found with this name.\nPlease search by phone or email.\n");
		    int pb=search_funmul(addressBook,name);
		    if(pb==-1) return -1;
                }

                if (z == -1) {
                    printf("Name not found. Try again.\n");
                    continue;
                }
                if(z==-2)
                {
                        int ind=find_ind(addressBook,name);
			int nb=edit_fun(addressBook,ind);
			if(nb==-1) return -1;
                } 
         }
	else if(option==2)
        {
                printf("Enter the Phone Number: ");
                scanf(" %s", phone);
                if(!isvalidnumber(phone))//checking whether the number is valid or not
                {
                         printf("Invalid number ! please enter the correct number\n");
                         continue;
                }
                result = isDuplicatenumber(addressBook, phone);
                if (result == -1)
                 {
                         printf("Number not found. Try again.\n");
                         continue;
                 }
                if(result>=0)
                 {
                         print_all(addressBook,result);
			 int hh=edit_fun(addressBook,result);
			 if(hh==-1) return -1;
                }
        }	
	else if(option==3)
        {
                printf("Enter the Mail Id: ");
                scanf(" %s", email);
                if(!isvalid_mail(email))//checking whether the mail is valid or not
            {
                    printf("Invalid email id ,please enter correct mailid\n");
                    continue;
            }
		
                result1 = isDuplicate_mail(addressBook,email);
                if (result1 == -1)
                {
                         printf("Mail not found. Try again.\n");
                         continue;
                }
                if(result1>=0)
                 {
                         print_all(addressBook,result);
			 int kk=edit_fun(addressBook,result1);
			 if(kk==-1) return -1;
                }
        }
	 else if(option==4)
	 {
		 return -1;
	 }
	 else  {printf("Invalid choice! Try again.\n");continue;}
    }
}
int search_funmul(AddressBook *addressBook,char*name)//these fun helps when multiple contacts found ,it displays by phone and mail.
{
        int i=1;
        while(i)
{
        int opt1,opt2,opt3;
        char phone[20];
        char mail[20];
     printf("::search menu::\n1.search by phone\n2.search by mail\n3.Exit\n");
     scanf(" %d",&opt1);
     if(opt1==1)
     {
             printf("Enter the ph no :");
             scanf(" %s",phone);
             if(!isvalidnumber(phone))//checking whether the number is valid or not
            {
                    printf("Invalid number ! please enter the correct number\n");
                    continue;
            }
             int z=fun_no(addressBook,name,phone);
	     if(z==-1) return -1;
             int kb=edit_fun(addressBook,z);
	     if(kb==-1) return -1;
     }
     else if(opt1==2)
     {
	     printf("Enter the mail id : ");
	     scanf(" %s",mail);
	     if(!isvalid_mail(mail))//checking whether the mail is valid or not
            {
                    printf("Invalid email id ,please enter correct mailid\n");
                    continue;
            }
	      int k=fun_mail(addressBook,name, mail);
	      if(k==-1) return -1;
	      int ab=edit_fun(addressBook,k);
	      if(ab==-1) return -1;
     }
     else if(opt1==3) return -1;
     else  {printf("Invalid choice! Try again.\n");continue;}
}
}
void editContact(AddressBook *addressBook)//these fun helps in editing the contact 
{
    while (1) {  // Keep asking for search criteria until user chooses Exit
        int editIndex = search_edit(addressBook);  // Search for a contact

        if (editIndex==-1) {
	    printf("Returning to main menu...\n");
            return;
	}
    }
}

int search_for_del(AddressBook *addressBook)//these fun helps in delete the particular contact 
		{
		 int option,opt2,opt3;
    char name[50], phone[20], email[50];
    int result = 0;

    while (1) {
        printf("\n::search menu::\n1. Search by Name\n2. Search by Phone\n3. Search by Email\n4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &option);

        if (option == 1) {
            printf("Enter the Name: ");
            getchar();
            scanf("%[^\n]", name);
            if (!isvalidName(name)) {//checking whether the name is valid or not .
                 printf("Invalid name! Please enter only alphabets.\n");
                 continue;
             }


                int z= isDuplicateName(addressBook, name);
                if (z> 1)
                {  // If multiple contacts are found
                    printf("Multiple contacts found with this name.\nPlease search by phone or email.\n");
                    int pb=search_for_muldel(addressBook,name);
                    if(pb==-1) return -1;
                }

                if (z == -1) {
                    printf("Name not found. Try again.\n");
                    continue;
                }
                if(z==-2)
                {
                        int ind=find_ind(addressBook,name);
                        return ind;
		}
	}
	else if(option==2)
        {
                printf("Enter the Phone Number: ");
                scanf(" %s", phone);
                if(!isvalidnumber(phone))//checking whether the number is valid or not
                {
                         printf("Invalid number ! please enter the correct number\n");
                         continue;
                }
                 result = isDuplicatenumber(addressBook, phone);
                if (result == -1)
                 {
                         printf("Number not found. Try again.\n");
                         continue;
                 }
                if(result>=0)
                 {
                         print_all(addressBook,result);
                         return result;
		 }
	}
	else if(option==3)
        {
                printf("Enter the Mail Id: ");
                scanf(" %s", email);
                if(!isvalid_mail(email))//checking whether the mail is valid or not
            {
                    printf("Invalid email id ,please enter correct mailid\n");
                    continue;
            }

                int result1 = isDuplicate_mail(addressBook,email);
                if (result1 == -1)
                {
                         printf("Mail not found. Try again.\n");
                         continue;
                }
                if(result1>=0)
                 {
                         print_all(addressBook,result1);
			 return result1;
		 }
	}
	else if(option==4)
	 {
		 return -1;
	 }
	else {printf("Invalid choice! Try again.\n");continue;}
    }
}
		
int search_for_muldel(AddressBook *addressBook,char*name)//these fun helps ,when u find multiple names .
		{
		 int i=1;
        while(i)
{
        int opt1;
        char phone[20];
        char mail[20];
     printf("::search menu::\n1.search by phone\n2.search by mail\n3.Exit\n");
     scanf(" %d",&opt1);
     if(opt1==1)
     {
             printf("Enter the ph no :");
             scanf(" %s",phone);
             if(!isvalidnumber(phone))//checking whether the number is valid or not
            {
                    printf("Invalid number ! please enter the correct number\n");
                    continue;
            }
	     int cc=fun_no(addressBook,name,phone);
             if(cc==-1) return -1;
	     else return cc;
     }
     else if(opt1==2)
        {
		
                printf("Enter the Mail Id: ");
                scanf(" %s", mail);
                if(!isvalid_mail(mail))//checking whether the mail is valid or not
            {
                    printf("Invalid email id ,please enter correct mailid\n");
                    continue;
            }
		int dd=fun_mail(addressBook,name,mail);
		if(dd==-1) return -1;
		else return dd;
	}
      else if(opt1==3)
      {
	      return -1;
      }
      else {printf("Invalid choice! Try again.\n");continue;}
}
}
void deleteContact(AddressBook *addressBook)
{
    /* Define the logic for deletecontact */
    while (1) {  // Keep asking for search criteria until user exits
        int delInd =  search_for_del(addressBook); // Search for a contact

        if (delInd == -1)
       	{
            printf("Returning to main menu...\n");
            return;  // Exit to main menu
        }

        // Confirm deletion
        printf("\nAre you sure you want to delete this contact? (y/n): ");
        char confirm;
        scanf(" %c", &confirm);

        if (confirm == 'y' || confirm == 'Y') {
            // Shift contacts left to remove the selected contact
            for (int i = delInd; i < addressBook->contactCount - 1; i++) {
                 addressBook->contacts[i] = addressBook->contacts[i + 1];
	    }
            addressBook->contactCount--;  // Reduce count after deletion
            printf("Contact deleted successfully!\n");
        } else {
            printf("Deletion canceled.\n");
        }
	return;
    }
}


