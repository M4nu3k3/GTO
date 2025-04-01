import turtle
import os
import subprocess  # For running command-line commands

# Configuration des dimensions
LARGEUR_FEUILLE, HAUTEUR_FEUILLE = 595, 842  # Taille A4 en pixels

# Paramètres
RAYON_CERCLE = 10
ESPACEMENT_X = 50
ESPACEMENT_Y = 40

# Dessiner un rectangle
def dessiner_rectangle(x, y, largeur, hauteur):
    turtle.penup()
    turtle.goto(x, y)
    turtle.pendown()
    for _ in range(2):
        turtle.forward(largeur)
        turtle.right(90)
        turtle.forward(hauteur)
        turtle.right(90)

# Dessiner cadre pour traitement d'image
def dessiner_cadre():
    marge = 20
    dessiner_rectangle(-LARGEUR_FEUILLE//2 + marge, HAUTEUR_FEUILLE//2 - marge,
                       LARGEUR_FEUILLE - 2*marge, HAUTEUR_FEUILLE - 2*marge)

# Dessiner cadre pour feuille A4
def dessiner_feuille():
    marge = 0
    dessiner_rectangle(-LARGEUR_FEUILLE//2 + marge, HAUTEUR_FEUILLE//2 - marge,
                       LARGEUR_FEUILLE - 2*marge, HAUTEUR_FEUILLE - 2*marge)
    
# Dessiner bandeau ID horizontal
def dessiner_bandeau_id():
    x, y = -200, 350
    dessiner_rectangle(x, y, 400, 80)
    turtle.penup()
    turtle.goto(x + 10, y - 35)
    turtle.write("ID Étudiant", font=("Arial", 12, "bold"))

    start_x = x + 110
    start_y = y - 25

    for row in range(2):
        for chiffre in range(10):
            turtle.penup()
            turtle.goto(start_x + chiffre * 25, start_y - row * 25)
            turtle.pendown()
            turtle.circle(RAYON_CERCLE)
            turtle.penup()
            turtle.goto(start_x + chiffre * 25, start_y - RAYON_CERCLE/2 - 3 - row * 25 + 10)
            turtle.write(chiffre, align="center", font=("Arial", 8, "normal"))

# Dessiner réponses espacées avec lettres dans les cercles
def dessiner_reponses():
    start_x, start_y = -220, 150  # abaissé ici
    question = 1

    for col in range(2):
        for row in range(10):
            x = start_x + col * 250
            y = start_y - row * ESPACEMENT_Y

            turtle.penup()
            turtle.goto(x, y - RAYON_CERCLE/2)
            turtle.write(f"{question}", align="center", font=("Arial", 12, "bold"))

            for idx, lettre in enumerate("ABCD"):
                cx = x + 50 + idx * ESPACEMENT_X
                cy = y

                turtle.penup()
                turtle.goto(cx, cy - RAYON_CERCLE)
                turtle.pendown()
                turtle.circle(RAYON_CERCLE)

                turtle.penup()
                turtle.goto(cx, cy - RAYON_CERCLE/2 - 3)
                turtle.write(lettre, align="center", font=("Arial", 9, "normal"))

            question += 1

    # Ligne de séparation centrale
    turtle.penup()
    turtle.goto(start_x + 225, start_y + 20)
    turtle.pendown()
    turtle.right(90)
    turtle.forward(ESPACEMENT_Y * 10)
    turtle.left(90)

# Fonction principale
def main():
    turtle.setup(width=LARGEUR_FEUILLE, height=HAUTEUR_FEUILLE)
    turtle.speed("fastest")
    turtle.hideturtle()

    dessiner_cadre()
    dessiner_feuille()
    dessiner_bandeau_id()
    dessiner_reponses()

    # Capturer le canvas en EPS
    canvas = turtle.getcanvas()
    eps_file = os.path.join(os.path.dirname(__file__), "feuille_A4.eps")
    canvas.postscript(file=eps_file)

    print(f"EPS file saved at: {eps_file}")  # Vérifier le chemin du fichier EPS

    # Convertir l'EPS en PDF dans le même répertoire
    pdf_file = os.path.join(os.path.dirname(__file__), "QCM_enonce.pdf")
    subprocess.run(["epstopdf", eps_file, "--outfile", pdf_file])

    print(f"PDF file saved at: {pdf_file}")  # Vérifier le chemin du fichier PDF

    # Supprimer le fichier EPS après conversion
    if os.path.exists(eps_file):
        os.remove(eps_file)
        print(f"EPS file deleted: {eps_file}")

    turtle.done()

if __name__ == "__main__":
    main()
