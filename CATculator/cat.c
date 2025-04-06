// CATculator - Cat to Human Age Converter
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 100

void get_cat_name(char name[NAME_LEN]);
void get_cat_age(int *years, int *months, const char *name);
int calc_tot_cat_mos(int years, int months);
float convert_catmos_to_manmos(int catmos);
void convert_manmos_to_manyrs_and_manmos(float manmos, int *years, int *months);
const char *classify_cat(int catmos);
char ask_repeat(void);

int main(void)
{
    printf("\n");
    char name[NAME_LEN];
    int years, months;
    char repeat;
    do
    {
        get_cat_name(name);
        get_cat_age(&years, &months, name);
        
        int catmos = calc_tot_cat_mos(years, months);
        float manmos = convert_catmos_to_manmos(catmos);

        int totmanyrs, totmanmos;
        convert_manmos_to_manyrs_and_manmos(manmos, &totmanyrs, &totmanmos);
        
        const char *group = classify_cat(catmos);

        // print - cat's human age
        printf("\n%s's human age is ", name);
        printf("%i %s and %i %s old — %s\n\n",
               totmanyrs, (totmanyrs == 1) ? "year" : "years",
               totmanmos, (totmanmos == 1) ? "month" : "months",
               group);

        repeat = ask_repeat();
    }
    while (tolower(repeat) == 'y');

    return 0;
}

// FUNCTIONS

void get_cat_name(char name[NAME_LEN])
{
    // get - cat's name
    printf("What's your cat's name? ");
    fgets(name, NAME_LEN, stdin);
    name[strcspn(name, "\n")] = 0; 
}

void get_cat_age(int *years, int *months, const char *name)
{
    // get - age in cat years and months
    do
    {
        printf("What's %s's age in years? ", name);
        scanf("%d", years);

        printf("In months? ");
        scanf("%d", months);

        while (getchar() != '\n');
    }
    while (*years < 0 || *months < 0 || *months >= 12);
}

int calc_tot_cat_mos(int years, int months)
{
    // calculate - total cat months
    return (years * 12) + months;
}

float convert_catmos_to_manmos(int catmos)
{
    // convert - cat months to human months
    if (catmos <= 12)
    {
        return (15.0 * catmos);
    }
    else if (catmos > 12 && catmos <= 24)
    {
        return (12.5 * catmos);
    }
    else
    {
        return ((4.0 * (catmos - 24)) + 300.0);
    }
}

void convert_manmos_to_manyrs_and_manmos(float manmos, int *years, int *months)
{
    // convert - total human months to years and months
    int tot_manmos = (int)manmos;
    *years = tot_manmos / 12;
    *months = tot_manmos % 12;
}

const char *classify_cat(int catmos)
{
    // classify - cat age group
    if (catmos <= 12)
    {
        return "still a kitten!";
    }
    else if (catmos > 12 && catmos <= 684)
    {
        return "now an adult!";
    }
    else
    {
        return "now a senior!";
    }
}

char ask_repeat(void)
{
    // get - yes or no repeat
    char response;
    while(1)
    {
        printf("Do you want to convert another one? (y/n): ");
        scanf(" %c", &response);
        while (getchar() != '\n');
        printf("\n");
        
        response = tolower(response);

        if (response == 'y' || response == 'n')
        {
            return response;
        }
        else
        {
            printf("Invalid input. Please enter only 'y' or 'no'.\n\n");
        }
    }
}