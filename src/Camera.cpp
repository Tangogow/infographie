#include "Lib.h"

const float m_pi = 3.14; // pi pour le calcul d'angle

Camera::Camera()
{
  deltaForward = 0; // movement x
  deltaStrafe = 0; // movement y

  /* position initiale cam */
  posx = 0.0f; //y
  posy = 1.5f; //z
  posz = 15.0f; //x

  /* direction de la cam */
  dirx = 0.0f;
  diry = 0.0f;
  dirz = -1.0f;

  /* init de l'angle */
  angleh = 0.0f;
  anglev = 0.0f;

  /* référence de l'origine */
  xOrigin = -1;
  yOrigin = -1;

  /* Angle d'orientation si locked = 0 */
  deltaAnglex = 0.0f;
  deltaAngley = 0.0f;

  locked = 1; /* verouillage de la cam */
}

/* Mise à jour de la position de la cam */
void Camera::updatePos()
{
  if (deltaForward || deltaStrafe)
  {
    if (locked) /* si cam locké */
    {
      posx += deltaForward * (dirx/cos(anglev + deltaAngley)) * MOVE_SPEED;
      posy = 1.5f;
      posz += deltaForward * (dirz/cos(anglev + deltaAngley)) * MOVE_SPEED;
      posx += deltaStrafe * (dirz/cos(anglev + deltaAngley)) * MOVE_SPEED;
      posz -= deltaStrafe * (dirx/cos(anglev + deltaAngley)) * MOVE_SPEED;
    }
    else /* cam libre */
    {
      posx += deltaForward * dirx * MOVE_SPEED;
      posy += deltaForward * diry * MOVE_SPEED;
      posz += deltaForward * dirz * MOVE_SPEED;
      posx += deltaStrafe * dirz * MOVE_SPEED;
      posz -= deltaStrafe * dirx * MOVE_SPEED;
    }
  }
}

void Camera::orienterCam(int x, int y)
{
  if (xOrigin >= 0) // si l'orientation bouge
  {
    // Calcul de l'angle horizontal
    deltaAnglex = (x - xOrigin) * SENSIBILITY;
    // Correction de l'angle ]-Pi; Pi[
    while (deltaAnglex + angleh > m_pi)
      deltaAnglex -= m_pi * 2;
    while (deltaAnglex + angleh < -m_pi)
      deltaAnglex += m_pi * 2;

    // Calcul de l'angle vertical
    deltaAngley = (y - yOrigin) * SENSIBILITY;
    // Limitation de l'angle (limite haute)
    if (deltaAngley + anglev > m_pi)
      deltaAngley = m_pi - anglev - 0.01f;
    // Limitation de l'angle (limite basse)
    if (deltaAngley + anglev < -m_pi)
      deltaAngley = -m_pi - anglev + 0.01f;

    // Mis à jour de la caméra
    dirx = sin(angleh + deltaAnglex)*cos(anglev + deltaAngley);
    diry = -sin(anglev + deltaAngley);
    dirz = -cos(angleh + deltaAnglex)*cos(anglev + deltaAngley);
  }
}

/* Relachement de la cam après le dévérouillage */
void Camera::releaseCam()
{
  angleh += deltaAnglex;
  anglev += deltaAngley;

  yOrigin = -1;
  xOrigin = -1;
}

/* Récupération de la cam sur l'axe x y */
void Camera::grabCam(int x, int y)
{
  xOrigin = x;
  yOrigin = y;
}
