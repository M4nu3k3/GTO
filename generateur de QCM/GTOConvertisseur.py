from PIL import Image
import struct


def get_mean_intensity(image, box):
    region = image.crop(box)
    pixels = list(region.getdata())
    return sum(pixels) / len(pixels)


def recup_id(bmp_path):
    img = Image.open(bmp_path).convert("L")
    identifiant = []

    top = 65
    bottom = 86
    xtop = 225
    xbot = 246
    
    # Lire 3 chiffres horizontalement
    for i in range(3):
        box_digits = [
            (xtop + 25*j, top + 25*i, xbot + 25*j, bottom + 25*i)
            for j in range(10)
        ]
        intensities = [get_mean_intensity(img, box) for box in box_digits]
        idx = intensities.index(min(intensities))
        identifiant.append(str(idx))

    return "".join(identifiant)       # normalement : '001' ou '002'

def recup_reponses_des_questions(bmp_path, nb_questions=20):
    img = Image.open(bmp_path).convert("L")
    
    reponses_detectees = []

    top = 175
    bottom = 196
    xtop = 90
    xbot = 111
    offset_x = 0
    taille_h = 40
    taille_l = 35
    
    for i in range(nb_questions):
        if top + (taille_h*i) >= 560: 
            top = top - (taille_h*i)
            bottom = bottom - (taille_h*i)
            offset_x += 270
        
        boxes = [
            (xtop + taille_l*j + offset_x, top + taille_h*i, xbot + taille_l*j + offset_x, bottom + taille_h*i)
            for j in range(4)
        ]
        
        # print('Question ', i+1, '\n Coordonnées : ', boxes , '\n')    # Test emplacements des A, B, C, D
        
        intensities = [get_mean_intensity(img, box) for box in boxes]
        # print('Question ', i+1, '\n Intensitées : ', intensities , '\n')  # Test intensitées des A, B, C, D
        
        idx = intensities.index(min(intensities))  # case la plus foncée = cochée
        # TODO : en dessous de [210.447 - 213.367 ,
        #                       207.313 - 211.054 ,
        #                       210.57 - 213.955 ,
        #                       208.487 - 212.211]
        reponses_detectees.append(['A', 'B', 'C', 'D'][idx])
    
    return reponses_detectees       # normalement : ['B', 'C', 'A', ...]


def recup_id_qcm(bmp_path):
    img = Image.open(bmp_path).convert("L")
    identifiant = []

    top = 715
    bottom = 735
    xtop = 220
    xbot = 241
    
    # Lire 3 chiffres horizontalement
    for i in range(3):
        box_digits = [
            (xtop + 25*j, top + 25*i, xbot + 25*j, bottom + 25*i)
            for j in range(10)
        ]
        intensities = [get_mean_intensity(img, box) for box in box_digits]
        idx = intensities.index(min(intensities))
        identifiant.append(str(idx))

    return "".join(identifiant)         # normalement : '001'


def convert_answers_to_hex(answers, mode="ascii"):
    hex_list = []
    for a in answers:
        if mode == "ascii":
            hex_val = hex(ord(a))  # 'A' -> 0x41
        elif mode == "numeric":
            hex_val = hex("ABCD".index(a))  # 'A' -> 0, etc.
        else:
            raise ValueError("Mode non reconnu : 'ascii' ou 'numeric'")
        hex_list.append(hex_val)
    return hex_list


def write_gto_file(filename, candidate_id, qcm_id, note, corrections, reponses_eleve):
    """
    Écrit un fichier .GTO avec :
    - candidate_id : 3 caractères
    - qcm_id : 3 caractères
    """
    signature = b".GTO"
    
    # Limite à 3 caractères chacun
    candidate_bytes = candidate_id.encode("ascii", errors="ignore")[:3]
    candidate_padded = candidate_bytes + b"\x00" * (3 - len(candidate_bytes))
    
    qcm_bytes = qcm_id.encode("ascii", errors="ignore")[:3]
    qcm_padded = qcm_bytes + b"\x00" * (3 - len(qcm_bytes))
    
    nb_questions = len(corrections)
    nb_reponses_possibles = 4
    
    note_bytes = struct.pack('<I', note)
    nb_questions_bytes = struct.pack('<I', nb_questions)
    nb_reponses_bytes = struct.pack('<I', nb_reponses_possibles)
    
    letter_to_code = {"A": 0x41, "B": 0x42, "C": 0x43, "D": 0x44}
    
    qcm_data = bytearray()
    for corr, rep in zip(corrections, reponses_eleve):
        qcm_data.append(letter_to_code[corr])
        qcm_data.append(letter_to_code[rep])
    
    data_wo_size = (
        signature +
        b'\x00\x00\x00\x00' +  # placeholder
        candidate_padded +
        qcm_padded +
        note_bytes +
        nb_questions_bytes +
        nb_reponses_bytes +
        qcm_data
    )
    
    file_size = len(data_wo_size)
    size_bytes = struct.pack('<I', file_size)
    
    final_data = (
        signature +
        size_bytes +
        candidate_padded +
        qcm_padded +
        note_bytes +
        nb_questions_bytes +
        nb_reponses_bytes +
        qcm_data
    )
    
    with open(filename, "wb") as f:
        f.write(final_data)
    
    print(f"Fichier {filename} généré ({file_size} octets)")






# === Programme principal ===
if __name__ == "__main__":
    bmp_correction = "Charlie2/00.bmp"
    bmp_eleve = "Charlie2/01.bmp"
    
    id_eleve = "".join(recup_id(bmp_eleve))
    id_qcm = "".join(recup_id_qcm(bmp_eleve))
    
    print(f"ID élève : {id_eleve}, QCM : {id_qcm}")
    
    corrections = recup_reponses_des_questions(bmp_correction)
    reponses_eleve = recup_reponses_des_questions(bmp_eleve)
    
    note = 00

    write_gto_file(
        filename=f"Charlie2/QCM_{id_qcm}_de_{id_eleve}.gto",
        candidate_id=id_eleve,
        qcm_id=id_qcm,
        note=note,
        corrections=corrections,
        reponses_eleve=reponses_eleve
    )
