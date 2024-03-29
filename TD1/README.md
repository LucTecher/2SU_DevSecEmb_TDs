# TD1 - Emily

## Création du programme

On copie-colle le programme sans oublier de rajouter les bibliothèques tout en haut.

```C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_valid(const char* password) {
	if (strcmp(password, "mypassword") == 0){
		return 1;
	} else {
		return 0;
	}
}

int main() {
	char * input = NULL;
	input = malloc(256);
	printf("Please input a word: ");
	scanf("%256s", input);

	if(is_valid(input)) {
		printf("That's correct!\n");
	} else {
		printf("That's not correct!\n");
	}

	free(input);
	return 0;
}
```

## Analyse du binaire

La commande hexdump permet de visualiser le code binaire généré par la compilation : 
![hexdump](images/hexdump_1.png)


Grâce à la commande string, on peut voir que la valeur du mot de passe (mypassword) est bien présente dans le binaire :
![strings](images/strings_1.png)

Dans le code désassemblé fourni par objdump, on peut voir la structure d'un if. On voit aussi que dans ce if, différentes valeurs sont mises dans le registre de retour aex. On peut en conclure que si on veut que la fonction "is_valid" retourne tout le temps true (1), il faut modifier le code assembleur pour qu'il mette toujours la valeur 1 dans le registre eax !

![is_valid](images/is_valid_assembly.png)

Le code machine qui correspond à retourner 1 dans les deux cas est :
`75 07 B8 01 00 00 00 EB 05 B8 01 00 00 00`

## Binary patching

On peut voir que l'octet à modifier est en position 0x11B0 :
![](images/if_in_assembly.png)

On modifie cet octet grâce à la commande dd, et on test le binaire obtenu avec un mot de passe aléatoire. On constate que tout mot de passe est valide :
![](images/binary_fix.png)

## Questions

* Quelle différence dans un environnement ARM?

Dans un environnement ARM les instuctions assembleur sont différentes.

* Comprendre le lien les attaques physiques / expliquez quelles sont les attaques par patching possibles sur une boucle for.

On peut imaginer une attaque physique ou un méchant attaquant utilise un aimant ou autre chose pour modifier un bit de la même manière que nous l'avons fait logiciellement.

Une boucle for n'est qu'un if répété, elle contient donc des sauts (JNE ou JE en assembleur) pour lesquels on peut modifier l'addresse du saut. On peut aussi modifier la valeur initiale de la variable qui s'incrémente ou encore la valeur de la variable à laquelle elle est comparée. Ceci modifierait l'execution flow du programme.

* Qu'elle défense est ce que je peux utiliser contre le patching?

On peut établir un Hash du programme juste après sa compilation. Avant d'exécuter le binaire, on le hasherait puis on pourrait comparer ce hash au hash original. S'ils sont différents, cela veut dire que le binaire a été altéré !