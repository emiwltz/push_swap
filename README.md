# Push_swap - Guide d'onboarding

## Introduction

Bienvenue sur le projet **push_swap** ! Ce README te permettra de comprendre rapidement l'état actuel du projet, les choix architecturaux qui ont été faits, et ce qu'il reste à implémenter.

### Qu'est-ce que push_swap ?

Push_swap est un projet 42 qui consiste à trier une pile d'entiers en utilisant uniquement deux piles (stack A et stack B) et un ensemble limité d'opérations. L'objectif est de trouver la séquence d'opérations la plus courte possible pour trier les nombres.

**Contraintes :**
- On ne peut utiliser que les opérations définies par le sujet (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr)
- Il faut minimiser le nombre d'opérations
- Le code doit respecter la Norme 42 (25 lignes/fonction max, 5 fonctions/fichier max, etc.)

### Objectifs de performance

Le projet sera évalué selon ces critères :

**Pour 100 nombres :**
- Excellent : < 700 opérations
- Bon : < 1500 opérations
- Passable : < 2000 opérations

**Pour 500 nombres :**
- Excellent : < 5500 opérations
- Bon : < 8000 opérations
- Passable : < 12000 opérations

---

## Architecture du projet

### Structure des dossiers

```
push_swap/
├── includes/
│   └── push_swap.h          # Header principal avec les structures et prototypes
├── src/
│   ├── main.c               # Point d'entrée du programme
│   ├── parse/               # Parsing et validation des arguments
│   │   ├── check_args.c     # Validation des arguments et flags
│   │   ├── check_double.c   # Vérification des doublons (à implémenter)
│   │   └── set_flags.c      # Gestion des flags (--bench, --simple, etc.)
│   └── utils/               # Utilitaires généraux
│       ├── check_string.c   # Validation des chaînes de caractères
│       ├── ft_strcmp.c      # Comparaison de chaînes
│       └── print_error.c    # Gestion des erreurs
├── libft/                   # Bibliothèque personnelle 42
├── Makefile                 # Compilation
└── CLAUDE.md                # Instructions pour l'assistant AI (mode pédagogique)

À CRÉER :
├── src/
│   ├── stack/               # Gestion des piles
│   ├── ops/                 # Implémentation des opérations
│   ├── algo/                # Algorithmes de tri
│   ├── metrics/             # Calcul du disorder
│   └── bench/               # Système de benchmark
```

### Structures de données

Le fichier `includes/push_swap.h` définit les structures principales :

#### 1. **t_node** - Nœud de liste chaînée
```c
typedef struct s_node {
    int value;              // Valeur de l'entier
    int rank;              // Rang normalisé (pour optimisations)
    struct s_node *next;   // Pointeur vers le nœud suivant
} t_node;
```

#### 2. **t_stack** - Pile (stack)
```c
typedef struct s_stack {
    t_node *head;          // Sommet de la pile
    t_node *tail;          // Fond de la pile
    size_t size;           // Nombre d'éléments
} t_stack;
```

#### 3. **t_algo** - Énumération des algorithmes
```c
typedef enum e_algo {
    ALGO_UNSET,            // Aucun algo sélectionné
    ALGO_SIMPLE,           // Algo basique (pour petites piles)
    ALGO_MEDIUM,           // Algo intermédiaire
    ALGO_COMPLEX,          // Algo avancé
    ALGO_ADAPTIVE          // Algo qui s'adapte à la taille
} t_algo;
```

#### 4. **t_ctx** - Contexte d'exécution
```c
typedef struct s_ctx {
    bool bench_enabled;    // Mode benchmark activé ?
    t_algo algo;           // Algorithme choisi
    int flag_count;        // Nombre de flags algo (doit être ≤ 1)
    int bench_count;       // Nombre de flags bench (doit être ≤ 1)
} t_ctx;
```

---

## Choix de conception

### 1. Système de flags modulaire

Le programme accepte des flags optionnels pour tester différents algorithmes et activer le benchmark :

```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <numbers>
```

