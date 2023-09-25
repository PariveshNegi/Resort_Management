#include <stdio.h>
#include<string.h>
// Function to display the available choices based on the selected service
int choiceA(int a)
{
    printf("\t\t---------------------------------------------\n");
    switch (a)
    {
        case 1:
            printf("\t\tCategories Of Room Available:\n");
            printf("\t\t1. Ordinary\n\t\t2. Deluxe\n\t\t3. VIP\n");
            break;
        case 2:
            printf("\t\tCategories Of Adventures:\n");
            printf("\t\t1. Camping\n\t\t2. Jungle Safari\n\t\t3. River Rafting\n\t\t4. Mountain Climbing\n");
            break;
        case 3:
            printf("\t\tTables Available:\n");
            printf("\t\t1. Single\n\t\t2. Couple\n\t\t3. Family\n\t\t4. VIP\n");
            break;
        default:
            printf("Invalid input\n");
            break;
    }

    return a;
}

// Function for table reservation
void table(char date[])
{
    int b;
    char x,z[15],p[10];
input_choice:
    printf("\t\t---------------------------------------------\n");
    printf("\n\t\tWhat Will Be Your Choice: ");
    scanf("%d", &b);
    printf("\t\t---------------------------------------------\n");

    switch (b)
    {
        case 1:
            printf("\t\tTable reservation for a single person\n\t\twill cost you: 300 Rs\n");
            strcpy(z, "Single person");
            strcpy(p,"Rs 300");
            break;
        case 2:
            printf("\t\tTable reservation for a couple\n\t\twill cost you: 500 Rs\n");
            strcpy(z, "Couple");
            strcpy(p,"Rs 500");
            break;
        case 3:
            printf("\t\tTable reservation for a family\n\t\twill cost you: 1000 Rs\n");
            strcpy(z, "Family");
            strcpy(p,"Rs 1000");
            break;
        case 4:
            printf("\t\tTable reservation for VIP\n\t\twill cost you: 2000 Rs\n");
            strcpy(z, "VIP");
            strcpy(p,"Rs 2000");
            break;
        default:
            printf("Invalid input\n");
            goto input_choice;
    }

    printf("\t\t---------------------------------------------\n");
    printf("\t\tWould you like to confirm your booking?\n\t\tAnswer Y/N: ");
    scanf(" %c", &x);

    if (x == 'y' || x == 'Y')
    {
        printf("\t\t*********************************************\n");
        printf("\t\t\t\tCONGRATULATIONS\n\t\t\t  Your table has been booked\n");
        printf("\t\tBooking details are sent to [reservtable.txt]\n");
        printf("\t\t*********************************************\n");

        // Store booking details in a file
        FILE *f = fopen("reservtable.txt", "w");
        if (f != NULL)
        {
            fprintf(f,"*--------------------*\n");
            fprintf(f, "Your table reservation is done \nSee below for details:\n");
            fprintf(f, "-------------------------\n");
            fprintf(f, "\nTable Type:      %s\n", z);
            fprintf(f, "Reservation ID : %.5s-%s\n",date,z);
            fprintf(f,"booking date :   %s\n",date);
            fprintf(f,"ammount :        %s\n",p);
            fclose(f);
        }
        else
        {
            printf("\n\t\tFailed to store booking details.\n");
        }
    }
    else if (x == 'n' || x == 'N')
    {
        goto input_choice;
    }
    else
    {
        printf("\n\t\tInvalid input\n");
    }
}

// Function for adventure booking
void adventure(char date[])
{
    int b;
    char x,z[15],p[10];
input_choice:
    printf("\t\t---------------------------------------------\n");
    printf("\n\t\tWhat Will Be Your Choice: ");
    scanf("%d", &b);
    printf("\t\t---------------------------------------------\n");
    printf("\t\t[NOTE]: Tools And Equipments Will Be Provided\n\t\t       As You Start Your Adventure.\n");

    switch (b)
    {
        case 1:
            printf("\n\t\tActivities Included:   Hiking    Archery\n\t\t\t\t       Fishing   Bonfire\n\n\t\tPrice: 2500 Rs\n");
            strcpy(z, "Camping");
            strcpy(p,"Rs 2500");
            break;
        case 2:
            printf("\n\t\tActivities Included: Birding   Animal Seeking\n\t\t\t         & Trained Animals Interaction\n\t\tPrice: 1500 Rs\n");
            strcpy(z, "Jungle safari");
            strcpy(p,"Rs 1500");
            break;
        case 3:
            printf("\n\t\tActivities Included: White-water Rafting  &\n\t\t\t   Swimming\n\t\tPrice: 2000 Rs\n");
            strcpy(z, "River Rafting");
            strcpy(p,"Rs 2000");
            break;
        case 4:
            printf("\n\t\tActivities Included: Trekking & Rock climbing\n\t\tPrice: 2000 Rs\n");
            strcpy(z, "Mountain Climbing");
            strcpy(p,"Rs 2000");
            break;
        default:
            printf("Invalid input\n");
            goto input_choice;
    }

    printf("\t\t---------------------------------------------\n");
    printf("\t\tWould you like to confirm your booking?\n\t\tAnswer Y/N: ");
    scanf(" %c", &x);

    if (x == 'y' || x == 'Y')
    {
        printf("\t\t*********************************************\n");
        printf("\t\t\t\tCONGRATULATIONS\n\t\t\t  Your adventure has been booked\n");
        printf("\t\tBooking details are sent to [adventure.txt]\n");
        printf("\t\t*********************************************\n");

        // Store booking details in a file
        FILE *f = fopen("adventurebooking.txt", "w");
        if (f != NULL)
        {
            fprintf(f,"*--------------------*\n");
            fprintf(f, "Your adventure is reserved sucessfully \nSee below for details:\n");
            fprintf(f, "-------------------------\n");
            fprintf(f, "\nAdventure Type:      %s\n", z);
            fprintf(f, "Reservation ID :     %.5s-%s\n",date,z);
            fprintf(f,"Booking date :       %s\n",date);
            fprintf(f,"Ammount :            %s\n",p);

            fclose(f);
        }
        else
        {
            printf("\n\t\tFailed to store booking details.\n");
        }
    }
    else if (x == 'n' || x == 'N')
    {
        goto input_choice;
    }
    else
    {
        printf("\n\t\tInvalid input\n");
    }
}

