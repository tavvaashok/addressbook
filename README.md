# Address Book

This is an Address Book program created in C. It allows users to store and manage contacts, including names, phone numbers, and email addresses. 
The program provides a menu-driven interface for various operations such as creating, searching, editing, and deleting contacts. The data is stored in files to ensure persistence.

## Features:
- **Create Contact**: Add new contacts with name, phone number, and email.
- **Search Contact**: Search contacts by name.
- **Edit Contact**: Modify an existing contact's details.
- **Delete Contact**: Remove a contact from the address book.
- **List All Contacts**: Display a list of all stored contacts.
- **Save and Exit**: Save contacts to a file and exit the program.

### Usage

1. **Create Contact**:
   - You can add a new contact by selecting the 'Create contact' option in the menu. The contact will be saved to a file.

2. **Search Contact**:
   - You can search for a contact by name. The program will display the contact's details if found.

3. **Edit Contact**:
   - The program allows you to edit an existing contact's name, phone number, and email.

4. **Delete Contact**:
   - You can delete a contact from the address book. The contact is permanently removed from the file.

5. **List All Contacts**:
   - View all contacts stored in the address book.

6. **Save and Exit**:
   - The program saves all contacts to a file before exiting, ensuring that your data persists.

### Restrictions:
- **Reuse of Names**: The program allows contacts with the same name, but **phone numbers and emails must be unique**.
- **No Duplicate Phone Numbers or Emails**: If a contact with the same phone number or email exists, you will not be able to add the new contact.

### Files:
- The contacts are stored in a file for persistence, so your data will remain even after exiting the program.

## How to Run:
1. Clone this repository.
   ```bash
   git clone https://github.com/yourusername/addressbook.git
