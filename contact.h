#ifndef CONTACT_H
#define CONTACT_H


#include<stdio.h>

#define MAX_CONTACTS 100

typedef struct Contact{
    char name[50];
    char phone[20];
    char email[50];
} Contact;
#define GREEN  "\033[1;32m"
#define RED    "\033[1;31m"
typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;
void populateAddressBook(AddressBook *addressBook);//it having the some dummy contacts.
void createContact(AddressBook *addressBook);//it helps to create the contact successfully.
void searchContact(AddressBook *addressBook);//it helps to search particular contact inthe list
void editContact(AddressBook *addressBook);//it  helps to edit the particular contact
void deleteContact(AddressBook *addressBook);//it helps to delete the particular contact inthe list 
void listContacts(AddressBook *addressBook);//it helps to display the all contact in the list 
void initialize(AddressBook *addressBook);//helps to call the contact from files
void saveContactsToFile(AddressBook *AddressBook);//it helps to save the contacts in to file ie,csv file
int isvalidName(char*name);//helps by telliing the name is valid or not
int isDuplicateName(AddressBook *addressBook,char*name);//helps to say the name is haviing iin the list or not
int isvalidnumber(char*number);//helps to say the number is valid or not 
int isDuplicatenumber(AddressBook *addressBook,char*number);//helps to say the number is have or not in contact list
int isvalid_mail(char*mail);//helps to say the mail is valid or not
void print_all(AddressBook *addressBook,int i);//it helps to print particular index in contact
int isDuplicate_mail(AddressBook *addressBook,char*mail);//helps to say mail is found or not in contact
int search_by(AddressBook *addressBook);//helps to search the contact
void updateContact(AddressBook *addressBook, int index);//it helps to update the contact for editing process
int fun_no(AddressBook *addressBook,char*name,char *number);//hepls when u see multiple contacts ,finding number
int search_edit(AddressBook *addressBook);//normal search for editing the contact
int search_by_mul(AddressBook *addressBook,char*name);//helps to edit the contact,when multiple names found.
int search_funmul(AddressBook *addressBook,char*name);//helps to edit ,when multiple names found
int edit_fun(AddressBook *addressBook, int ind);//helps to edit the contact ,when know the index
int search_for_muldel(AddressBook *addressBook,char*name);//helps ti delect contact ,when multiple names found
int search_for_del(AddressBook *addressBook);//helps to search for delete contact
#endif