// Function for room booking
void room(char date[])
{
    int b;
    char x,z[15],p[10],day[9];

input_choice:
    printf("\t\t---------------------------------------------\n");
    printf("\n\t\tWhat Will Be Your Choice: ");
    scanf("%d", &b);
    printf("\t\t---------------------------------------------\n");

    switch (b)
    {
        case 1:
            printf("\t\tFeatures:  1 Double Bed   Private Bathroom\n\t\t\t    Wall TV\n\n\t\tPrice: 1500 Rs\n");
            strcpy(z, "Ordinary");
            strcpy(p,"Rs 1500");
            break;
        case 2:
            printf("\t\tFeatures:  1 Double Bed   Private Bathroom\n\t\t\t    Flat Screen    Air Conditioner\n\t\tPrice: 3000 Rs\n");
            strcpy(z, "Deluxe");
            strcpy(p,"Rs 3000");
            break;
        case 3:
            printf("\t\tFeatures:  1 Double Bed   Private Bathroom\n\t\t\t    Free Wifi      Flat Screen TV\n\t\t\t    Geyser         Air Conditioner\n\t\tPrice: 4000 Rs\n");
            strcpy(z, "VIP");
            strcpy(p,"Rs 4000");
            break;
        default:
            printf("Invalid input\n");
            goto input_choice;
    }

    printf("\t\t---------------------------------------------\n");
    printf("\t\tEnter checkout date as (dd/mm/yy):");
    scanf("%8s",day);
    printf("\t\tWould you like to confirm your booking?\n\t\tAnswer Y/N: ");
    scanf(" %c", &x);

    if (x == 'y' || x == 'Y')
    {
        printf("\t\t*********************************************\n");
        printf("\t\t\t\tCONGRATULATIONS\n\t\t\t  Your room has been booked\n");
        printf("\t\tBooking details are sent to [roombooking.txt]\n");
        printf("\t\t*********************************************\n");

        // Store booking details in a file
        FILE *f = fopen("roombooking.txt", "w");
        if (f != NULL)
        {
            fprintf(f,"*--------------------*\n");
            fprintf(f, "Your room is booked sucessfully \nSee below for details:\n");
            fprintf(f, "-------------------------\n");
            fprintf(f, "\nAdventure Type:      %s\n", z);
            fprintf(f, "Reservation ID :     %.5s-%s\n",date,z);
            fprintf(f,"checkin date :       %s\n",date);
            fprintf(f,"checkout date :      %s\n",day);
            fprintf(f,"Ammount :            %s\n",p);
            fclose(f);
        }
        else
        {
            printf("\n\t\tFailed to store booking details.\n");
        }
    }
    else if (x == 'n' || x == 'N')
    {
        goto input_choice;
    }
    else
    {
        printf("\n\t\tInvalid input\n");
    }
}

// Function to handle user sign up
void signup()
{
    FILE *f;
    f = fopen("CUSTOMERdetails.txt", "w");
    char name[20], email[20], Mno[10];
    int age, a;

    printf("\n\t\t----->FILL THE SIGN UP FORM TO PROCEED<------\n");
    printf("\t\t---------------------------------------------\n");
    fprintf(f,"*--------------------*\n");
    printf("\t\tNAME\t: ");
    gets(name);
    fprintf(f, "NAME : %s\n", name);
    printf("\t\tEMAIL ID: ");
    gets(email);
    fprintf(f, "EMAIL : %s\n", email);
    printf("\t\tAGE\t: ");
    scanf("%d", &age);
    fprintf(f, "AGE : %d\n", age);
    printf("\t\tMOB No\t: ");
    scanf("%s", &Mno);
    fprintf(f, "MOB NO : %s\n", Mno);
    fprintf(f,"*--------------------*\n");
    printf("\t\t---------------------------------------------");
}
int main()
{
    int a;
    printf("\t\t(^_^)******* HAPPY VALLEY RESORT *******(^_^)\n");
    printf("\t\t(^_^)*********  WELCOMES YOU  **********(^_^)\n");
    printf("\t\t_____________________________________________");
    signup();
    printf("\n\t\t\t   Thank You For Signing Up\n");
    printf("\t\t---------------------------------------------");
    printf("\n\t\tHow Can We Assist You Today?\n\t\t1. Room Booking\n\t\t2. Adventure\n\t\t3. Table Reservation");
    printf("\n\t\t---------------------------------------------\n");
    printf("\t\tEnter The Service No As Per The List: ");
    scanf("%d", &a);
    char date[9];
    printf("\n\t\tEnter the booking date in (dd/mm/yy):");
    scanf("%8s",date);
   choiceA(a);
    if (a == 1)
        room(date);
    else if (a == 2)
        adventure(date);
    else if (a == 3)
        table(date);
    printf("\t\t    ***** Thank you for choosing us *****\n\t\t\t  **** Have a nice day ****\n\n\n");
    return 0;
}
