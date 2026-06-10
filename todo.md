# preparation
- structure de projet
  - [ok] comment est structuerer les projet en cpp
  - [ok] ou metre les .h
  - [ok] ou mettre les .cpp
  - [ok] architecutere courane ?
  - [ok] quelle sont les norme de nomage de fonction ,variable classe 
  - [ok] les boucle , condition , sont il le meme qu on java 
- [ok] compilation avec makefile
- [ok] fichier hello world
# implementation backend
## creation des classe
### Vecteur
#### Attribut
- x 
- y
### Avion
#### Attribut
1. vitesse :
   - vitesseCourrantX
   - vitesseCourantY
2. Acceleration :
   - AccelerationX
   - AccelerationY
3. Freinage :
   - CapaciteFreinageX
   - CapaciteFreinageY
4. Position :
   - Position x
   - Posistion y
5. Variation acceleration
   - X
   - Y
- vitesseDecrochage
### Aeroport
#### Attribut
1. Longeur
2. Position

### ZoneJeu
#### Attribut
1. LimitationMax
   - x
   - y
2. LimitationMin
   - x
   - y
### Jeu
#### Attribut
1. Temps
2. ZoneJeu
3. Avion
4. Aeroport

## definition des fonctions a implementer
- Avion
  - avancer(float miliseconde)
    - metter a jour le position
  - mittreAJourVitesse(float miliseconde)
    - augmeter vitesse x , y 
    - verifier si vitesse x inferieur a vitesse de decrochage
      - si oui
        - setVariationAccelerationY = 100
        - vietesse x = 0

  - augmenterAccelerationX()
    - accelerationX += varition acceleration x 
  - augmenterAccelerationY()
- Aeroport
- ZoneJeu
  - contient(Avion avion)

- Jeu
  - mettreAJour(float miliseconde)
    - verifier si avon dans le zone de jeu
      - si oui : exploser
    - verifier si l avion n a pas encore exploser
    - 
## implemetation des fonctions de classe
- Avion
- Aeroport
- ZoneJeu
# affichage
- Premier fenetre
- Desin avion
- Affichage image
- Deplacement avion , (boucle de temps)
- Ajout de bonton
- affichage labelle
- evenement sur bouton