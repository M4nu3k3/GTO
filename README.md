# Projet GTO  ![Languages](https://img.shields.io/badge/Languages-C%2C%20Python-blue) ![Languages](https://img.shields.io/badge/Languages-Carte%20STM32%2C%20Ecran%20OLED-green)

**Projet en cours de réalisation**

Ce projet a été réalisé sur une carte STM32G431KBTx et un écran TFT ST7789V, avec une communication SPI. Il a pour objectif d'afficher des informations à l'écran via des fonctions d'affichage personnalisées, avec une interface simple et directe, dans le cadre d'un projet pédagogique. Projet réalisé à 3 : Emmanuel Bruchard, Bastien Bourdin et Matthieu Damien

## Fonctionnalités principales

- Initialisation complète de l'écran ST7789V
- Affichage d'une chaîne de caractères à l'écran
- Utilisation d'une police personnalisée (6x12)
- Fonctions de dessin (point, ligne, rectangle, cercle)
- Rotation de l'affichage
- Défilement vertical
- Communication SPI via HAL

## Matériel utilisé

- Carte STM32G431KBTx
- Écran TFT ST7789V 1.3" (240x240)
- Connexion SPI : SCK sur PA5, MOSI sur PA7, NSS sur PA4
- Alimentation 3.3V

## Compilation

Le projet a été développé sous STM32CubeIDE. Il est entièrement compatible avec cet environnement. Le fichier `.ioc` est fourni, avec les configurations nécessaires pour SPI1, GPIO et les horloges système.

Voir le tableau ici : https://excalidraw.com/#room=50f86837b22fc74da657,5Z5Pb0o4Y56OWGFS0vLuXg

Google doc : https://docs.google.com/document/d/1LATpN_it4jmHfyVcG99JMaECTmQSpx4lkzkocTupbt8/edit?tab=t.0
