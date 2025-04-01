import turtle
import os
import subprocess

# Configuration des dimensions pour le format A4 en orientation portrait
LARGEUR_FEUILLE, HAUTEUR_FEUILLE = 595, 842  # Environ 21 x 29.7 cm en pixels

# Paramètres de mise en page
RAYON_CERCLE = 10
ESPACEMENT_X = 50
ESPACEMENT_Y = 40

def dessiner_rectangle(x, y, largeur, hauteur):
    """
    Dessine un rectangle avec Turtle en partant du coin supérieur gauche (x, y).
    """
    turtle.penup()
    turtle.goto(x, y)
    turtle.pendown()
    for _ in range(2):
        turtle.forward(largeur)
        turtle.right(90)
        turtle.forward(hauteur)
        turtle.right(90)

def dessiner_cadre():
    """
    Dessine un cadre pour le traitement d'image avec une marge autour de la feuille A4.
    """
    marge = 20
    dessiner_rectangle(
        -LARGEUR_FEUILLE // 2 + marge,
        HAUTEUR_FEUILLE // 2 - marge,
        LARGEUR_FEUILLE - 2 * marge,
        HAUTEUR_FEUILLE - 2 * marge
    )

def dessiner_feuille():
    """
    Dessine un second cadre représentant précisément la zone A4.
    """
    marge = 0
    dessiner_rectangle(
        -LARGEUR_FEUILLE // 2 + marge,
        HAUTEUR_FEUILLE // 2 - marge,
        LARGEUR_FEUILLE - 2 * marge,
        HAUTEUR_FEUILLE - 2 * marge
    )

def dessiner_bandeau_id():
    """
    Dessine le bandeau « ID Étudiant » en haut, avec deux lignes de 10 chiffres (0 à 9).
    """
    x, y = -200, 350
    largeur_bandeau, hauteur_bandeau = 400, 80

    # Dessiner un rectangle pour le bandeau
    dessiner_rectangle(x, y, largeur_bandeau, hauteur_bandeau)

    turtle.penup()
    turtle.goto(x + 10, y - 35)
    turtle.write("ID Étudiant", font=("Arial", 12, "bold"))

    # Position de base pour les cercles des chiffres
    start_x = x + 110
    start_y = y - 25

    for row in range(2):
        for chiffre in range(10):
            turtle.penup()
            turtle.goto(start_x + chiffre * 25, start_y - row * 25)
            turtle.pendown()
            turtle.circle(RAYON_CERCLE)
            turtle.penup()

            # Position du chiffre
            turtle.goto(start_x + chiffre * 25, start_y - RAYON_CERCLE / 2 - 3 - row * 25 + 10)
            turtle.write(str(chiffre), align="center", font=("Arial", 8, "normal"))

def dessiner_reponses(reponses):
    """
    Dessine 20 questions en deux colonnes de 10 questions chacune.
    Pour chaque question, on affiche un cercle pour A, B, C et D.
    Si la lettre est la réponse choisie, on simule un mauvais coloriage (un point plus petit dans le cercle).
    """
    start_x, start_y = -220, 150
    question = 1

    for col in range(2):  # 2 colonnes
        for row in range(10):  # 10 questions par colonne
            x = start_x + col * 250
            y = start_y - row * ESPACEMENT_Y

            # Écrire le numéro de la question
            turtle.penup()
            turtle.goto(x, y - RAYON_CERCLE / 2)
            turtle.write(f"{question}", align="center", font=("Arial", 12, "bold"))

            # Dessiner les cercles A, B, C, D
            for idx, lettre in enumerate("ABCD"):
                cx = x + 50 + idx * ESPACEMENT_X
                cy = y

                # Contour du cercle
                turtle.penup()
                turtle.goto(cx, cy - RAYON_CERCLE)
                turtle.pendown()
                turtle.circle(RAYON_CERCLE)

                # Si c'est la réponse choisie
                if reponses[question - 1] == lettre:
                    # Dessiner un point plus petit pour simuler un coloriage partiel
                    turtle.penup()
                    turtle.goto(cx, cy - (RAYON_CERCLE / 2))
                    turtle.pendown()
                    turtle.dot(RAYON_CERCLE - 1/10, "black")

                # Écrire la lettre dans le cercle
                turtle.penup()
                turtle.goto(cx, cy - RAYON_CERCLE / 2 - 3)
                turtle.write(lettre, align="center", font=("Arial", 9, "normal"))

            question += 1

    # Dessiner la ligne de séparation centrale entre les deux colonnes
    turtle.penup()
    turtle.goto(start_x + 225, start_y + 20)
    turtle.pendown()
    turtle.right(90)
    turtle.forward(ESPACEMENT_Y * 10)
    turtle.left(90)

def main():
    """
    Programme principal :
      1) Récupère les réponses de l'utilisateur pour 20 questions.
      2) Dessine la feuille A4 avec Turtle.
      3) Sauvegarde le résultat en PDF.
    """
    # 1) Récupération des réponses de l'utilisateur
    reponses = []
    for i in range(20):
        while True:
            choix = input(f"Question {i+1}: Entrez votre réponse (A, B, C ou D): ").upper()
            if choix in ['A', 'B', 'C', 'D']:
                reponses.append(choix)
                break
            else:
                print("Veuillez entrer une réponse valide (A, B, C ou D).")

    # 2) Dessin Turtle
    turtle.setup(width=LARGEUR_FEUILLE, height=HAUTEUR_FEUILLE)
    turtle.speed("fastest")
    turtle.hideturtle()

    dessiner_cadre()
    dessiner_feuille()
    dessiner_bandeau_id()
    dessiner_reponses(reponses)

    # 3) Sauvegarde en EPS -> PDF
    canvas = turtle.getcanvas()
    script_dir = os.path.dirname(__file__)
    eps_file = os.path.join(script_dir, "feuille_A4.eps")
    pdf_file = os.path.join(script_dir, "QCM_copie.pdf")

    # Capturer en EPS
    canvas.postscript(file=eps_file)
    print(f"EPS file saved at: {eps_file}")

    # Convertir EPS en PDF
    subprocess.run(["epstopdf", eps_file, "--outfile", pdf_file])
    print(f"PDF file saved at: {pdf_file}")

    # Supprimer le fichier EPS
    if os.path.exists(eps_file):
        os.remove(eps_file)
        print(f"EPS file deleted: {eps_file}")

    turtle.done()

if __name__ == "__main__":
    main()
