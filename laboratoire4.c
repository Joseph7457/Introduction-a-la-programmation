#include<stdio.h>
#include<stdlib.h>


/* 4.1 Répertoire d’Adresses Électroniques
On souhaite mettre en place un répertoire d’adresses électroniques. Pour ce faire, nous allons
procéder en plusieurs étapes./*

/*. Exercice 1 Définissez une structure de données permettant de représenter une personne.
Les informations relatives à une personne sont son nom, son prénom et son adresse email. Toutes
ces informations sont des chaines de caractères.*/ 

typedef struct
{
char* nom;
char* prenom;
char* adresse;
} Personne;

void testExercice1()
{
Personne albert;
albert.nom     = "Le Grand";
albert.prenom  = "Albert";
albert.adresse = "albertlegrand@matador.be"; 

printf("\n Le nom est %s", albert.nom );
printf("\n Le prénom est %s", albert.prenom );
printf("\n L'adresse mail est %s\n", albert.adresse );
}

/*
. Exercice 2 Spécifiez et écrivez une fonction C prenant en argument deux chaines de
caractères et retournant une valeur entière non-nulle si ces deux chaines sont égales (i.e., elles
possèdent le même contenu), une valeur nulle sinon.
Attention, il n’est pas permis de faire appel, pour résoudre ce problème, à des fonctions d’une
quelconque bibliothèque C.
Veillez à envisager tous les cas possibles : les deux chaines peuvent avoir des longueurs
maximales différentes et le symbole de fin de chaine ( ’\0’) n’est peut-être pas présent dans
l’une ou l’autre des chaines. Il est indispensable de réaliser un schéma (et donc un Invariant
Graphique) afin de bien gérer tous ces cas particuliers.*/


int tester_string(char* c1, char* c2)
{
	int index = 0;					
	char a;   // création de deux variables contenant chacune le caractère à comparé
	char b;   
	printf("\nla première chaine est : %s", c1);
	printf("\nla deuxième chaine est : %s", c2);
	 

	while (*(c1+index) != '\0' && *(c2+index) != '\0')
	{
	a = *(c1+index);		// a est égale à la valeur du pointeur majoré de l'index
	b = *(c2+index);		// pareil pour b
	//printf("\n le caractère de la chaine 1 est: %c", a );		// retirer les // pour afficher les caractères 1 à 1. 
	//printf("\n le caractère de la chaine 1 est: %c", b);
	
		if(a != b)
		return 0;   // si différent on retourne 0;
		
	index++;            // si on a pas quitté la boucle, on augmente l'index.
	}
	
	a = *(c1+index);       // pareil qu'avant
	b = *(c2+index); 
	//printf("\n %c", a ); // pareil
	//printf("\n %c", b);
	
	if(a != b)   // dernière comparaison. Utile si tous les caractères sont communs, mais qu'un mot est plus grand que l'autre.
	return 0;
	else
	return 1;
}

void testExercice2()
{
char prenom1[]  = "Roxannne";
char prenom2[]  = "Roxannne";
char prenom3[]  = "Roxannn";
char prenom4[]  = "Epoxy";

int boolean;
boolean = tester_string(prenom1, prenom2);

if (boolean == 1)
printf("les prénoms matchent");
else
printf("les prénoms ne matchent pas");

boolean = tester_string(prenom1, prenom3);

if (boolean == 1)
printf("les prénoms matchent");
else
printf("les prénoms ne matchent pas");

boolean = tester_string(prenom1, prenom4);

if (boolean == 1)
printf("les prénoms matchent\n");
else
printf("les prénoms ne matchent pas\n");
}

/*
. Exercice 3 Définissez maintenant une structure de données permettant de représenter un
répertoire. Les informations nécessaires sont les personnes composant le répertoire et le nombre
de personnes contenues dans le répertoire.
*/



/*
. Exercice 4 Spécifiez et écrivez une fonction C permettant de recherche l’adresse électro-
nique d’une personne donnée. Plus précisément, la fonction prendra pour argument un répertoire
ainsi que la nom de la personne dont on cherche l’adresse. Si la personne se trouve dans le réper-
toire, la fonction affichera son email et retournera une valeur entière non nulle. Sinon, la fonction
renverra une valeur nulle
*/



int main()
{
testExercice1();
testExercice2();
}
