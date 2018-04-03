/*
  configuration_h

  This file is part of alternator-autocontrol.

  _author : @gtorreil

*/


// BRANCHEMENTS - WIRING

#define PIN_THROTTLE_HANDLE A0
#define PIN_CONTROLLER_SPEED A1

// MODE ROUE LIBRE - FREEWHEEL MODE

// En dessous de cette commande, roue libre : 
#define FREEWHEEL_MIN_THROTTLE 10 // 0 pour désactiver

/* PID Control loop

   Warning : PID control loop is not yet implemented
   and should not be used for standard use.
   Use linear_ramp instead.
*/

//#define PID_CONTROL

#ifdef PID_CONTROL
#define PID_KP 2.0 // Proportionnal
#define PID_KI 1.0 // Integral
#define PID_KD 1.0 // Derivate
#endif


/* Linear Ramp Control loop

   The basic, default control system.

   Uinduit(Err) = a * err
*/

#define LINEAR_CONTROL

#ifdef LINEAR_CONTROL
#define LINEAR_CONTROL_GAIN 2.0 // Use the calibration protocol to get the gain.
#endif



/* Application de la tension à l'induit

   Deux possibilités sont proposées.
   - Méthode direct-PWM :
     Pilotage à travers un transistor simple par PWM.
   - Méthode digitalPot : (PAS ENCORE DISPONIBLE)
     Pilotage à travers un potentiomètre numérique et un variateur du commerce.
*/

#define INDUIT_CONTROL_DIRECT_PWM

#ifdef INDUIT_CONTROL_DIRECT_PWM
#define PIN_INDUIT_CONTROL_DIRECT_PWM 3
#endif

//#define INDUIT_CONTROL_DIGITALPOT

#ifdef INDUIT_CONTROL_DIGITALPOT
//// DIGITAL POT CONFIG
#endif
