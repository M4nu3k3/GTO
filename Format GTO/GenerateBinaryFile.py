def write_hex_to_file(filename, hex_data):
    """
    Crée un fichier et écrit des données en hexadécimal dedans.
    :param filename: Nom du fichier à créer.
    :param hex_data: Chaîne de caractères représentant les données en hexadécimal.
    """
    # Convertir la chaîne hexadécimale en bytes
    binary_data = bytes.fromhex(hex_data)
    # Écrire les données dans le fichier
    with open(filename, "wb") as file:
        file.write(binary_data)
    print(f"Données hexadécimales écrites dans {filename}")
 
# Exemple d'utilisation
hex_string = "48656c6c6f20576f726c6421"  # Correspond à "Hello World!"

Nom_Candidat = "Jean Dupond"

Données_Test = [[0,232,0,0],[0,0,213,0]]

#Write Candidate name at file start
write_hex_to_file("output.bin", Nom_Candidat)
write_hex_to_file("output.bin", Données_Test)
