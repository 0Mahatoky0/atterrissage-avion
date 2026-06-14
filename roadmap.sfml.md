# Roadmap SFML — Mahatoky
> Profil : Java/Swing + C de base · Objectif : mini-jeu 2D C++

---

## Vue d'ensemble

| Phase | Thème | Durée estimée |
|---|---|---|
| 1 | Mise en place & fenêtre | 1–2 jours |
| 2 | Formes & dessin | 1–2 jours |
| 3 | Événements & input | 1–2 jours |
| 4 | Delta-time & mouvement | 1 jour |
| 5 | Textures & sprites | 2–3 jours |
| 6 | Drawable personnalisé | 2–3 jours |
| 7 | Mini-jeu complet | 3–5 jours |

---

## Phase 1 — Mise en place & fenêtre

### Ce qu'il faut apprendre
- Installer SFML (via apt, vcpkg ou téléchargement manuel)
- Configurer un projet avec CMake + lier les libs SFML
- Créer une `sf::RenderWindow`
- Comprendre la boucle `while (window.isOpen())`
- Les 3 phases obligatoires : **events → update → draw**
- `window.clear()` / `window.display()`

### Analogie Java
```
JFrame + setVisible(true)   →   sf::RenderWindow
repaint()                   →   window.clear() + window.display()
```

### Exercice
Ouvrir une fenêtre 800×600 noire qui se ferme quand on clique sur la croix.

---

## Phase 2 — Formes & dessin

### Ce qu'il faut apprendre
- `sf::RectangleShape` — rectangle
- `sf::CircleShape` — cercle (et polygone régulier via `setPointCount`)
- `sf::ConvexShape` — forme libre
- `setFillColor()`, `setOutlineColor()`, `setOutlineThickness()`
- `setPosition()`, `setSize()`, `setRadius()`
- Système de coordonnées (origine en haut à gauche, Y vers le bas)
- `window.draw(shape)`

### Analogie Java
```
g.setColor() + g.fillRect()   →   setFillColor() + window.draw()
g.drawOval()                  →   sf::CircleShape
```

### Exercice
Dessiner un fond coloré, un rectangle (sol), un cercle (balle) à des positions précises.

---

## Phase 3 — Événements & input

### Ce qu'il faut apprendre
- `sf::Event` et `window.pollEvent(e)` — boucle d'événements
- Types d'événements clés :
  - `sf::Event::Closed`
  - `sf::Event::KeyPressed` / `KeyReleased`
  - `sf::Event::MouseButtonPressed` / `MouseButtonReleased`
  - `sf::Event::MouseMoved`
- `sf::Keyboard::isKeyPressed()` — état continu (maintenu)
- `sf::Mouse::getPosition(window)` — position curseur
- `window.mapPixelToCoords()` — convertir pixels → coordonnées monde
- Hit-test : `shape.getGlobalBounds().contains(pos)`

### Différence critique
```
pollEvent → KeyPressed   : déclenché UNE FOIS à l'appui  (saut, tir)
isKeyPressed             : vrai tant que la touche est enfoncée (déplacement)
```

### Analogie Java
```
KeyListener.keyPressed()    →   sf::Event::KeyPressed
MouseListener.mouseClicked()→   MouseButtonReleased + contains()
```

### Exercice
Un carré qui se déplace avec les flèches (continu) + change de couleur au clic (événement ponctuel).

---

## Phase 4 — Delta-time & mouvement fluide

### Ce qu'il faut apprendre
- `sf::Clock` et `clock.restart().asSeconds()` — mesurer le temps
- Pourquoi multiplier par `dt` (frame-rate independence)
- Vitesse en **pixels/seconde** (pas pixels/frame)
- Gravité et vélocité : `velocity.y += gravite * dt`
- `sf::Vector2f` — vecteur 2D, opérations `+`, `*`, `/`

### Analogie Java
```
System.nanoTime() dans Swing Timer   →   sf::Clock
```

### Exercice
Le carré de la phase 3 qui se déplace à vitesse constante (200 px/s) peu importe le FPS. Ajouter une gravité simple.

---

## Phase 5 — Textures & sprites

### Ce qu'il faut apprendre
- `sf::Texture` — image chargée en mémoire GPU
- `sf::Sprite` — instance dessinable liée à une texture
- `texture.loadFromFile("image.png")`
- `sprite.setTexture(tex)`, `sprite.setPosition()`, `sprite.setScale()`
- **Spritesheet** : `sprite.setTextureRect(sf::IntRect(x, y, w, h))`
- Animation manuelle : changer `TextureRect` selon un timer
- `sf::Font` + `sf::Text` — afficher du texte à l'écran

### Analogie Java
```
ImageIcon / BufferedImage   →   sf::Texture
JLabel avec image           →   sf::Sprite
```

### Exercice
Un personnage avec spritesheet 4 frames qui anime la marche. Afficher un score en texte en haut à gauche.

---

## Phase 6 — Drawable personnalisé (architecture OOP)

### Ce qu'il faut apprendre
- Hériter de `sf::Drawable` — créer ses propres entités de jeu
- Surcharger `void draw(sf::RenderTarget&, sf::RenderStates) const override`
- Séparer logique (`update(float dt)`) et rendu (`draw(...)`)
- Hériter de `sf::Transformable` — gérer position/rotation/scale proprement
- `sf::FloatRect` et `getGlobalBounds()` — collision AABB
- Organiser une hiérarchie de classes : `EntiteJeu` → `Joueur`, `Ennemi`, `Bouton`

### Analogie Java
```
extends JComponent + paintComponent(g)   →   extends sf::Drawable + draw()
setBounds() / getX()                     →   extends sf::Transformable
```

### Exercice
Classe `Bouton` (Drawable) qui change d'apparence au survol et envoie un signal au clic. Classe `Joueur` avec sprite + hitbox.

---

## Phase 7 — Mini-jeu complet

### Ce qu'il faut assembler
- **GameState** : enum ou classe pour gérer Menu / Jeu / GameOver
- **Collision** : `getGlobalBounds().intersects()` entre entités
- **Score** : compteur + affichage `sf::Text`
- **Spawn** : créer des ennemis avec un timer
- **Scènes** : changer d'état selon les événements (appui bouton, mort du joueur)
- **Son** (bonus) : `sf::SoundBuffer` + `sf::Sound`

### Structure de fichiers recommandée
```
projet/
├── CMakeLists.txt
├── assets/
│   ├── player.png
│   └── font.ttf
└── src/
    ├── main.cpp
    ├── Game.hpp / Game.cpp
    ├── Joueur.hpp / Joueur.cpp
    └── Ennemi.hpp / Ennemi.cpp
```

### Projet final suggéré
**Dodge** : un vaisseau qui évite des astéroïdes qui tombent, avec score croissant et écran game over.

---

## Références utiles
- Documentation officielle : https://www.sfml-dev.org/documentation/
- Tutoriels SFML-fr : https://www.sfml-dev.org/tutorials/
- CMake + SFML : chercher `sfml cmake fetchcontent` pour la config moderne