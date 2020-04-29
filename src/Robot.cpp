#include "Lib.h"

Robot::Robot()
{
  posx = 1.0f;
  posy = 2.0f;
  posz = 1.0f;

  //for (int i = 0; i < 6; i++)
    //textures[i] = 0;

  for (int j = 0; j < 3; j ++)
    anchor[j] = 0;
}

void Robot::Draw()
{
  glEnable(GL_TEXTURE_2D);

   /* body */
  glPushMatrix();
  createBody();
  glPopMatrix();

  /* Patte avant gauche */
  glPushMatrix();
  glTranslatef(1.0f, 0.3f, 1.0);
  createPawLeft(angleEpauleAGDD, angleGenouAGDD);
  glPopMatrix();

  /* Patte avant droite */
  glPushMatrix();
  glTranslatef(1.0f, 0.3f, -1.0f);
  createPawRight(angleEpauleADDG, angleGenouADDG);
  glPopMatrix();

  /* patte arrière gauche */
  glPushMatrix();
  glTranslatef(-1.7f, 0.3f, 1.0);
  createPawLeft(angleEpauleADDG, angleGenouADDG);
  glPopMatrix();

  /* patte arrière droite */
  glPushMatrix();
  glTranslatef(-1.7f, 0.3f, -1.0f);
  createPawRight(angleEpauleAGDD, angleGenouAGDD);
  glPopMatrix();

  /* head */
  glPushMatrix();
  glTranslatef(1.0f, 0.7, 0.0f);
  createHead();
  glPopMatrix();
}

/* Corp du robot */
void Robot::createBody()
{
  glPushMatrix();

  if (anchor[0])
    glTranslatef(-x/2, 0.0f, 0.0f);
  if (anchor[1])
    glTranslatef(0.0f, -y/2, 0.0f);
  if (anchor[2])
    glTranslatef(0.0f, 0.0f, -z/2);

  setTexture(TOP, ListeTextures[12]);
  glBindTexture(GL_TEXTURE_2D, textures[TOP]);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

  glRotatef(0, 0.0f, 1.0f, 0.0f);

  //glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
  //glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

  glBegin(GL_QUADS);

  // Front
  //calcNorm(-2.0f, -0.5f, 1.0f, 2.0f, -0.5f, 1.0f, -2.0f, 0.5f, 1.0f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(-2.0f, -0.5f);
  glVertex3f(-2.0f, -0.5f, 1.0f);
  glTexCoord2f(2.0f, -0.5f);
  glVertex3f(2.0f, -0.5f, 1.0f);
  glTexCoord2f(2.0f, 0.5f);
  glVertex3f(2.0f, 0.5f, 1.0f);
  glTexCoord2f(-2.0f, 0.5f);
  glVertex3f(-2.0f, 0.5f, 1.0f);

  // Right
  //calcNorm(2.0f, -0.5f, -1.0f, 2.0f, 0.5f, -1.0f, 2.0f, -0.5f, 1.0f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(-0.5f, 2.0f);
  glVertex3f(2.0f, -0.5f, -1.0f);
  glTexCoord2f(0.5f, 2.0f);
  glVertex3f(2.0f, 0.5f, -1.0f);
  glTexCoord2f(2.0f, 0.5f);
  glVertex3f(2.0f, 0.5f, 1.0f);
  glTexCoord2f(2.0f, -0.5f);
  glVertex3f(2.0f, -0.5f, 1.0f);

  // Back
  //calcNorm(-2.0f, -0.5f, -1.0f, -2.0f, 0.5f, -1.0f, 2.0f, -0.5f, -1.0f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(-2.0f, -0.5f);
  glVertex3f(-2.0f, -0.5f, -1.0f);
  glTexCoord2f(-2.0f, 0.5f);
  glVertex3f(-2.0f, 0.5f, -1.0f);
  glTexCoord2f(2.0f, 0.5f);
  glVertex3f(2.0f, 0.5f, -1.0f);
  glTexCoord2f(2.0f, -0.5f);
  glVertex3f(2.0f, -0.5f, -1.0f);

  // Left
  //calcNorm(-2.0f, -0.5f, -1.0f, -2.0f, -0.5f, 1.0f, -2.0f, 0.5f, -1.0f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(-0.5f, -2.0f);
  glVertex3f(-2.0f, -0.5f, -1.0f);
  glTexCoord2f(-2.0f, -0.5f);
  glVertex3f(-2.0f, -0.5f, 1.0f);
  glTexCoord2f(0.5f, -2.0f);
  glVertex3f(-2.0f, 0.5f, 1.0f);
  glTexCoord2f(-2.0f, 0.5f);
  glVertex3f(-2.0f, 0.5f, -1.0f);

  // Top
  //calcNorm(2.0f, 0.5f, 1.0f,-2.0f, 0.5f, 1.0f, 2.0f, 0.5f, -1.0f );
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(2.0f, 0.5f);
  glVertex3f(2.0f, 0.5f, 1.0f);
  glTexCoord2f(0.5f, -2.0f);
  glVertex3f(-2.0f, 0.5f, 1.0f);
  glTexCoord2f(-2.0f, 0.5f);
  glVertex3f(-2.0f, 0.5f, -1.0f);
  glTexCoord2f(0.5f, 2.0f);
  glVertex3f(2.0f, 0.5f, -1.0f);

  // Bottom
  //calcNorm(2.0f, -0.5f, 1.0f, -2.0f, -0.5f, 1.0f, 2.0f, -0.5f, -1.0f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(2.0f, -0.5f);
  glVertex3f(2.0f, -0.5f, 1.0f);
  glTexCoord2f(-2.0f, -0.5f);
  glVertex3f(-2.0f, -0.5f, 1.0f);
  glTexCoord2f(-0.5f, -2.0f);
  glVertex3f(-2.0f, -0.5f, -1.0f);
  glTexCoord2f(-0.5f, 2.0f);
  glVertex3f(2.0f, -0.5f, -1.0f);

  glEnd();
  glPopMatrix();
  // Fin du corps
}