**Exemples :**
```bash
./push_swap 3 2 1                    # Tri par défaut
./push_swap --simple 3 2 1           # Force l'algo simple
./push_swap --bench 4 67 3 87 23     # Active le mode benchmark
./push_swap --complex --bench 1 2 3  # Combine les deux
```

**Règles de validation :**
- Maximum 1 flag d'algorithme
- Maximum 1 flag `--bench`
- Les flags peuvent être mélangés avec les nombres dans n'importe quel ordre

### 2. Double validation (two-pass parsing)

Le parsing se fait en deux étapes (voir `src/parse/set_flags.c:71-90`) :

**Premier passage (`first_check`) :**
- Détecte les arguments vides
- Identifie et stocke les flags dans le contexte
- Vérifie qu'il n'y a pas trop de flags
- Valide que chaque argument est soit un nombre, soit un flag

**Second passage (`second_check`) :**
- Nettoie les flags de la liste d'arguments
- Vérifie que les nombres sont valides (INT_MIN à INT_MAX)
- Prépare le tableau final de nombres

### 3. Gestion d'erreurs stricte

Toute erreur affiche "Error\n" sur stderr et retourne 1 :
- Arguments non numériques
- Nombres hors limites (< INT_MIN ou > INT_MAX)
- Doublons dans la liste
- Flags invalides ou multiples
- Arguments vides

### 4. Séparation claire des responsabilités

**Principe UNIX :** Chaque module a une responsabilité unique :
- `parse/` : Validation et extraction des arguments
- `stack/` (à créer) : Manipulation des structures de données
- `ops/` (à créer) : Opérations atomiques sur les piles
- `algo/` (à créer) : Logique de tri
- `metrics/` (à créer) : Analyse et mesures
- `bench/` (à créer) : Affichage des performances

---

## État actuel (ce qui est fait)

### ✅ Implémenté (~300 lignes)

#### 1. **Parsing des arguments**
- `src/parse/check_args.c` :
  - `arg_is_valid()` : Vérifie si un argument est un nombre ou un flag valide
  - `is_a_flag()` : Détecte si une chaîne est un flag reconnu
  - `clean_flags()` : Filtre les flags pour ne garder que les nombres

- `src/parse/set_flags.c` :
  - `set_algo()` : Stocke l'algorithme choisi dans le contexte
  - `set_flags()` : Parse un flag et met à jour le contexte
  - `first_check()` : Validation de premier niveau
  - `second_check()` : Validation de second niveau (INT overflow, etc.)

#### 2. **Utilitaires**
- `src/utils/ft_strcmp.c` : Comparaison de chaînes
- `src/utils/print_error.c` : Affiche "Error\n" sur stderr
- `src/utils/check_string.c` : Validation des chaînes numériques

