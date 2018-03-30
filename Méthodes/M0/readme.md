## M0 : Ecart calibré Consigne – Vitesse

### Principe de la méthode
A chaque itération, la méthode M0 calcule la consigne de vitesse grâce à l'équation de calibration Vitesse/Consigne : 
```arduino
speed_target = throttle * etal_throttle_gain + etal_throttle_offset;
```
L'écart est ensuite calculé : 
```arduino
speed_error = speed_target - speed_measured;
```
Si l'écart est négatif, le vélo est plus rapide que la consigne -> l'induit est désactivé. (mode roue libre)
Sinon, une correction proportionnelle est appliquée selon échelle. 

### Calibration vitesse/consigne.
Objectif : obtenir la droite vitesse/consigne (et surtout son équation)

- **Mesure** : utiliser le programme log_trhrottle_speed.ino et faire un ou plusieurs cycles d’accélération / décélération a vide. 
Faire des cycles progressifs pour éviter le glissement du à l'inertie. 

- Etablir la courbe vitesse/consigne. Dégager l’équation. (Tableur ou IDE Scientifique)

- Le fichier `data_calib.csv` fournit un exemple de jeu de données de calibration. 