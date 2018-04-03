/*
  M0_ino

  This file is part of alternator-autocontrol.

  _author : @gtorreil

*/

#include "configuration.h"


void setup() {
  #ifdef INDUIT_CONTROL_BRUSHED_ESC

}

void loop() {
  int consigne = analogRead(PIN_THROTTLE_HANDLE);  // Lecture de la poignée
  int vitesse  = analogRead(PIN_CONTROLLER_SPEED); // Lecture de la vitesse (sur contro)
  int err = consigne - vitesse;

  if (!induit_should_be_off(consigne)) {
    int Uinduit = calculateUinduitWithError(err);
    appliquer_tension_induit(Uinduit);
  } else {
    appliquer_tension_induit(0);
  }
}



// Core Functions

// Calcul de la tension de l'induit
int calculateUinduitWithError(int err) {
  // Méthode de controle linéaire
#ifdef LINEAR_CONTROL
  if (err <= 0) {
    // Plus vite que la consigne, coupure induit
    return 0;
  } else {
    // Plus lent que la consigne, correction.
    return clip_int(LINEAR_CONTROL_GAIN * err, 0, 1024) / 4; // Division par 4 -> mappage de 0 à 255
  }
#endif
}

// Appliquer la tension demandée à l'induit.
void appliquer_tension_induit(int Uinduit) {
  // Méthode PWM Direct
#ifdef INDUIT_CONTROL_DIRECT_PWM
  analogWrite(PIN_INDUIT_CONTROL_DIRECT_PWM, Uinduit);
#endif

  // Méthode DigitalPot
  /// NON FINALISE (j'attends encore mes digital pots..)
#ifdef INDUIT_CONTROL_DIGITALPOT
  Uinduit = map(Uinduit, 0, 255, 0, 100); // Passage en échelle 0~100 pour le pot
#endif

  // Méthode Brushed ESC
#ifdef INDUIT_CONTROL_BRUSHED_ESC
  Uinduit = map(Uinduit, 0, 255, 0, 180); // Passage en échelle 0~180 pour l'esc
  escInduit.write(Uinduit);
#endif
}

// Indique si l'induit devrait être coupé (sécu ou autre)
bool induit_should_be_off(int throttle) {
  /* Cette méthode passe en revue les différentes raisons de couper l'induit
     et renvoie un drapeau true seulement si aucune n'est vérifiée.
  */
  // Selon la commande (throttle) :
  if (throttle < FREEWHEEL_MIN_THROTTLE) {
    return true;
  }

  return false;
}

// Utilities - Utilitaires

// clip_int() : Restreindre a (entier) entre lBound et uBound
int clip_int(int a, int lBound, int uBound) {
  if (a < lBound) {
    return lBound;
  } else if (a > uBound) {
    return uBound;
  }
  return a;
}

