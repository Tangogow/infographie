

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include "glut.h"
#include "SOIL.h"

#include "Camera.h"
#include "Map.h"
#include "Robot.h"


// Objet Camera
Camera *cam = new Camera();
// Objet Sc�ne
Map *m = new Map();

// Objet robot
Robot *robot = new Robot();

//Variable position Robot
float posX = 0;
float posZ = 0;




/** GESTION FENETRE **/
void reshapeWindow(int w, int h)
{
    if (h == 0)
        h = 1;

    float ratio =  w * 1.0 / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, w, h);
    gluPerspective(45.0f, ratio, 0.1f, 348.0f);
    glMatrixMode(GL_MODELVIEW);
}

/** FONCTIONS DE GESTION CLAVIER **/
void KeyboardDown(unsigned char key, int xx, int yy)
{
    switch(key)
    {
    case 'e': // Unlock Camera
        cam->locked = (cam->locked)?0:1;
        break;
    case 'z':
        cam->deltaForward = 1;
        break;
    case 's':
        cam->deltaForward = -1;
        break;
    case 'd':
        cam->deltaStrafe = -1;
        break;
    case 'q':
        cam->deltaStrafe = 1;
        break;
    case 'c':
        robot->lowerPartUpFunc();
        glutPostRedisplay();
        break;
    case 'C':
        robot->lowerPartDownFunc();
        glutPostRedisplay();
        break;
    case 'x':
        robot->upperPartUpFunc();
        glutPostRedisplay();
        break;
    case 'X':
        robot->upperPartDownFunc();
        glutPostRedisplay();
        break;

    case 'l' :
        robot->posXUp();
        break;
    case 'k' :
        robot->posZUp();
        break;
    case 'j' :
        robot->posXDown();
        break;
    case 'i':
        robot->posZDown();

    }
}
void KeyboardUp(unsigned char key, int xx, int yy)
{
    switch(key)
    {
    case 'z':
    case 's':
        cam->deltaForward = 0;
        break;
    case 'q':
    case 'd':
        cam->deltaStrafe = 0;
        break;
    }
}
void SpecialDown(int key, int xx, int yy)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        cam->deltaForward = 1;
        break;
    case GLUT_KEY_DOWN:
        cam->deltaForward = -1;
        break;
    case GLUT_KEY_RIGHT:
        cam->deltaStrafe = -1;
        break;
    case GLUT_KEY_LEFT:
        cam->deltaStrafe = 1;
        break;
    }
}
void SpecialUp(int key, int xx, int yy)
{
    switch(key)
    {
    case GLUT_KEY_UP:
    case GLUT_KEY_DOWN:
        cam->deltaForward = 0;
        break;
    case GLUT_KEY_RIGHT:
    case GLUT_KEY_LEFT:
        cam->deltaStrafe = 0;
        break;
    }
}

/** FONCTIONS DE GESTION SOURIS (ORIENTATION CAMERA) **/
void mouseMove(int x, int y)
{
    // Rentres uniquement lors du clic
    cam->orienterCam(x, y);
}
void mouseButton(int button, int state, int x, int y)
{
    // Gestion camera en fonction du clic souris
    if (button == GLUT_LEFT_BUTTON)
    {
        // Relacher la camera
        if (state == GLUT_UP)
        {
            cam->releaseCam();
        }
        // Mise � jour origine du clic
        else
        {
            cam->grabCam(x, y);
        }
    }
}

/** GESTION DEPLACEMENT CAMERA **/
void computePos(int inutile)
{
    cam->updatePos();
    glutTimerFunc(10, computePos, 0);
}

/** AFFICHAGE **/
void renderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    // D�finition de la cam�ra
    gluLookAt(  cam->posx, cam->posy, cam->posz,
                cam->posx+cam->dirx, cam->posy+cam->diry,  cam->posz+cam->dirz,
                0.0f, 1.0f,  0.0f
                );

    m->DrawGround();
    m->DrawSkybox(cam);

    glPushMatrix();
        glRotatef(robot->angleRobot, 0.0f, 1.0f, 0.0f);
        glTranslatef(robot->posx, robot->posy, robot->posz);
        robot->Draw();
    glPopMatrix();

    glutSwapBuffers();
}

void LoadTextures()
{
    m->LoadTextures();
    robot->loadTextures();
}

int main(int argc, char **argv)
{
    /** CREATION FENETRE **/
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(320,320);
    glutCreateWindow("Impl�mentation :: Textures");

    /** FONCTIONS GLUT **/
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reshapeWindow);
    glutIdleFunc(renderScene);
    glutTimerFunc(10, computePos, 0);

    /** GESTION CLAVIER **/
    glutIgnoreKeyRepeat(0);
    glutKeyboardFunc(KeyboardDown);
    glutKeyboardUpFunc(KeyboardUp);
    glutSpecialFunc(SpecialDown);
    glutSpecialUpFunc(SpecialUp);

    /** GESTION SOURIS **/
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);

    /** INIT TEXTURES **/
    LoadTextures();

    /** INIT GL STATES **/
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    glutMainLoop();

    return (1);
}
