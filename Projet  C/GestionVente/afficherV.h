void afficherArticles(int); // afficher uniquement l'article a la position indiqué
void afficherLibelle(char[]); // afficher les libelles et marque sans '_'
int menuVente(void);   // menu vente par position, libelle...Preciser le choix avec l'annulation de la casse:
void avantArticle(void); // position,id, libelle,marque,couleur...
int detailsArticle(void); // demande la position puis donne details de l'article puis demande si ajouter panier
int afficherArticlesTrouvesLibelle(char[]); // affiche l'article trouvé par recherche sur libelle.
int afficherArticlesTrouvesCouleur(char[]);
int afficherArticlesTrouvesPrix(int);
int verifierPos(void); // retourne 0 si pos entré ne figure pas parmi les positions affichées

