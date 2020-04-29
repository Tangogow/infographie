#ifndef ROBOT_H
#define ROBOT_H

#define ANCHOR_FROM_ORIGIN 0
#define ANCHOR_FROM_CENTER 1

#define FRONT 0
#define BACK 1
#define LEFT 2
#define RIGHT 3
#define TOP 4
#define BOT 5
#define ALL 6
#define SPHERE 7

#define TEXTURE_SCALE 1.0f

class Robot
{
  public:
    Robot();
    void Draw();
    void createBody();
    void createPawLeft(double, double);
    void createPawRight(double, double);
    void createHead();
    void calcNorm(float, float, float, float, float, float, float, float, float);
    void upperPartUpFunc();
    void lowerPartUpFunc();
    void upperPartDownFunc();
    void lowerPartDownFunc();
    void posXUp();
    void posZUp();
    void posXDown();
    void posZDown();
    void loadTextures();
    void setTexture(int, GLuint);

    float posx;
    float posy;
    float posz;

    float x;
    float y;
    float z;

    /*Variable pour alterner les jambes animés*/
    int whichPaws = 1; // 1 => AGDD 2=> ADDG

    /* angle patte Avant Gauche et Derrière Droite */
    double angleEpauleAGDD = -45.0;
    double angleGenouAGDD = 120;

    /* angle patte Avant Droite et Derrière Gauche */
    double angleEpauleADDG = -10.0;
    double angleGenouADDG = 60;

    /* angle orientation robot */
    float angleRobot = 0;

    /* Normal variable */
    float normX;
    float normY;
    float normZ;

    /* Angle lumière */
    float angleLight = 0.0;

    /* Membre pince */
    int upperPart = 0, lowerPart = 0;

    /* Tableau textures */
    GLuint ListeTextures[20];
    GLuint textures[6];
    char anchor[3];
  protected:
  private:
};

#endif // ROBOT_H
