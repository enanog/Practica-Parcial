#include <stdio.h>
#include <string.h>

#define NMAX 15
#define TERM "\0"

typedef struct 
{
    const char *Club;
    unsigned int startDate;
    unsigned int endDate;
}club_t;

typedef struct
{
    const char *nombre;
    club_t listClub[NMAX];
}futbolista_t;

int futJugaronJuntxs(futbolista_t fut1, futbolista_t fut2);

int main(void)
{
    club_t club1[NMAX] = {
        {"Boca", 2014, 2015},
        {"Huracan", 2015, 2019},
        {"Platense", 2020, 2025},
        {TERM}
    };

    club_t club2[NMAX] = {
        {"Boca", 2018, 2021},
        {"Platense", 2021, 2025},
        {TERM}
    };
    
    futbolista_t jugador1 = {"Jorge", {club1[0], club1[1], club1[2], club1[3]}};
    futbolista_t jugador2 = {"Raul", {club2[0], club2[1], club2[2]}};

    printf("%d", futJugaronJuntxs(jugador1, jugador2));

    return 0;
}

int futJugaronJuntxs(futbolista_t fut1, futbolista_t fut2)
{
    int i, j;
    for(i = 0; fut1.listClub[i].Club != TERM; i++)
    {
        for(j = 0; fut2.listClub[j].Club != TERM; j++)
        {
            // Verifico que los clubes sean los mismos
            if(strcmp(fut1.listClub[i].Club, fut2.listClub[j].Club))
            {
                continue;   // Si no son iguales, salteo lo que queda del for y paso al siguiente club
            }
            // Si jugaron en el mismo equipo verifico que esten en el mismo lapso de tiempo
            if(fut1.listClub[i].startDate <= fut2.listClub[j].startDate 
               && fut2.listClub[j].startDate <= fut1.listClub[i].endDate)
            {
                return 1;   // Jugaron en el mismo lapso
            }
        }
    }
    return 0;
}
