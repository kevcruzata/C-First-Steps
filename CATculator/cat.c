// CATculator - Cat to Human Age Converter
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 100

int main(void)
{
    printf("\n");
    char repeat;
    do
    {
        // ask - cat's name
        char name[NAME_LEN];
        printf("What's your cat's name? ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;

        // ask - age in cat years and months
        int years, months;
        do
        {
            printf("What's %s's age in years? ", name);
            scanf("%d", &years);

            printf("In months? ");
            scanf("%d", &months);

            while (getchar() != '\n');
        }
        while (years < 0 || months < 0 || months >= 12);

        // calculate - total cat months
        int catmos = (years * 12) + months;
        int manmos;

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

        // print - cat's human age
        printf("\n%s's human age is ", name);

        // print - result
        printf("%i %s and %i %s old — %s\n\n",
               totmanyrs, (totmanyrs == 1) ? "year" : "years",
               totmanmos, (totmanmos == 1) ? "month" : "months",
               group);

        // ask - repeat
        printf("Do you want to convert another one? (y/n): \n\n");
        scanf(" %c", &repeat);
        while (getchar() != '\n');
    }
    while (tolower(repeat) == 'y');

    return 0;
}
