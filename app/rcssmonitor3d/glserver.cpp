#include "glserver.h"

GLserver::GLserver(int width, int height,
			salt::Vector3f camPos, 
			salt::Vector3f lookAtPos, 
			salt::Vector3f up, bool wire)
{
  mCamPos  = camPos;
  mLookAt  = lookAtPos;
  mUp      = up;

  mWidth     = width;
  mHeight    = height;
  mWireframe = wire;

  mCamera = Camera(camPos, lookAtPos, up);
}  

//---------------------------------ApplyCamera--------------------------
//
//----------------------------------------------------------------------
void GLserver::ApplyCamera()
{
  mCamera.Look();
}

//---------------------------------initGL-------------------------------
//
// OpenGL initialisation function
//----------------------------------------------------------------------
void GLserver::InitGL (void)
{
  if(!mWireframe)
    {
      GLfloat position[] = { 0.5, 1.5, 1.0, 0.0 };
      GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
      GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
      GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };

      glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
      glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
      glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

      glEnable(GL_LIGHTING);
      glEnable(GL_LIGHT0);
      glEnable(GL_NORMALIZE);
      glShadeModel(GL_SMOOTH);

      glLightfv(GL_LIGHT0, GL_POSITION, position);
    }

  glEnable(GL_DEPTH_TEST);

  glViewport(0,0,mWidth,mHeight);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0f,(GLfloat)mWidth/(GLfloat)mHeight,0.1f,100.0f);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}


//--------------------------drawGround-----------------------------------
//
// draws a virtual grid ground out of several green lines
//----------------------------------------------------------------------- 
void GLserver::DrawGround()
{
  //draw the lines GREEN
  glColor3ub(0, 255, 0);
  glBegin(GL_LINES);

  // Draw a 1x1 grid along the X and Z axis'
  for(float i = -50; i <= 50; i += 1)
    {
      // Do the horizontal lines (along the X)
      glVertex3f(-50, 0, i);
      glVertex3f(50, 0, i);

      // Do the vertical lines (along the Z)
      glVertex3f(i, 0, -50);
      glVertex3f(i, 0, 50);
    }
  glEnd();
}

//------------------------drawSphere-------------------------------------
//
// draws a solid sphere with given radius to position 'spherePos' 
//-----------------------------------------------------------------------
void GLserver::DrawSphere(salt::Vector3f spherePos,float radius)
{
  glPushMatrix();
  glTranslatef(spherePos[0],spherePos[1], spherePos[2]);
  if(!mWireframe) glutSolidSphere(radius, 10, 10);
  else glutWireSphere(radius, 10, 10);
  glPopMatrix();
}

  
  
