from PIL import Image, ImageDraw, ImageFont

def main():
    # Taille A4 en pixels
    LARGEUR_FEUILLE, HAUTEUR_FEUILLE = 595, 842
    
    # Paramètres
    RAYON_CERCLE = 10
    ESPACEMENT_X = 35
    ESPACEMENT_Y = 40
    
    # Crée un canevas blanc
    img = Image.new("RGB", (LARGEUR_FEUILLE, HAUTEUR_FEUILLE), "white")
    draw = ImageDraw.Draw(img)
    
    # Charge (ou crée) des polices
    try:
        font_arial_big = ImageFont.truetype("arial.ttf", 14)
        font_arial_normal = ImageFont.truetype("arial.ttf", 12)
        font_arial_small = ImageFont.truetype("arial.ttf", 10)
    except:
        # Si jamais la police n'est pas trouvée
        font_arial_big = ImageFont.load_default()
        font_arial_normal = ImageFont.load_default()
        font_arial_small = ImageFont.load_default()
    
    # 1) Dessin du grand cadre extérieur
    #    (on dessine le pourtour A4, si on veut un trait tout autour)
    draw.rectangle(
        [(0, 0), (LARGEUR_FEUILLE - 1, HAUTEUR_FEUILLE - 1)],
        outline="black", width=1
    )
    
    # 2) Dessin d'un cadre intérieur (marges)
    MARGE = 15
    draw.rectangle(
        [(MARGE, MARGE), (LARGEUR_FEUILLE - MARGE, HAUTEUR_FEUILLE - MARGE)],
        outline="black", width=1
    )
    
    # 3) Bandeau ID en haut
    #    Pour ressembler à l’exemple Turtle, on le centre environ vers le haut
    x_bandeau, y_bandeau = 100, 50
    w_bandeau, h_bandeau = 400, 80
    draw.rectangle(
        [(x_bandeau, y_bandeau), (x_bandeau + w_bandeau, y_bandeau + h_bandeau)],
        outline="black", width=1
    )
    # Écriture du texte "ID Étudiant"
    draw.text(
        (x_bandeau + 10, y_bandeau + h_bandeau // 2 - 10),
        "ID Étudiant",
        fill="black",
        font=font_arial_big
    )
    
    # 4) Cercles pour les chiffres de l'ID
    #    On va faire 2 lignes x 10 colonnes (comme dans ton code Turtle).
    start_x = x_bandeau + 135
    start_y = y_bandeau + h_bandeau // 2 - 10  # aligné au texte
    for row in range(2):
        for chiffre in range(10):
            # Coordonnées pour le centre du cercle
            cx = start_x + chiffre * 25
            cy = start_y + row * 25
            
            # Définition de la zone du cercle (ellipse)
            # (cx - RAYON, cy - RAYON) -> (cx + RAYON, cy + RAYON)
            draw.ellipse(
                [(cx - RAYON_CERCLE, cy - RAYON_CERCLE),
                 (cx + RAYON_CERCLE, cy + RAYON_CERCLE)],
                outline="black", width=1
            )
            # Afficher la valeur du chiffre dedans
            # On se décale un peu vers le haut/gauche pour centrer
            draw.text(
                (cx - 3, cy - 7),
                str(chiffre),
                fill="black",
                font=font_arial_small
            )
    
    # 5) Dessin des questions + cases ABCD
    #    On va placer 2 colonnes de 10 questions (20 questions au total)
    #    Les cercles "ABCD" seront placés à droite du numéro de question.
    start_x_questions = 60
    start_y_questions = 180
    question = 1
    
    for col in range(2):
        for row in range(10):
            # Position du "numéro de question"
            x_num = start_x_questions + col * 270
            y_num = start_y_questions + row * ESPACEMENT_Y
            
            # Écriture du numéro
            draw.text(
                (x_num, y_num),
                str(question),
                fill="black",
                font=font_arial_normal
            )
            
            # Cercles pour A, B, C, D
            for idx, lettre in enumerate("ABCD"):
                cx = x_num + 40 + idx * ESPACEMENT_X
                cy = y_num + 5  # Légère correction
                draw.ellipse(
                    [(cx - RAYON_CERCLE, cy - RAYON_CERCLE),
                     (cx + RAYON_CERCLE, cy + RAYON_CERCLE)],
                    outline="black", width=1
                )
                # Lettrage
                draw.text(
                    (cx - 3, cy - 8),
                    lettre,
                    fill="black",
                    font=font_arial_small
                )
            
            question += 1
    
    # 6) Optionnel : Ligne de séparation (verticale) entre les 2 colonnes
    #    On place une ligne verticale entre les 2 colonnes de réponses
    x_line = start_x_questions + 245
    y_line_top = start_y_questions - 5
    y_line_bottom = y_line_top + ESPACEMENT_Y * 10
    draw.line(
        [(x_line, y_line_top), (x_line, y_line_bottom)],
        fill="black", width=1
    )
    
    # 7) Sauvegarde au format JPG
    output_jpg = "formulaire.jpg"
    img.save(output_jpg, "JPEG")
    print(f"Image générée dans le fichier {output_jpg} !")

if __name__ == "__main__":
    main()