#### 3. **Point d'entrée**
- `src/main.c` :
  - `ctx_init()` : Initialisation du contexte
  - `main()` : Orchestre le parsing (pour l'instant)

#### 4. **Makefile**
- Compilation avec flags `-Wall -Wextra -Werror -g`
- Intégration de la libft
- Règles standard : `all`, `clean`, `fclean`, `re`

---

## Ce qu'il reste à faire

### 🔴 Priorité 1 : Module stack (création et manipulation)

**Fichiers à créer dans `src/stack/` :**

#### stack_init.c
- `t_stack *stack_create(void)` : Alloue et initialise une pile vide
- `void stack_free(t_stack *stack)` : Libère la mémoire d'une pile
- `t_node *node_create(int value)` : Crée un nouveau nœud

#### stack_operations.c
- `void stack_push(t_stack *stack, t_node *node)` : Ajoute un nœud en haut
- `t_node *stack_pop(t_stack *stack)` : Retire et retourne le nœud du haut
- `t_node *stack_peek(t_stack *stack)` : Retourne le nœud du haut sans le retirer

#### stack_utils.c
- `bool stack_is_empty(t_stack *stack)` : Vérifie si la pile est vide
- `bool stack_is_sorted(t_stack *stack)` : Vérifie si la pile est triée
- `void stack_print(t_stack *stack)` : Affiche la pile (debug)

#### stack_populate.c
- `int stack_fill_from_args(t_stack *stack, char **numbers)` : Remplit la stack A avec les arguments parsés
- `int check_duplicates(t_stack *stack)` : Vérifie qu'il n'y a pas de doublons

**Intégration à faire :**
- Compléter `src/main.c` pour créer et remplir la stack A après le parsing
- Ajouter la gestion de la libération mémoire en cas d'erreur

---

### 🔴 Priorité 2 : Module ops (opérations de base)

**Fichiers à créer dans `src/ops/` :**

Les opérations du sujet push_swap doivent être implémentées en deux niveaux :
1. **Opérations raw (bas niveau)** : Manipulent les piles sans afficher
2. **Opérations op_* (haut niveau)** : Appellent les raw + affichent l'opération

#### ops_swap.c
- `void swap(t_stack *stack)` : Échange les 2 premiers éléments
- `void op_sa(t_stack *a)` : Affiche "sa\n" + swap(a)
- `void op_sb(t_stack *b)` : Affiche "sb\n" + swap(b)
- `void op_ss(t_stack *a, t_stack *b)` : Affiche "ss\n" + swap(a) + swap(b)

#### ops_push.c
- `void push(t_stack *dest, t_stack *src)` : Déplace le top de src vers dest
- `void op_pa(t_stack *a, t_stack *b)` : Affiche "pa\n" + push(a, b)
- `void op_pb(t_stack *a, t_stack *b)` : Affiche "pb\n" + push(b, a)

#### ops_rotate.c
- `void rotate(t_stack *stack)` : Décale tous les éléments vers le haut (premier devient dernier)
- `void op_ra(t_stack *a)` : Affiche "ra\n" + rotate(a)
- `void op_rb(t_stack *b)` : Affiche "rb\n" + rotate(b)
- `void op_rr(t_stack *a, t_stack *b)` : Affiche "rr\n" + rotate(a) + rotate(b)

#### ops_reverse_rotate.c
- `void reverse_rotate(t_stack *stack)` : Décale tous les éléments vers le bas (dernier devient premier)
- `void op_rra(t_stack *a)` : Affiche "rra\n" + reverse_rotate(a)
- `void op_rrb(t_stack *b)` : Affiche "rrb\n" + reverse_rotate(b)
- `void op_rrr(t_stack *a, t_stack *b)` : Affiche "rrr\n" + reverse_rotate(a) + reverse_rotate(b)

**Points d'attention :**
- Gérer les cas limites (pile vide, 1 seul élément)
- Mettre à jour correctement les pointeurs head/tail
- Mettre à jour le champ size

---

### 🟡 Priorité 3 : Module algo (algorithmes de tri)

**Fichiers à créer dans `src/algo/` :**

#### algo_simple.c
Pour de petites piles (2-5 éléments), tri exhaustif optimisé :
- `void sort_simple(t_stack *a, t_stack *b)` : Gère les cas 2, 3, 4, 5 éléments
- `void sort_three(t_stack *a)` : Tri optimal pour 3 éléments (max 2 ops)
- `void sort_five(t_stack *a, t_stack *b)` : Tri optimal pour 5 éléments

#### algo_medium.c
Pour des piles moyennes (< 100 éléments), approche par chunks :
- `void sort_medium(t_stack *a, t_stack *b)` : Tri par segments
- Idée : Diviser en petits groupes, pousser vers B, puis ramener dans l'ordre

#### algo_complex.c
Pour de grandes piles (100-500 éléments), algorithmes avancés :
- `void sort_complex(t_stack *a, t_stack *b)` : Radix sort ou algorithme optimisé
- Utiliser le champ `rank` de `t_node` pour normaliser les valeurs
- Viser < 700 ops pour 100 éléments, < 5500 pour 500

#### algo_adaptive.c
Sélectionne automatiquement l'algo selon la taille :
- `void sort_adaptive(t_stack *a, t_stack *b)` : Choisit l'algo approprié

#### algo_dispatcher.c
- `void execute_sort(t_stack *a, t_stack *b, t_ctx *ctx)` : Appelle le bon algo selon le contexte

**Conseil :** Implémenter dans l'ordre simple → medium → complex. L'algo simple est nécessaire pour valider que les opérations fonctionnent.

---

### 🟡 Priorité 4 : Module metrics (calcul du disorder)

**Fichiers à créer dans `src/metrics/` :**

#### disorder.c
- `int calculate_disorder(t_stack *stack)` : Calcule le nombre d'inversions
  - Une inversion = paire (i, j) où i < j mais value[i] > value[j]
  - Exemple : [3, 1, 2] a 2 inversions : (3,1) et (3,2)
- `float disorder_ratio(t_stack *stack)` : Retourne disorder / disorder_max
  - disorder_max = n*(n-1)/2 pour une pile de taille n

#### rank.c
- `void assign_ranks(t_stack *stack)` : Normalise les valeurs en rangs (0, 1, 2, ...)
  - Permet d'utiliser des algos bit-based même avec des valeurs négatives
  - Exemple : [-10, 5, 100] devient [0, 1, 2]

**Utilité :**
- Afficher le disorder initial et final en mode `--bench`
- Décider si un algo adaptatif doit utiliser une stratégie simple ou complexe

---

### 🟢 Priorité 5 : Module bench (système de benchmark)

**Fichiers à créer dans `src/bench/` :**

#### bench.c
- `void bench_start(t_ctx *ctx, t_stack *a)` : Affiche les infos initiales
  - Taille de la pile
  - Disorder initial
  - Algorithme sélectionné

- `void bench_end(t_ctx *ctx, int op_count)` : Affiche les résultats
  - Nombre d'opérations total
  - Disorder final (devrait être 0)
  - Évaluation (excellent/bon/passable selon les seuils)

**Format suggéré :**
```
=== PUSH_SWAP BENCHMARK ===
Stack size: 100
Initial disorder: 2341 (47.2%)
Algorithm: ALGO_COMPLEX
---------------------------
Operations: 687
Final disorder: 0
Grade: EXCELLENT (< 700)
===========================
```

---

### 🔵 Bonus (optionnel)

#### Checker
Programme séparé qui vérifie si une séquence d'opérations trie correctement :
```bash
./checker 3 2 1
sa
rra
^D
OK
```

#### Visualiseur
Script Python/JS qui affiche graphiquement le tri en cours.

---

## Comment compiler et tester

### Compilation
```bash
make        # Compile push_swap
make clean  # Supprime les .o
make fclean # Supprime tout
make re     # Recompile from scratch
```

### Tests de base

**Test manuel :**
```bash
./push_swap 3 2 1
# Devrait afficher les opérations de tri
```

**Test avec flags :**
```bash
./push_swap --simple 4 67 3 87 23
./push_swap --bench 2 1 3 5 4 6
```

**Test d'erreurs :**
```bash
./push_swap 1 2 2         # Doublon -> Error
./push_swap abc           # Non numérique -> Error
./push_swap 9999999999    # Overflow -> Error
./push_swap --simple --medium 1  # 2 flags algo -> Error
```

### Tests automatisés (à créer)

Un script de test serait utile pour vérifier :
1. Que les petites piles (3-5 éléments) se trient correctement
2. Que le nombre d'opérations respecte les seuils
3. Que les cas d'erreur sont bien gérés

Exemple de structure :
```bash
# test.sh
for size in 3 5 10 100 500; do
    ARG=$(seq 1 $size | shuf | tr '\n' ' ')
    ./push_swap $ARG | ./checker $ARG
done
```

---

## Règles importantes (CLAUDE.md)

⚠️ **Mode pédagogique activé** : Ce projet suit une approche d'apprentissage stricte.

### L'assistant IA ne doit PAS :
- Écrire les algorithmes de tri (simple, medium, complex, adaptive)
- Écrire la logique des opérations de stack (sa, sb, pa, pb, etc.)
- Écrire le calcul du disorder
- Fournir des solutions complètes aux problèmes algorithmiques

### L'assistant IA peut :
- Écrire le code boilerplate (Makefile, headers, structures)
- Aider au debugging en posant des questions
- Expliquer des concepts sans donner l'implémentation
- Écrire les utilitaires non-algorithmiques

### Pourquoi ?
Le but est de **comprendre** les algorithmes, pas juste de les copier. Pendant la défense, tu devras expliquer chaque partie du code. Si l'IA écrit l'algo, tu ne pourras pas le défendre.

**En cas de blocage :** L'IA te guidera avec des questions pour te faire réfléchir, mais ne donnera pas la solution directement.

---

## Ordre de développement recommandé

1. **Terminer le parsing** : Implémenter `check_double.c` et finaliser la validation
2. **Module stack** : Sans stack fonctionnel, impossible de tester quoi que ce soit
3. **Module ops** : Implémente les 11 opérations + teste-les individuellement
4. **Algo simple** : Commence par trier 3, puis 5 éléments (cas de base)
5. **Algo medium** : Développe une stratégie pour ~50-100 éléments
6. **Metrics** : Ajoute le calcul du disorder pour mesurer les performances
7. **Bench** : Affiche les résultats de façon lisible
8. **Algo complex** : Optimise pour les grandes piles (100-500)
9. **Algo adaptive** : Combine les algos précédents
10. **Tests et optimisation** : Peaufine pour atteindre les seuils d'excellence

---

## Ressources utiles

### Documentation officielle
- **Sujet push_swap** : /sgoinfre/subject.pdf (ou voir l'intranet)
- **Norminette** : `norminette src/ includes/` (vérifie la norme)

### Concepts à maîtriser
- **Listes chaînées** : Les stacks sont des listes chaînées
- **Complexité algorithmique** : O(n log n) vs O(n²)
- **Algorithmes de tri** :
  - Tri par insertion (base pour algo simple)
  - Radix sort (excellent pour grandes piles)
  - Tri par sélection (utile pour comprendre la logique)

### Outils de test
- `valgrind ./push_swap 3 2 1` : Vérifie les fuites mémoires
- Générateur de nombres aléatoires : `seq 1 100 | shuf | tr '\n' ' '`
- Compteur d'opérations : `./push_swap 3 2 1 | wc -l`

---

## Tips et pièges à éviter

### ⚠️ Pièges courants
1. **Segfault sur pile vide** : Toujours vérifier `stack->size > 0` avant d'accéder aux nœuds
2. **Fuites mémoires** : Libérer tous les nœuds en cas d'erreur
3. **Oubli du tail** : Maintenir `head` ET `tail` à jour (sinon rotate cassé)
4. **Overflow INT** : Tester avec INT_MIN et INT_MAX
5. **Doublons non détectés** : Vérifier après le parsing complet

### ✅ Bonnes pratiques
1. **Teste chaque opération individuellement** : Écris un petit main qui teste `sa`, `pb`, etc.
2. **Affiche les stacks** : Une fonction `stack_print()` est invaluable pour le debug
3. **Commence petit** : Trie 3 nombres avant 500
4. **Commits fréquents** : Un commit par fonctionnalité (git log déjà existant)
5. **Norminette en continu** : Lance `norminette` AVANT de commit

### 🎯 Objectif final
Un binaire `push_swap` qui :
- Parse correctement tous les cas (valides et invalides)
- Trie n'importe quelle pile d'entiers
- Respecte les seuils d'opérations pour obtenir 100/100
- Ne leak jamais de mémoire
- Respecte la Norme 42

---

## Contact et questions

Si tu as des questions sur :
- **L'architecture** : Relis ce README ou regarde `includes/push_swap.h`
- **Un bug spécifique** : Utilise `valgrind` et des prints debug
- **Un concept algorithmique** : Demande à l'IA en mode pédagogique (elle te guidera sans donner la réponse)

**N'oublie pas** : L'objectif est d'apprendre, pas juste de finir le projet. Prends le temps de comprendre chaque algo avant de coder.

Bon courage ! 🚀
