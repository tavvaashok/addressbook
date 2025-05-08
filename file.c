#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook)// these fun is used to save the contacts in to file
{
     FILE *fptr = fopen("contact.csv", "w+");//opening file in mode "w"
    if (fptr == NULL)//if they are no no memory then null will occures 
    {
        return;
    }
 fprintf(fptr,"#%d\n",addressBook->contactCount);//counting in the file it represents as # at the beginning
    for (int i = 0; i < addressBook->contactCount; i++) {
	    fprintf(fptr, "%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }
    fclose(fptr); //closing the file
}
void loadContactsFromFile(AddressBook *addressBook)// from these fun taking contacts from the file and storing in struct array.
{
    int i=0;
    FILE*fptr=fopen("contact.csv","r+");//opening file in r+ mode .
    if (fptr == NULL) {
        return;
    }
   fscanf(fptr,"#%d\n",&addressBook->contactCount);//it helps to read the count from file.
    for (int i = 0; i < addressBook->contactCount; i++) {
        fscanf(fptr, "%[^,],%[^,],%[^\n]\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    } 
    
    fclose(fptr);//closing the file.
}
