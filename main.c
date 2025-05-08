/*
1.Name      : T.Ashok
2.Date      : 08/05/2025
3.Batch no  :24038_014
4.Project   : AddressBook
*/
#include "contact.h"
#include<stdlib.h>

int main()
{
          AddressBook addressBook;    //taking variable addressBook in AddressBook datatype
	 addressBook.contactCount = 0;    //initiating count as 0
	 //populateAddressBook(&addressBook);
         initialize(&addressBook);   //fun calling for taking contacts into struct array
	 while(1)
	 {
	 int opt;
	  printf(GREEN"\n:::Address Book Menu:::\n\n");
        printf(GREEN"1. Create contact\n");
        printf(GREEN"2. Search contact\n");
        printf(GREEN"3. Edit contact\n");
        printf(GREEN"4. Delete contact\n");
        printf(GREEN"5. List all contacts\n");
	printf(GREEN"6. Save and Exit\n");
        printf(RED"Enter your choice: ");
	 scanf("%d",&opt);
	 
	 
	switch (opt)
	{
		case 1:createContact(&addressBook);//these fun helps creats the name,phone,mail
		       break;
		case 2:searchContact(&addressBook);//these fun helps to search a particular contact.
		       break;
		case 3:editContact(&addressBook); // these fun helps to edit the particular contact.
		       break;
		case 4:deleteContact(&addressBook);//these fun helps to delete the particular contact.
		       break;
		case 5:listContacts(&addressBook);//these fun helps to display the all the contacts .
		       break;
                case 6:saveContactsToFile(&addressBook);//these fun helps in saving contacts in file and terminate the program.
		      exit(0);

	 }
	 }
}

