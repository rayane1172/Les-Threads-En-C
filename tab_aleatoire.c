
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h> //il faut utiliser ce beb pour les nombres aleatoire

int tab[100];

void *f_thread3()
{

    printf("\n\n\n size of table is : %lu octets\n\n\n", sizeof(tab));
    sleep(2);
}

void *f_thread1()
{ // fonction du premier thread

    srand(time(NULL));

    for (size_t i = 0; i < sizeof(tab) / 4; i++) // sizeof /2 : c.a.d que chaque element du tableau des entier a un taille du 4 octets et la fonction sizeof return le nombre d'octets total dans le tableau...
    {
        tab[i] = rand() % 99 + 0; // nombre aleatoire entre 0 et 99
    }
    sleep(4);
    pthread_exit(NULL);
}
void *f_thread2()
{ // fonction du 2eme thread

    for (int j = 0; j < sizeof(tab) / 4; j++)
    {
        printf("T[%d]=%d \t", j + 1, tab[j]);
    }
    pthread_exit(NULL);
}

int main()
{

    pthread_t thr1, thr2, thr3; // initialiser deux threads

    pthread_create(&thr1, NULL, f_thread1, NULL);
    pthread_create(&thr2, NULL, f_thread2, NULL);
    pthread_create(&thr3, NULL, f_thread3, NULL);
    pthread_join(thr3, NULL);
    pthread_join(thr1, NULL);
    pthread_join(thr2, NULL);

    return 0;
}