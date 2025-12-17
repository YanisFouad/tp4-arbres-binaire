build:
	gcc -o main ./src/main.c ./src/affichage_index.c ./src/arbre_index.c ./src/global.c ./src/indexation_fichier.c ./src/liste_position.c ./src/occurences_mot.c ./src/construction_texte.c ./src/liste_occurences.c -Wall -Wextra -g

clean:
	rm -f main

run: build
	./main