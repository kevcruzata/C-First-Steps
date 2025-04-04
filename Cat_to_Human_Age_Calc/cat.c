// MAC - Meow Age Calculator : Converting Cat Age to Human Age
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NAME_LEN 100

int main(void)
{
    char repeat;
    do
    {
        // ask - cat's name
        char name[NAME_LEN];
        printf("What's your cat's name? ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0; // remove newline character

        // ask - age in cat years and months
        int years, months;
        do
        {
            printf("What's %s's age in years? ", name);
            scanf("%d", &years);

            printf("In months? ");
            scanf("%d", &months);

            while (getchar() != '\n'); // clear input buffer
        }
        while (years < 0 || months < 0 || months >= 12);

        // calculate - total cat months
        int catmos = (years * 12) + months;
        int manmos;

        // print - cat's human age
        printf("%s's human age is ", name);

        // calculate - cat age in human age in months
        if (catmos <= 12)
        {
            manmos = 15 * catmos;
        }
        else if (catmos > 12 && catmos <= 24)
        {
            manmos = (int)(12.5 * catmos);
        }
        else
        {
            manmos = ((4 * (catmos - 24)) + 300);
        }

        // convert - total human months to years and months
        int totmanyrs = manmos / 12;
        int totmanmos = manmos % 12;

        // classify - age group
        const char *group;
        if (catmos <= 12)
        {
            group = "still a kitten!";
        }
        else if (catmos > 12 && catmos <= 684)
        {
            group = "now an adult!";
        }
        else
        {
            group = "now a senior!";
        }

        // print - result
        printf("%i %s and %i %s old — %s\n",
               totmanyrs, (totmanyrs == 1) ? "year" : "years",
               totmanmos, (totmanmos == 1) ? "month" : "months",
               group);

        // ask - repeat
        printf("Do you want to check another cat? (y/n): ");
        scanf(" %c", &repeat);
        while (getchar() != '\n'); // clear buffer
    }
    while (tolower(repeat) == 'y');

    printf("Thanks for using the MAC - Meow Age Calc!\n");

    return 0;
}
