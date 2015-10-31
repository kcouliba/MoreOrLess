#include "../includes/moreOrLess.h"

int     main(void)
{
    bool    run;
    char    *input;
    int     level;

    if (!(input = (char *)malloc(sizeof(*input) * 2)))
    {
        printf("Pas assez de memoire pour lancer l'executable.\n");
        return (EXIT_FAILURE);
    }
    run = TRUE;
    /*
    ** Game loop
    */
    while (run == TRUE)
    {
        /*
        ** Ask the player for a difficulty level
        */
        do
        {
            printf("\nNiveaux de jeu : \n\t1 (facile) : 1 - 100\n\t2 (moyen) : 1 - 1000\n\t3 (difficile) : 1 - 10000\n\n");
            printf("Niveau : ");
            scanf("%i", &level);
        } while ((level < 1) || (level > 3));
        printf("Niveau choisi : %i\n\n", level);
        /*
        ** Launches the main game
        */
        moreOrLess(level);
        /*
        ** Ask the player for a new game
        */
        printf("Nouvelle partie (O/N) : ");
        scanf("%s", input);
        input[1] = '\0';
        if (input[0] != 'O')
            run = FALSE;
    }
    free(input);
    return (0);
}