/* Pate gauche */
void Robot::createPawLeft(double angleEpaule, double angleGenou)
{
  glBindTexture(GL_TEXTURE_2D, ListeTextures[11]);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
  glPushMatrix();

  // rotule epaule
  glPushMatrix();
  glTranslatef(0.2f, -0.3f, 0.0f);
  glScalef(1.3, 1.3, 1.3);
  GLUquadric *sph;
  sph = gluNewQuadric();
  gluQuadricTexture(sph, ListeTextures[11]);
  gluSphere(sph,0.2,18,18);

  // cuisse
  glRotatef(angleEpaule, 0.0, 0.0, 1.0);
  glTranslatef(-0.2f, 0.3f, 0.1f);
  glBegin(GL_QUADS);

  // Back
  calcNorm(0.0f, 0.0f, 0.0f, 0.0f, -1.5f, 0.0f, 0.4f, 0.0f, 0.0f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glTexCoord2f(0.0f, -1.5f);
  glVertex3f(0.0f, -1.5f, 0.0f);
  glTexCoord2f(0.4f, -1.5f);
  glVertex3f(0.4f, -1.5f, 0.0f);
  glTexCoord2f(0.4f, 0.0f);
  glVertex3f(0.4f, 0.0f, 0.0f);

  // Right
  calcNorm(0.4f, 0.0f, 0.4f, 0.4f, -1.5f, 0.4f, 0.4f, 0.0f, 0.0f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(0.0f, 0.4f);
  glVertex3f(0.4f, 0.0f, 0.4f);
  glTexCoord2f(-1.5f, 0.4f);
  glVertex3f(0.4f, -1.5f, 0.4f);
  glTexCoord2f(0.4f, -1.5f);
  glVertex3f(0.4f, -1.5f, 0.0f);
  glTexCoord2f(0.4f, 0.0f);
  glVertex3f(0.4f, 0.0f, 0.0f);

  // Front
  calcNorm(0.0f, 0.0f, 0.4f, 0.0f, -1.5f, 0.4f, 0.4f, 0.0f, 0.4f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.4f);
  glTexCoord2f(0.0f, -1.5f);
  glVertex3f(0.0f, -1.5f, 0.4f);
  glTexCoord2f(0.4f, -1.5f);
  glVertex3f(0.4f, -1.5f, 0.4f);
  glTexCoord2f(0.4f, 0.0f);
  glVertex3f(0.4f, 0.0f, 0.4f);

  // Left
  calcNorm(0.0f, 0.0f, 0.0f, 0.0f, -1.5f, 0.0f, 0.0f, 0.0f, 0.4f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glTexCoord2f(0.0f, -1.5f);
  glVertex3f(0.0f, -1.5f, 0.0f);
  glTexCoord2f(-1.5f, 0.0f);
  glVertex3f(0.0f, -1.5f, 0.4f);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.4f);

  // top
  calcNorm(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.4f, 0.4f, 0.0f, 0.0f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.4f);
  glTexCoord2f(0.4f, 0.0f);
  glVertex3f(0.4f, 0.0f, 0.4f);
  glTexCoord2f(0.0f, 0.4f);
  glVertex3f(0.4f, 0.0f, 0.0f);

  // Bottom
  calcNorm(0.0f, -1.5f, 0.0f, 0.0f, -1.5f, 0.4f, 0.4f, -1.5f, 0.0f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(0.0f, -1.5f);
  glVertex3f(0.0f, -1.5f, 0.0f);
  glTexCoord2f(0.0f, -1.5f);
  glVertex3f(0.0f, -1.5f, 0.4f);
  glTexCoord2f(0.4f, -1.5f);
  glVertex3f(0.4f, -1.5f, 0.4f);
  glTexCoord2f(0.4f, -1.5f);
  glVertex3f(0.4f, -1.5f, 0.0f);

  glEnd();

  // rotule
  glTranslatef(0.2f, -1.5f, 0.2f);
  glScalef(1.3, 1.3, 1.3);
  GLUquadric *sph2;
  sph2 = gluNewQuadric();
  gluQuadricTexture(sph2, ListeTextures[11]);
  gluSphere(sph2,0.2,18,18);

  // tibia
  glTranslatef(0.0f, 0.0f, 0.0f);
  glRotatef(angleGenou, 0.0, 0.0, 1.0);

  glRotatef(90, 1.0, 0.0, 0.0);
  GLUquadric* qobj;
  qobj = gluNewQuadric();
  gluQuadricTexture(qobj, ListeTextures[11]);
  gluCylinder(qobj, 0.18, 0.17, 1.0, 32, 32);

  // pied sphère
  glTranslatef(0.0f, 0.0f, 1.0f);
  glScalef(1.0, 1.0, 1.0);
  GLUquadric *sph3;
  sph3 = gluNewQuadric();
  gluQuadricTexture(sph3, ListeTextures[11]);
  gluSphere(sph3,0.2,18,18);

  glPopMatrix();
}

/* Patte droite */
void Robot::createPawRight(double angleEpaule, double angleGenou)
{
  glBindTexture(GL_TEXTURE_2D, ListeTextures[11]);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

  glPushMatrix();


  // Rotule epaule
  glPushMatrix();
  glTranslatef(0.2f, -0.3f, 0.0f);
  glScalef(1.3, 1.3, 1.3);
  GLUquadric *sph;
  sph = gluNewQuadric();
  gluQuadricTexture(sph, ListeTextures[11]);
  gluSphere(sph,0.2,18,18);

  // Cuisse
  glRotatef(angleEpaule, 0.0, 0.0, 1.0);
  glTranslatef(-0.2f, 0.3f, -0.5f);
  glBegin(GL_QUADS);

  // Back
  glBindTexture(GL_TEXTURE_2D, textures[FRONT]);
  calcNorm(0.0f, 0.0f, 0.0f, 0.0f, -1.5f, 0.0f, 0.4f, 0.0f, 0.0f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glTexCoord2f(0.0f, -1.5f);
  glVertex3f(0.0f, -1.5f, 0.0f);
  glTexCoord2f(0.4f, -1.5f);
  glVertex3f(0.4f, -1.5f, 0.0f);
  glTexCoord2f(0.4f, 0.0f);
  glVertex3f(0.4f, 0.0f, 0.0f);

  // Right
  calcNorm(0.4f, 0.0f, 0.4f, 0.4f, -1.5f, 0.4f, 0.4f, 0.0f, 0.0f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(0.0f, 0.4f);
  glVertex3f(0.4f, 0.0f, 0.4f);
  glTexCoord2f(-1.5f, 0.4f);
  glVertex3f(0.4f, -1.5f, 0.4f);
  glTexCoord2f(0.4f, -1.5f);
  glVertex3f(0.4f, -1.5f, 0.0f);
  glTexCoord2f(0.4f, 0.0f);
  glVertex3f(0.4f, 0.0f, 0.0f);

  // Front
  calcNorm(0.0f, 0.0f, 0.4f, 0.0f, -1.5f, 0.4f, 0.4f, 0.0f, 0.4f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.4f);
  glTexCoord2f(0.0f, -1.5f);
  glVertex3f(0.0f, -1.5f, 0.4f);
  glTexCoord2f(0.4f, -1.5f);
  glVertex3f(0.4f, -1.5f, 0.4f);
  glTexCoord2f(0.4f, 0.0f);
  glVertex3f(0.4f, 0.0f, 0.4f);

  // Left
  calcNorm(0.0f, 0.0f, 0.0f, 0.0f, -1.5f, 0.0f, 0.0f, 0.0f, 0.4f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glTexCoord2f(0.0f, -1.5f);
  glVertex3f(0.0f, -1.5f, 0.0f);
  glTexCoord2f(-1.5f, 0.0f);
  glVertex3f(0.0f, -1.5f, 0.4f);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.4f);

  // Top
  //calcNorm(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.4f, 0.4f, 0.0f, 0.0f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.4f);
  glTexCoord2f(0.4f, 0.0f);
  glVertex3f(0.4f, 0.0f, 0.4f);
  glTexCoord2f(0.0f, 0.4f);
  glVertex3f(0.4f, 0.0f, 0.0f);

  // Bottom
  //calcNorm(0.0f, -1.5f, 0.0f, 0.0f, -1.5f, 0.4f, 0.4f, -1.5f, 0.0f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(0.0f, -1.5f);
  glVertex3f(0.0f, -1.5f, 0.0f);
  glTexCoord2f(0.0f, -1.5f);
  glVertex3f(0.0f, -1.5f, 0.4f);
  glTexCoord2f(0.4f, -1.5f);
  glVertex3f(0.4f, -1.5f, 0.4f);
  glTexCoord2f(0.4f, -1.5f);
  glVertex3f(0.4f, -1.5f, 0.0f);

  glEnd();

  // Rotule
  glTranslatef(0.2f, -1.5f, 0.2f);
  glScalef(1.3, 1.3, 1.3);
  GLUquadric *sph2;
  sph2 = gluNewQuadric();
  gluQuadricTexture(sph2, ListeTextures[11]);
  gluSphere(sph2,0.2,18,18);

  // Tibia
  glTranslatef(0.0f, 0.0f, 0.0f);
  glRotatef(angleGenou, 0.0, 0.0, 1.0);
  glRotatef(90, 1.0, 0.0, 0.0);
  GLUquadric* qobj;
  qobj = gluNewQuadric();
  gluQuadricTexture(qobj, ListeTextures[11]);
  gluCylinder(qobj, 0.18, 0.17, 1.0, 32, 32);

  // Pied sphère
  glTranslatef(0.0f, 0.0f, 1.0f);
  glScalef(1.0, 1.0, 1.0);
  GLUquadric *sph3;
  sph3 = gluNewQuadric();
  gluQuadricTexture(sph3, ListeTextures[11]);
  gluSphere(sph3,0.2,18,18);

  glPopMatrix();
}

/* Tête du robot */
void Robot::createHead()
{
  glBindTexture(GL_TEXTURE_2D, ListeTextures[10]);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
  glPushMatrix();

  glTranslatef(0.0f, 0, 0.0f);
  glScalef (1.0, 1.0, 1.0);
  GLUquadric *sph;
  sph = gluNewQuadric();
  gluQuadricTexture(sph, ListeTextures[11]);
  gluSphere(sph,0.4,18,18);
  glTranslatef(0.0f, 0, -0.45);
  glRotatef((GLfloat)lowerPart, 0.0, 0.0, 1.0);
  glTranslatef(0.7f, 0, 0);

  glBegin(GL_QUADS);

  // Front
  calcNorm(-0.7f, -0.2f, 0.7f, 2.5f, -0.2f, 0.7f, -0.7f, 0.2f, 0.7f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(-0.7f, -0.2f);
  glVertex3f(-0.7f, -0.2f, 0.7f); // bottom left
  glTexCoord2f(-0.2f, 2.5f);
  glVertex3f(2.5f, -0.2f, 0.7f); // bottom right
  glTexCoord2f(2.5f, 0.2f);
  glVertex3f(2.5f, 0.2f, 0.7f); //top right
  glTexCoord2f(-0.7f, 0.2f);
  glVertex3f(-0.7f, 0.2f, 0.7f); //top left

  // Right
  calcNorm(2.5f, -0.2f, 0.7f, 2.5f, -0.2f, 0.2f, 2.5f, 0.2f, 0.7f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(-0.2f, 2.5f);
  glVertex3f(2.5f, -0.2f, 0.7f);
  glTexCoord2f(-0.2f, 2.5f);
  glVertex3f(2.5f, -0.2f, 0.2f);
  glTexCoord2f(2.5f, 0.2f);
  glVertex3f(2.5f, 0.2f, 0.2f);
  glTexCoord2f(2.5f, 0.2f);
  glVertex3f(2.5f, 0.2f, 0.7f);

  // Back
  calcNorm(2.5f, -0.2f, 0.2f, -0.7f, -0.2f, 0.2f, 2.5f, 0.2f, 0.2f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(2.5f, -0.2f);
  glVertex3f(2.5f, -0.2f, 0.2f);
  glTexCoord2f(-0.7f, -0.2f);
  glVertex3f(-0.7f, -0.2f, 0.2f);
  glTexCoord2f(-0.7f, 0.2f);
  glVertex3f(-0.7f, 0.2f, 0.2f);
  glTexCoord2f(2.5f, 0.2f);
  glVertex3f(2.5f, 0.2f, 0.2f);

  // Left
  calcNorm(-0.7f, -0.2f, 0.7f, -0.7f, -0.2f, 0.2f, -0.7f, 0.2f, 0.7f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(-0.7f, -0.2f);
  glVertex3f(-0.7f, -0.2f, 0.7f);
  glTexCoord2f(-0.7f, -0.2f);
  glVertex3f(-0.7f, -0.2f, 0.2f);
  glTexCoord2f(-0.7f, 0.2f);
  glVertex3f(-0.7f, 0.2f, 0.2f);
  glTexCoord2f(-0.7f, 0.2f);
  glVertex3f(-0.7f, 0.2f, 0.7f);

  // Top
  calcNorm(-0.7f, 0.2f, 0.7f, 2.5f, 0.2f, 0.7f, -0.7f, 0.2f, 0.2f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(-0.7f, 0.2f);
  glVertex3f(-0.7f, 0.2f, 0.7f);
  glTexCoord2f(0.2f, 2.5f);
  glVertex3f(2.5f, 0.2f, 0.7f);
  glTexCoord2f(2.5f, 0.2f);
  glVertex3f(2.5f, 0.2f, 0.2f);
  glTexCoord2f(0.2f, -0.7f);
  glVertex3f(-0.7f, 0.2f, 0.2f);

  // Bottom
  calcNorm(-0.7f, -0.2f, 0.7f, 2.5f, -0.2f, 0.7f, -0.7f, -0.2f, 0.2f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(-0.7f, -0.2f);
  glVertex3f(-0.7f, -0.2f, 0.7f);
  glTexCoord2f(2.5f, -0.2f);
  glVertex3f(2.5f, -0.2f, 0.7f);
  glTexCoord2f(-0.2f, 2.5f);
  glVertex3f(2.5f, -0.2f, 0.2f);
  glTexCoord2f(-0.2f, -0.7f);
  glVertex3f(-0.7f, -0.2f, 0.2f);

  glEnd();

  // Sphère lien bras
  glTranslatef(2.5f, 0, 0.45f);
  glScalef (1.0, 1.0, 1.0);
  GLUquadric *sph2;
  sph2 = gluNewQuadric();
  gluQuadricTexture(sph2, ListeTextures[11]);
  gluSphere(sph2,0.4,18,18);
  glTranslatef(-2.5f, 0, -0.45f);


  // Upper part
  glTranslatef(2.4f, 0, 0);
  glRotatef((GLfloat)upperPart, 0.0, 0.0, 1.0);
  glTranslatef(1.0f, 0, 0);

  glBindTexture(GL_TEXTURE_2D, ListeTextures[13]);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

  glBegin(GL_QUADS);

  // Front
  calcNorm(-0.7f, -0.2f, 0.7f, 2.5f, -0.2f, 0.7f, -0.7f, 0.2f, 0.7f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(-0.2f, 0.7f);
  glVertex3f(-0.7f, -0.2f, 0.7f); // bottom left
  glTexCoord2f(0.2f, 2.5f);
  glVertex3f(2.5f, -0.2f, 0.7f); // bottom right
  glTexCoord2f(2.5f, 0.2f);
  glVertex3f(2.5f, 0.2f, 0.7f); //top right
  glTexCoord2f(-0.7f, 0.2f);
  glVertex3f(-0.7f, 0.2f, 0.7f); //top left

  // Right
  calcNorm(2.5f, -0.2f, 0.7f, 2.5f, -0.2f, 0.2f, 2.5f, 0.2f, 0.7f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(2.5f, -0.2f);
  glVertex3f(2.5f, -0.2f, 0.7f);
  glTexCoord2f(2.5f, -0.2f);
  glVertex3f(2.5f, -0.2f, 0.2f);
  glTexCoord2f(2.5f, 0.2f);
  glVertex3f(2.5f, 0.2f, 0.2f);
  glTexCoord2f(2.5f, 0.2f);
  glVertex3f(2.5f, 0.2f, 0.7f);

  // Back
  calcNorm(2.5f, -0.2f, 0.2f, -0.7f, -0.2f, 0.2f, 2.5f, 0.2f, 0.2f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(2.5f, -0.2f);
  glVertex3f(2.5f, -0.2f, 0.2f);
  glTexCoord2f(-0.7f, -0.2f);
  glVertex3f(-0.7f, -0.2f, 0.2f);
  glTexCoord2f(-0.7f, 0.2f);
  glVertex3f(-0.7f, 0.2f, 0.2f);
  glTexCoord2f(2.5f, 0.2f);
  glVertex3f(2.5f, 0.2f, 0.2f);

  // Left
  calcNorm(-0.7f, -0.2f, 0.7f, -0.7f, -0.2f, 0.2f, -0.7f, 0.2f, 0.7f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(-0.7f, -0.2f);
  glVertex3f(-0.7f, -0.2f, 0.7f);
  glTexCoord2f(-0.7f, -0.2f);
  glVertex3f(-0.7f, -0.2f, 0.2f);
  glTexCoord2f(-0.7f, 0.2f);
  glVertex3f(-0.7f, 0.2f, 0.2f);
  glTexCoord2f(-0.7f, 0.2f);
  glVertex3f(-0.7f, 0.2f, 0.7f);

  // Top
  calcNorm(-0.7f, 0.2f, 0.7f, 2.5f, 0.2f, 0.7f, -0.7f, 0.2f, 0.2f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(-0.7f, 0.2f);
  glVertex3f(-0.7f, 0.2f, 0.7f);
  glTexCoord2f(0.2f, 2.5f);
  glVertex3f(2.5f, 0.2f, 0.7f);
  glTexCoord2f(2.5f, 0.2f);
  glVertex3f(2.5f, 0.2f, 0.2f);
  glTexCoord2f(0.2f, -0.7f);
  glVertex3f(-0.7f, 0.2f, 0.2f);

  // Bottom
  calcNorm(-0.7f, -0.2f, 0.7f, 2.5f, -0.2f, 0.7f, -0.7f, -0.2f, 0.2f);
  glNormal3f(normX, normY, normZ);
  glTexCoord2f(-0.7f, -0.2f);
  glVertex3f(-0.7f, -0.2f, 0.7f);
  glTexCoord2f(2.5f, -0.2f);
  glVertex3f(2.5f, -0.2f, 0.7f);
  glTexCoord2f(-0.2f, 2.5f);
  glVertex3f(2.5f, -0.2f, 0.2f);
  glTexCoord2f(-0.2f, -0.7f);
  glVertex3f(-0.7f, -0.2f, 0.2f);

  glEnd();

  // Sphère lien pince
  glTranslatef(2.5f, 0, 0.45f);
  glScalef (0.3, 0.3, 0.3);
  GLUquadric *sph3;
  sph3 = gluNewQuadric();
  gluQuadricTexture(sph3, ListeTextures[11]);
  gluSphere(sph3,1.2,18,18);
  glTranslatef(-2.5f, 0, -0.45f);

  glPopMatrix();
}

/* Calcul normal function à utiliser uniquement avec glQuads */
void Robot::calcNorm(float xA, float yA, float zA, float xB, float yB, float zB, float xC, float yC, float zC)
{
  /* Instruction */
  /* Le glVertex relie les point dans l'ordre donnée, pour avoir deux bon vecteurs,*/
  /*il faut donc prendre les point 1,2 et 4 (et non 3 attention)*/
  /* il faut d'abord faire cette fonction avant de dessiner donc être sur des coordonées */
  /* 1 --> calcNorm(......)
   * 2 --> glNormal(normX, normY, normZ)
   * 3 --> tracer avec glVertex */
  /* First step */
  /* Calcul coordonnée vecteur */
  /* u = (xB−xA;yB−yA;zB−zA) = (uX, uY, uZ)*/
  /* v = (xC−xA;yC−yA;zC−zA) = (vX, vY, vZ)*/
  float uX = xB - xA;
  float uY = yB - yA;
  float uZ = zB - zA;

  float vX = xC - xA;
  float vY = yC - yA;
  float vZ = zC - zA;

  /* Second Step */
  /* calcul w */
  /* w = ((uY*vZ - uZ*vY), (uZ*vX - uX*vZ), (uX*vY - uY*vX))*/
  /* mettre coordonée dans 3 variable global */
  normX = ((uY * vZ) - (uZ * vY));
  normY = ((uZ * vX) - (uX * vZ));
  normZ = ((uX * vY) - (uY * vX));
}

/* Mouvement haut parties supérieures */
void Robot::upperPartUpFunc()
{
  if (upperPart > -130 && upperPart < 160)
    upperPart = (upperPart + 5) % 360;
  else
    upperPart += 0;
  printf("+ upperPart :%d\n", upperPart);
  //glutPostRedisplay();
}

/* Mouvement haut parties inférieure */
void Robot::lowerPartUpFunc()
{
  if (lowerPart >= -5 && lowerPart < 170)
    lowerPart = (lowerPart + 5) % 360;
  printf("+ lowerPart :%d\n", lowerPart);
  //glutPostRedisplay();
}

/* Mouvement bas parties supérieures */
void Robot::upperPartDownFunc()
{
  if (upperPart > -125 && upperPart <= 165)
    upperPart = (upperPart - 5) % 360;
  else
    upperPart += 0;
  printf("- upperPart :%d\n", upperPart);
  //glutPostRedisplay();
}

/* Mouvement bas parties inférieures */
void Robot::lowerPartDownFunc()
{
 if (lowerPart >= 0 && lowerPart <= 175)
    lowerPart = (lowerPart - 5) % 360;
  printf("- lowerPart :%d\n", upperPart);
  //glutPostRedisplay();
}

void Robot::posXUp()
{
  if (whichPaws == 1)
  {
    printf("angleEpauleAGDD = %f\n", angleEpauleAGDD);
    printf("angleGenouAGDD = %f\n", angleGenouAGDD);
    angleEpauleAGDD += 0.5;
    angleEpauleADDG -= 0.5;
    if (angleEpauleAGDD > -30)
    {
      angleGenouAGDD -= 2.0;
      angleGenouADDG += 2.0;
      if (angleEpauleAGDD > -15)
      {
        printf("%f", angleEpauleAGDD);
        angleGenouAGDD -= 0.5;
        angleGenouADDG += 0.5;
        whichPaws = 2;
      }
    }
  }
  else
  {
    printf("angleEpauleAGDD = %f\n", angleEpauleAGDD);
    printf("angleGenouAGDD = %f\n", angleGenouAGDD);
    angleEpauleAGDD -= 0.5;
    angleEpauleADDG += 0.5;
    if (angleEpauleAGDD <= -45 && angleEpauleAGDD >= -60){
      angleGenouAGDD += 2.0;
      angleGenouADDG -= 2.0;
    }
    if (angleEpauleAGDD <= -60){
      whichPaws = 1;
    }
  }
  posx += 0.01f;
}

void Robot::posZUp(){
  angleRobot += 0.1f;
}

void Robot::posXDown(){
  posx -= 0.01f;
}

void Robot::posZDown(){
  angleRobot -= 0.1f;
}

void Robot::loadTextures(){
  // Textures utilisables
  ListeTextures[0] = SOIL_load_OGL_texture("img/cliff.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  ListeTextures[1] = SOIL_load_OGL_texture("img/cobble.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  ListeTextures[2] = SOIL_load_OGL_texture("img/darkgrass.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  ListeTextures[3] = SOIL_load_OGL_texture("img/darkwoodplanks.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  ListeTextures[4] = SOIL_load_OGL_texture("img/darkwoodtiles.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  ListeTextures[5] = SOIL_load_OGL_texture("img/deadgrass.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  ListeTextures[6] = SOIL_load_OGL_texture("img/floorbrick.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  ListeTextures[7] = SOIL_load_OGL_texture("img/graybrick.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  ListeTextures[8] = SOIL_load_OGL_texture("img/graybricktiles.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  ListeTextures[9] = SOIL_load_OGL_texture("img/grass.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  ListeTextures[10] = SOIL_load_OGL_texture("img/metal1.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  ListeTextures[11] = SOIL_load_OGL_texture("img/metal2.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  ListeTextures[12] = SOIL_load_OGL_texture("img/metal3.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  ListeTextures[13] = SOIL_load_OGL_texture("img/metal4.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  ListeTextures[14] = SOIL_load_OGL_texture("img/mossbricktiles.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  ListeTextures[15] = SOIL_load_OGL_texture("img/pavement.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  ListeTextures[16] = SOIL_load_OGL_texture("img/pebbles.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  ListeTextures[17] = SOIL_load_OGL_texture("img/redbrick.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  ListeTextures[18] = SOIL_load_OGL_texture("img/metalgate.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  ListeTextures[19] = SOIL_load_OGL_texture("img/betonurban.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
  ListeTextures[19] = SOIL_load_OGL_texture("img/terre.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
}

void Robot::setTexture(int face, GLuint texture)
{
  textures[face] = texture;
}
