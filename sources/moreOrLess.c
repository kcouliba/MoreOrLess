#include "../includes/moreOrLess.h"

void    moreOrLess(int level)
{
    int max;
    int mysteryNumber;
    int userNumber;
    int count;

    max = MAX;
    while (level-- > 1)
        max *= 10;
    srand(time(NULL));
    mysteryNumber = (rand() % (max - MIN + 1)) + MIN;
    count = 0;
    /*
    ** Player tries to guess the mystery number
    */
    do
    {
        count++;
        do
        {
            printf("Quel nombre (%i - %i) : ", MIN, max);
            scanf("%i", &userNumber);
        } while ((userNumber < MIN) || (userNumber > max));
        if (userNumber > mysteryNumber)
            printf("C'est moins.\n");
        else if (userNumber < mysteryNumber)
            printf("C'est plus.\n");
    } while (userNumber != mysteryNumber);
    printf("Bravo, vous avez trouve le nombre mystere %i, en %i coup(s)!\n", mysteryNumber, count);
}
