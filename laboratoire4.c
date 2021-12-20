#include<stdio.h>
#include<stdlib.h>


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* 4.1 Répertoire d’Adresses Électroniques
On souhaite mettre en place un répertoire d’adresses électroniques. Pour ce faire, nous allons
procéder en plusieurs étapes./*

/*. Exercice 1 Définissez une structure de données permettant de représenter une personne.
Les informations relatives à une personne sont son nom, son prénom et son adresse email. Toutes
ces informations sont des chaines de caractères.*/ 

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int tester_string(char* c1, char* c2)
{
	int index = 0;					
	char a;   // création de deux variables contenant chacune le caractère à comparé
	char b;   
	printf("\nla première chaine est : %s", c1);
	printf("\nla deuxième chaine est : %s\n", c2);
	 

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

				////////////////////////////////////////////////////////////////////////////
				
void testExercice2()
{
char prenom1[]  = "Roxannne";
char prenom2[]  = "Roxannne";
char prenom3[]  = "Roxannn";
char prenom4[]  = "Epoxy";

int boolean;
boolean = tester_string(prenom1, prenom2);

if (boolean == 1)
printf("les prénoms matchent\n");
else
printf("les prénoms ne matchent pas\n");

boolean = tester_string(prenom1, prenom3);

if (boolean == 1)
printf("les prénoms matchent\n");
else
printf("les prénoms ne matchent pas\n");

boolean = tester_string(prenom1, prenom4);

if (boolean == 1)
printf("les prénoms matchent\n");
else
printf("les prénoms ne matchent pas\n\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
. Exercice 3 Définissez maintenant une structure de données permettant de représenter un
répertoire. Les informations nécessaires sont les personnes composant le répertoire et le nombre
de personnes contenues dans le répertoire.
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct
	{
	short nombreDeContacts;
	Personne* contacts;
} Repertoire;


				////////////////////////////////////////////////////////////////////////////
				
void testExercice3()
{
Repertoire carnet;
carnet.nombreDeContacts = 5;
carnet.contacts = malloc(sizeof(Personne)*carnet.nombreDeContacts);
int sop = sizeof(Personne);
printf("la taille de Personne est de %d octets\n\n", sop);

Personne* p = carnet.contacts;    // pour faciliter la lecture;


for (int i = 0; i<carnet.nombreDeContacts; i++)
	{
	//char* prenom;        			// A l'aide M. Donnet
	//scanf("%s", prenom); 			// A l'aide Géraldine 
	(p+i*sop)->nom     = "Skywalker";	
	(p+i*sop)->prenom  = "Luc";
	(p+i*sop)->adresse = "Luke-Skywalker@laforce.be";
	//free(prenom);
	
	}
	
	(p+0*sop)->nom     = "Skywalker";	
	(p+0*sop)->prenom  = "Luc";
	(p+0*sop)->adresse = "Luke-Skywalker@laforce.be";
	
	(p+1*sop)->nom     = "Skywalker";	
	(p+1*sop)->prenom  = "Léa";
	(p+1*sop)->adresse = "Lea@laforce.be";	
	
	(p+2*sop)->nom     = "Marcheur Des Cieux";	
	(p+2*sop)->prenom  = "Lucien";
	(p+2*sop)->adresse = "Lulu-de-la-street@laforce.be";	
	
	

for (int i = 0; i<carnet.nombreDeContacts; i++)
	{
	printf("Le nom est: %s\n", (p+i*sop)->nom);
	printf("Le prénom est: %s\n", (p+i*sop)->prenom);
	printf("L'adresse est: %s\n\n", (p+i*sop)->adresse);
	}
	
//retrouverAdresse(carnet, "Skywalker");


}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*
. Exercice 4 Spécifiez et écrivez une fonction C permettant de recherche l’adresse électro-
nique d’une personne donnée. Plus précisément, la fonction prendra pour argument un répertoire
ainsi que la nom de la personne dont on cherche l’adresse. Si la personne se trouve dans le réper-
toire, la fonction affichera son email et retournera une valeur entière non nulle. Sinon, la fonction
renverra une valeur nulle
*/

int retrouverAdresse(Repertoire r, char* n)
{

int sop = sizeof(Personne);
for (int i = 0; i<r.nombreDeContacts; i++)
{
Personne *p = r.contacts;

if(tester_string(n, (p+i*sop)->nom))
{
printf("\nL'adresse mail est %s\n" , (p+i*sop)->adresse);
return 1;
}

}

return 0;
}

				////////////////////////////////////////////////////////////////////////////

void testExercice4()
{

Repertoire carnet;
carnet.nombreDeContacts = 3;
carnet.contacts 	= malloc(sizeof(Personne)*carnet.nombreDeContacts);
Personne* p 		= carnet.contacts;
int sop 		= sizeof(Personne);

(p+0*sop)->nom 	   = "Lullaby";
(p+0*sop)->prenom  = "OfBirdland";
(p+0*sop)->adresse = "ThatwhatI@love.com";

(p+1*sop)->nom 	   = "Autumn";
(p+1*sop)->prenom  = "Leaves";
(p+1*sop)->adresse = "LesFeuillesMortes@Prevert.fr";

(p+2*sop)->nom 	   = "Trenet";
(p+2*sop)->prenom  = "Charles";
(p+2*sop)->adresse = "yadelajoie@gmal.be";


retrouverAdresse(carnet, "Trenet");



}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{

printf("\n\n Exercice 1 \n\n");
testExercice1();
printf("\n\n Exercice 2 \n\n");
testExercice2();
printf("\n\n Exercice 3 \n\n");
testExercice3();
printf("\n\n Exercice 4 \n\n");
testExercice4();
}
