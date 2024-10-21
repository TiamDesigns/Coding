#include <stdio.h>
#define OPTION_LICENSE 1
#define OPTION_STICKER 2
#define OPTION_TICKET 3
#define COUNTER_LICENSE 5
#define COUNTER_STICKER 8
#define COUNTER_TICKET 2
#define ADMIN_MODE 12345

int admin(int count); 

int main()
{
    int userSelection;
    int customerCounter = 0; 

    do {
        printf("Enter an integer\n\t%d for Renew License\t%d for Renew Sticker\t%d for Pay ticket\n", 
        OPTION_LICENSE, OPTION_STICKER, OPTION_TICKET);
        scanf("%d", &userSelection);

        if (userSelection == OPTION_LICENSE) {
            printf("Go to counter %d\n", COUNTER_LICENSE);
            customerCounter++; 
        } else if (userSelection == OPTION_STICKER) {
            printf("Go to counter %d\n", COUNTER_STICKER);
            customerCounter++; 
        } else if (userSelection == OPTION_TICKET) {
            printf("Go to counter %d\n", COUNTER_TICKET);
            customerCounter++; 
        } else if (userSelection == ADMIN_MODE) {
            int result = admin(customerCounter);  
            if (result == 1) {
                customerCounter = 0; 
            } else if (result == 2) {
                break;  
            }
        } else {
            printf("Invalid selection\n");  
        }

    } while (1); 
    
    return 0;
}

int admin(int count) {
    int adminSelection;
    printf("ADMIN MODE\n");
    printf("Number of customers: %d\n", count);
    printf("Enter 1 to reset the customer counter, 2 to exit the program, or 0 to continue customer mode:\n");
    
    do {
        scanf("%d", &adminSelection);
        if (adminSelection == 1) {
            printf("Customer counter reset.\n");
            return 1; 
        } else if (adminSelection == 2) {
            printf("Exiting the program.\n");
            return 2;  
        } else if (adminSelection == 0) {
            return 0;  
        } else {
            printf("Invalid selection, please enter 0, 1, or 2.\n");
        }
    } while (1);  
}
