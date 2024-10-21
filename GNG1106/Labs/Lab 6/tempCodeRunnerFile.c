#include <stdio.h>
#define OPTION_LICENSE 5
#define OPTION_STICKER 2
#define OPTION_TICKET 3
#define COUNTER_LICENSE 5
#define COUNTER_STICKER 8
#define COUNTER_TICKET 2

int main()
{
	int userSelection;
	printf("Enter an integer\n\t%d for Renew License\t%d for Renew Sticker\t%d for Pay ticket\n", 
OPTION_LICENSE, OPTION_STICKER, OPTION_TICKET);
	scanf("%d", &userSelection);
	switch(userSelection)
	{
		case OPTION_LICENSE:
			printf("Go to counter %d\n", COUNTER_LICENSE);
			break;
		case OPTION_STICKER:
			printf("Go to counter %d\n", COUNTER_STICKER);
                        break;
                case OPTION_TICKET:               
			printf("Go to counter %d\n", COUNTER_TICKET);
                        break;
		default:
			printf("invalid selection\n");

	}
	return 0;

}
