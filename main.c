#include <stdlib.h>
#include <stdio.h>
#include <math.h>

const   int     CONST_INT   = 3;
        int     entier      = 12;
        float   reel      = 3.14f;


void parcourire(int tab[], size_t size, void(*traitement)(int*)) {

    for (size_t i = 0; i < size; ++i) {
        traitement(&tab[i]);
    }
}

void fois2(int* ptrx) {
    *ptrx *= 2;
}

void put(int* ptrx) {
    printf("%d\n", *ptrx);
}

void pswap(int* lhs, int* rhs) {
    int tmp = *lhs;

    *lhs = *rhs;
    *rhs = tmp;
}

int* fibobo(int n) {
    int* tab = (int*)calloc(n, sizeof(int));

    if (!tab) return tab;

    int first  = 1;
    int second = 1;
    int next   = 1;

    for (int i = 0; i < n; ++i) {
        if (i > 1) {
            next   = second + first;
            first  = second;
            second = next;
        }

        *(tab + i) = next;
    }

    return tab;
}

int main() {

    // const   int*        ptrOnConst          = &CONST_INT; // pointer on a constant
    //         int* const  constPtr            = &CONST_INT; // constant pointer on an integer
    // const   int* const  constPtrOnConst     = &CONST_INT; // constant pointer on a constant

    { // 1.
        printf("1. Pointeur constant sur une constante:\n");

        // a. Déclarer un pointeur constant sur la constante « CONST_INT »
        const int* const ptr = &CONST_INT;

        // b. Afficher la valeur pointée
        printf("pointed value = %d\n", *ptr);

        // c. Incrémenter de 1 « CONST_INT »
        //*ptr += 1;

        // d. Changer la valeur du pointeur (nouvelle adresse)
        // ptr = &entier; // pas possible car pointeur constant.

        // e. Changer la valeur pointée
        //(*ptr) = 10;

        printf("\n");
    }

    { // 2.
        printf("2. Pointeur sur une constante:\n");

        // a. Déclarer un pointeur sur une constante entière initialisé à NULL
        const int* ptr = NULL;

        // b. Affecter ce pointeur sur la variable « entier»
        ptr = &entier;

        // c. Afficher la valeur pointée
        printf("pointed value = %d\n", *ptr);

        // d. Changer la valeur pointée à 13
        // *ptr = 13;

        // e. Affecter ce pointeur sur la constante « CONST_INT »
        ptr = &CONST_INT;

        // f. Afficher la valeur pointée
        printf("pointed value = %d\n", *ptr);

        // g. Changer la valeur pointée
        // *ptr = 13;

        printf("\n");
    }

    { // 3.
        printf("3. Pointeur constant:\n");

        // a. Déclarer un pointeur constant pointant sur « entier»
        int* const ptr = &entier;

        // b. Que se passe-t-il si initialisé à NULL ?
        //      Vu qu'il est constant, s'il est initialisé à NULL,
        //      il ne sera plus possible de changer sa valeur.

        // c. Affecter ce pointeur sur « CONST_INT »
        // ptr = &CONST_INT;

        // d. Afficher la valeur pointée
        printf("pointed value = %d\n", *ptr);

        // e. Changer la valeur pointée à 5
        *ptr = 5;

        printf("\n");
    }


    { // 4.
        printf("4. Pointeur « void »:\n");

        // a. Déclarer un pointeur « void » non-initialisé
        void* ptr;

        // b. Affecter ce pointeur sur « entier»
        ptr = &entier;

        // c. Afficher la valeur pointée
        printf("pointed value = %d\n", *(int*)ptr);

        // d. Affecter ce pointeur sur « reel »
        ptr = &reel;

        // e. Afficher la valeur pointée
        printf("pointed value = %f\n", *(float*)ptr);

        // f. Affecter ce pointeur sur « entier»
        ptr = &entier;

        // g. Afficher la valeur pointée
        printf("pointed value = %d\n", *(int*)ptr);

        printf("\n");
    }

    { // 5.
        printf("5.Pointeur sur un pointeur sur un entier:\n");

        // a. Déclarer un pointeur sur un entier affecté sur « entier»
        int* ptr = &entier;

        // b. Déclarer un pointeur sur le pointeur précédent
        int** ptr_ptr = &ptr;

        // c. Afficher la valeur pointée correspondant à « entier»
        printf("pointed value = %d\n", *ptr);
        printf("pointed value = %d\n", **ptr_ptr);

        printf("\n");
    }

    { // 6.
        printf("6.Pointeur sur un tableau de 10 entiers:\n");

        // a. Déclarer un tableau de 10 entiers initialisé à : 0, 1, 2, 3, 4, reste à 0
        int tab[10] = {0, 1, 2, 3, 4};

        // b. Déclarer un pointeur sur le début du tableau
        int* ptr = &tab[0];

        // c. De plusieurs manières, afficher l’élément « 0 » du tableau
        printf("a) tab[0]     : %d \n",  tab[0]);
        printf("b) *tab       : %d \n", *tab);
        printf("c) *(tab + 0) : %d \n", *(tab + 0));
        printf("d) ptr[0]     : %d \n",  ptr[0]);
        printf("e) *ptr       : %d \n", *ptr);
        printf("f) *(ptr + 0) : %d \n", *(ptr + 0));


        // d. Affecter le pointeur sur l’élément « 1 » du tableau
        ptr = tab + 1;

        // e. Afficher cet élément de plusieurs manières
        printf("\n");
        printf("a) tab[1]     : %d \n",  tab[1]);
        printf("b) *(tab + 1) : %d \n", *(tab + 1));
        printf("c) ptr[0]     : %d \n",  ptr[0]);
        printf("d) *pt  r     : %d \n", *ptr);
        printf("d) *(ptr + 0) : %d \n", *(ptr + 0));

        // f. Déclarer un pointeur sur le tableau de 10 entiers
        int* ptr2 = tab; // c pas possible de pointer sur le tableau en entier. on pointe sur le premier élément

        // g. En utilisant ce dernier pointeur, afficher l’élément « 0 » de ce tableau
        printf("\n");
        printf("tab[0] : %d \n", *ptr2);

        printf("\n");
    }

    { // 7.
        printf("7.Pointeur de fonctions:\n");

        // a. Déclarer un tableau de 10 entiers initialisés de 0 à 9
        int tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        // b. Afficher l’adresse de « entier »
        printf("\"entier\" address = %p\n", &entier);

        // c. Créer une fonction « parcourir » ayant comme paramètre le traitement
        //      à faire sur chacun des éléments du tableau
        // d. Créer une fonction « fois2 » qui servira à multiplier par 2 tous les
        //      éléments du tableau
        // e. Créer une fonction « put » qui servira à afficher tous les éléments du
        //      tableau
        // f. Afficher tout le tableau
        parcourire(tab, 10, put);
        printf("\n");

        // g. Doubler toutes les valeurs du tableau
        parcourire(tab, 10, fois2);

        // h. Afficher tout le tableau
        parcourire(tab, 10, put);
        printf("\n");

        printf("\n");
    }

    { // 8.
        printf("8.Tableau de fonctions:\n");

        // a. Déclarer un tableau de pointeurs de fonctions double fct (double) qui
        //      contient sin, cos, tan
        double ( (* tab[3]) ) (double) = {sin, cos, tan};

        // b. Par le biais du tableau, appliquer une fonction choisie sur une valeur
        //      fixe
        printf("sin(%f) = %f\n", 3.0, tab[0](3.0));

        printf("\n");
    }

    { // 9.
        printf("9. Echange de pointeurs\n");

        // a. Déclarer deux variables entières et deux pointeurs pointant sur ces variables.
        int i = 10,
            j = 3;

        int* pi = &i;
        int* pj = &j;

        // b. Ecrire une fonction qui échange 2 pointeurs sur des entiers
        //      c.f. pswap

        // c. Afficher les valeurs pointées
        printf("i = %d, j = %d\n", *pi, *pj);

        // d. Echanger le contenu des deux pointeurs
        pswap(pi, pj);

        // e. Afficher les valeurs pointées
        printf("i = %d, j = %d\n", *pi, *pj);


        printf("\n");
    }

    { // 10.
        printf("10. Tableau de Fibonacci\n");

        // a. Ecrire une fonction qui retourne un tableau constant contenant les n
        // premières valeurs de la suite de Fibonacci f(n) = f(n-1) + f(n-2) avec f0 = 1 et f1 = 1
        int* fibo = fibobo(5);

        // b. Afficher ce tableau en écrivant le moins de code possible
        parcourire(fibo, 5, put);
    }
    return 0;
}