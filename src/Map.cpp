#include "Lib.h"

#define GL_CLAMP_TO_EDGE 0x812F
#define SKY_DISTANCE 200.0f

Map::Map()
{

}

void Map::LoadTextures()
{
  // Skybox
  Skybox[0] = SOIL_load_OGL_texture("img/skybox1.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
  Skybox[1] = SOIL_load_OGL_texture("img/skybox2.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
  Skybox[2] = SOIL_load_OGL_texture("img/skybox3.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
  Skybox[3] = SOIL_load_OGL_texture("img/skybox4.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
  Skybox[4] = SOIL_load_OGL_texture("img/skybox5.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
  Skybox[5] = SOIL_load_OGL_texture("img/skybox6.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
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


void Map::DrawGround()
{
  glEnable(GL_TEXTURE_2D);
  glColor3f(1.0f, 1.0f, 1.0f);
  glBindTexture(GL_TEXTURE_2D, ListeTextures[9]);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

  glBegin(GL_QUADS);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(-50.0f, 0.0f, -50.0f);
  glTexCoord2f(0.0f, 50.0f);
  glVertex3f(-50.0f, 0.0f,  50.0f);
  glTexCoord2f(50.0f, 50.0f);
  glVertex3f(50.0f, 0.0f, 50.0f);
  glTexCoord2f(50.0f, 0.0f);
  glVertex3f(50.0f, 0.0f, -50.0f);
  glEnd();
  glTranslatef(0.0f, 1.0f, 0.0f);
}

void Map::DrawSkybox(Camera *cam)
{
  glDisable(GL_LIGHTING);
  glEnable(GL_TEXTURE_2D);

  glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

  // Face
  glBindTexture(GL_TEXTURE_2D, Skybox[1]);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

  glBegin(GL_QUADS);
  glTexCoord2f(0, 0);
  glVertex3f( SKY_DISTANCE + cam->posx, -SKY_DISTANCE + cam->posy, -SKY_DISTANCE + cam->posz);
  glTexCoord2f(1, 0);
  glVertex3f(-SKY_DISTANCE + cam->posx, -SKY_DISTANCE + cam->posy, -SKY_DISTANCE + cam->posz);
  glTexCoord2f(1, 1);
  glVertex3f(-SKY_DISTANCE + cam->posx, SKY_DISTANCE + cam->posy, -SKY_DISTANCE + cam->posz);
  glTexCoord2f(0, 1);
  glVertex3f( SKY_DISTANCE + cam->posx, SKY_DISTANCE + cam->posy, -SKY_DISTANCE + cam->posz);
  glEnd();

  // Render the left quad
  glBindTexture(GL_TEXTURE_2D, Skybox[0]);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

  glBegin(GL_QUADS);
  glTexCoord2f(0, 0);
  glVertex3f( SKY_DISTANCE + cam->posx, -SKY_DISTANCE + cam->posy, SKY_DISTANCE + cam->posz);
  glTexCoord2f(1, 0);
  glVertex3f( SKY_DISTANCE + cam->posx, -SKY_DISTANCE + cam->posy, -SKY_DISTANCE + cam->posz);
  glTexCoord2f(1, 1);
  glVertex3f( SKY_DISTANCE + cam->posx, SKY_DISTANCE + cam->posy, -SKY_DISTANCE + cam->posz);
  glTexCoord2f(0, 1);
  glVertex3f( SKY_DISTANCE + cam->posx, SKY_DISTANCE + cam->posy, SKY_DISTANCE + cam->posz);
  glEnd();

  // Render the back quad
  glBindTexture(GL_TEXTURE_2D, Skybox[3]);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

  glBegin(GL_QUADS);
  glTexCoord2f(0, 0);
  glVertex3f(-SKY_DISTANCE + cam->posx, -SKY_DISTANCE + cam->posy, SKY_DISTANCE + cam->posz);
  glTexCoord2f(1, 0);
  glVertex3f( SKY_DISTANCE + cam->posx, -SKY_DISTANCE + cam->posy, SKY_DISTANCE + cam->posz);
  glTexCoord2f(1, 1);
  glVertex3f( SKY_DISTANCE + cam->posx, SKY_DISTANCE + cam->posy, SKY_DISTANCE + cam->posz);
  glTexCoord2f(0, 1);
  glVertex3f(-SKY_DISTANCE + cam->posx, SKY_DISTANCE + cam->posy, SKY_DISTANCE + cam->posz);

  glEnd();

  // Render the right quad
  glBindTexture(GL_TEXTURE_2D, Skybox[4]);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

  glBegin(GL_QUADS);
  glTexCoord2f(0, 0);
  glVertex3f(-SKY_DISTANCE + cam->posx, -SKY_DISTANCE + cam->posy, -SKY_DISTANCE + cam->posz);
  glTexCoord2f(1, 0);
  glVertex3f(-SKY_DISTANCE + cam->posx, -SKY_DISTANCE + cam->posy, SKY_DISTANCE + cam->posz);
  glTexCoord2f(1, 1);
  glVertex3f(-SKY_DISTANCE + cam->posx, SKY_DISTANCE + cam->posy, SKY_DISTANCE + cam->posz);
  glTexCoord2f(0, 1);
  glVertex3f(-SKY_DISTANCE + cam->posx, SKY_DISTANCE + cam->posy, -SKY_DISTANCE + cam->posz);
  glEnd();

  // Render the top quad
  glBindTexture(GL_TEXTURE_2D, Skybox[2]);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

  glBegin(GL_QUADS);
  glTexCoord2f(0, 1);
  glVertex3f(-SKY_DISTANCE + cam->posx, SKY_DISTANCE + cam->posy, -SKY_DISTANCE + cam->posz);
  glTexCoord2f(0, 0);
  glVertex3f(-SKY_DISTANCE + cam->posx, SKY_DISTANCE + cam->posy, SKY_DISTANCE + cam->posz);
  glTexCoord2f(1, 0);
  glVertex3f( SKY_DISTANCE + cam->posx, SKY_DISTANCE + cam->posy, SKY_DISTANCE + cam->posz);
  glTexCoord2f(1, 1);
  glVertex3f( SKY_DISTANCE + cam->posx, SKY_DISTANCE + cam->posy, -SKY_DISTANCE + cam->posz);
  glEnd();

  // Render the bottom quad

  glBindTexture(GL_TEXTURE_2D, Skybox[5]);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

  glBegin(GL_QUADS);
  glTexCoord2f(0, 1);
  glVertex3f(-SKY_DISTANCE + cam->posx, -SKY_DISTANCE + cam->posy, SKY_DISTANCE + cam->posz);
  glTexCoord2f(0, 0);
  glVertex3f(-SKY_DISTANCE + cam->posx, -SKY_DISTANCE + cam->posy, -SKY_DISTANCE + cam->posz);
  glTexCoord2f(1, 0);
  glVertex3f(SKY_DISTANCE + cam->posx, -SKY_DISTANCE + cam->posy, -SKY_DISTANCE + cam->posz);
  glTexCoord2f(1, 1);
  glVertex3f(SKY_DISTANCE + cam->posx, -SKY_DISTANCE + cam->posy, SKY_DISTANCE + cam->posz);
  glEnd();
}
