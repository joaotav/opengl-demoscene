#include <GL/glew.h> // Includes the GLEW library
#include <GL/glut.h> // Includes the GLUT library
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <time.h>

/* Implemented by João Chervinski (2017) */

time_t start = time(0); // Allows for checking the execution time

// Object movement control variables
bool movingLeft = true;
bool movingUp = false;
bool shrinking = true;
bool explode = false;

// Object position control variables
float yLocation = 0.0f;
float yRotationAngle = 0.0f;
float yPos = 0.0f;
float planeY = 0.0f; // Paper plane position y
float planeX = 0.0f; // Paper plane position x
float planeZ = 0.0f; // Paper plane position z

float coreScale = 1.5f;
float coreRotation = 0.0f;
float ringScale = 0.0f;


void displayText(GLfloat x, GLfloat y, const char *text) {
    // Prints text to the screen using glutStrokeCharacter
    glColor3f(0.0f, 1.0f, 0.0f); 

    glPushMatrix();
    glTranslatef(x, y, -5);
    for (const char *p = text; *p; p++) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
    }
    glPopMatrix();
}

void rainbowSquares(bool secondTime){
  // Section that displays squares that rotate and change colors pseudo-randomly
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f((float)(rand() % 100)/100, (float)(rand() % 100)/100, (float)(rand() % 100)/100); // Set the colour of the square to blue

  // Middle cube 1
  glLoadIdentity();
  glTranslatef(0.0f, yLocation, -5.0f); // Moves the object on the y-axis
  glRotatef(yRotationAngle, 0.0f, 06.0f, 0.0f); // Rotates the object on the y-axis
  if (secondTime) // On the second call renders solid cubes
  glutSolidCube(2.0f);
  else
  glutWireCube(2.0f);

  // Middle cube 2
  glLoadIdentity();
  glTranslatef(0.0f, -yLocation, -5.0f); // Moves the object on the y-axis
  glRotatef( yRotationAngle, 0.0f, 06.0f, 0.0f); // Rotates the object on the y-axis
  if (secondTime) // On the second call renders solid cubes
  glutSolidCube(2.0f);
  else
  glutWireCube(2.0f);

  // Right cube 1
  glLoadIdentity();
  glTranslatef(5.0f, yLocation * 2, -10.0f); // Moves the object on the y-axis
  glRotatef(-yRotationAngle * 10, 0.0f, 10.0f, 0.0f); // Rotates the object on the y-axis
  if (secondTime) // On the second call renders solid cubes
  glutSolidCube(2.0f);
  else
  glutWireCube(2.0f);

  // Right cube 2
  glLoadIdentity();
  glTranslatef(5.0f, - yLocation * 2, -10.0f); // Moves the object on the y-axis
  glRotatef(-yRotationAngle * 10, 0.0f, 10.0f, 0.0f); // Rotates the object on the y-axis
  if (secondTime) // On the second call renders solid cubes
  glutSolidCube(2.0f);
  else
  glutWireCube(2.0f);


  // Left cube 1
  glLoadIdentity();
  glTranslatef(-5.0f, yLocation * 2, -10.0f);
  glRotatef(-yRotationAngle * 10, 0.0f, 10.0f, 0.0f); // Rotates the object on the y-axis
  if (secondTime) // // On the second call renders solid cubes
  glutSolidCube(2.0f);
  else
  glutWireCube(2.0f);

  // Left cube 2
  glLoadIdentity();
  glTranslatef(-5.0f, -yLocation * 2 , -10.0f);
  glRotatef(-yRotationAngle * 10, 0.0f, 10.0f, 0.0f);  // Rotates the object on the y-axis
  if (secondTime) // On the second call renders solid cubes
  glutSolidCube(2.0f);
  else
  glutWireCube(2.0f);

  if (movingUp) // If the cubes are moving up
    yLocation += 0.1f;
  else  // Otherwise
    yLocation -= 0.1f;

  if (yLocation < -2.5f) // If the cubes are far below the center of the screen
    movingUp = true; // Changes their movement direction to up
  else if (yLocation > 0.0f)  // If the cubes are far above the center of the screen
    movingUp = false; // Changes their movement direction to down

  yRotationAngle += 1.0f; // Increases the rotation value

  glutSwapBuffers();
}


void torusRing(void){
  // Draws a figure composed of several tori that rotate, with a central torus that 'pulses'
  glColor3f(0.1f, 0.8f, 0.1f);
  glClear(GL_COLOR_BUFFER_BIT);


  glLoadIdentity();
  // If the total time exceeds 190, shrinks the components until they disappear
  glTranslatef(0.0f, 0.0f, -15.0f);
  if (difftime( time(0), start) > 190)
  glScalef(ringScale, ringScale, ringScale);
  glutSolidTorus(0.1f, 3.0f, 40, 40);

  glLoadIdentity();
  glTranslatef(-5.0f, 0.0f, -15.0f);
  if (difftime( time(0), start) > 190)
  glScalef(ringScale, ringScale, ringScale);
  glutSolidTorus(0.1f, 2.0f, 40, 40);

  glLoadIdentity();
  glTranslatef(5.0f, 0.0f, -15.0f);
  if (difftime( time(0), start) > 190)
  glScalef(ringScale, ringScale, ringScale);
  glutSolidTorus(0.1f, 2.0f, 40, 40);

  glColor3f(1.0f, 0.0f, 0.0f);
  glLoadIdentity();
  glTranslatef(0.0f, -5.0f, -15.0f);
  if (difftime( time(0), start) > 190)
  glScalef(ringScale, ringScale, ringScale);
  glutSolidTorus(0.1f, 2.0f, 40, 40);

  glColor3f(0.0f, 0.0f, 1.0f);
  glLoadIdentity();
  glTranslatef(0.0f, 5.0f, -15.0f);
  if (difftime( time(0), start) > 190)
  glScalef(ringScale, ringScale, ringScale);
  glutSolidTorus(0.1f, 2.0f, 40, 40);

  // Changes the colors of the central torus
  glColor3f((float)(rand() % 100)/100, (float)(rand() % 100)/100, (float)(rand() % 100)/100);
  glLoadIdentity();
  glTranslatef(0.0f, 0.0f, -15.0f);
  glScalef(ringScale, ringScale, ringScale);
  glutSolidTorus(0.1f, 1.0f, 40, 40);

  // If the time exceeds 190, only reduces the scale of the shapes
  if ((difftime( time(0), start) > 190) and (difftime( time(0), start) < 207)){
    shrinking = true;
  } else if (difftime( time(0), start) > 205)
    shrinking = false;

  else if (ringScale > 1.8f) // If the central torus gets too large
    shrinking = true;  // Sets the variable to shrink
  else if(ringScale < 1.0f) // If the central torus gets too small
    shrinking = false; // Sets the variable to grow

  if (shrinking)
    ringScale -= 0.008;
  else if (shrinking == false and (difftime( time(0), start) > 207)){
    if (ringScale < 0)
      ringScale += 0.1;
  }
  else
    ringScale += 0.008;

  glutSwapBuffers();
}


void cores(){
  glClear(GL_COLOR_BUFFER_BIT);
  if (!explode)
  // Chooses pseudo-random colours
  glColor3f((float)(rand() % 100)/100, (float)(rand() % 100)/100, (float)(rand() % 100)/100);
  else
  // Chooses pseudo-random colours of a darker shade
  glColor3f((float)(rand() % 100)/200, (float)(rand() % 100)/200, (float)(rand() % 100)/200);

  glLoadIdentity();
  glTranslatef(0.0f, 0.0f, -10.0f);
  glRotatef(yRotationAngle * 10, 2.0f, 0.0f, 0.0f);
  glScalef(coreScale, coreScale, coreScale);
  if (!explode) // Changes into a solid object before 'exploding' it 
    glutWireIcosahedron();
  else
    glutSolidIcosahedron();

  // While the elapsed time is below 78 seconds
  if (difftime( time(0), start) < 78){
    glLoadIdentity();
    glTranslatef(-4.0f, +4.0f, -10.0f);
    glRotatef(yRotationAngle * 10, 1.0f, 2.0f, 1.0f);
    glutWireTetrahedron();
    glutSolidSphere(0.2f, 20, 20);
  }

  // While the elapsed time is below 80 seconds
  if (difftime( time(0), start) < 80){
    glLoadIdentity();
    glTranslatef(+4.0f, +4.0f, -10.0f);
    glRotatef(yRotationAngle * 10, 2.0f, 1.0f, 1.0f);
    glutWireTetrahedron();
    glutSolidSphere(0.2f, 20, 20);
  }

  // While the elapsed time is below 82 seconds
  if (difftime( time(0), start) < 82){
    glLoadIdentity();
    glTranslatef(+4.0f, -4.0f, -10.0f);
    glRotatef(yRotationAngle * 10, 2.0f, 1.0f, 1.0f);
    glutWireTetrahedron();
    glutSolidSphere(0.2f, 20, 20);
  }

  // While the elapsed time is below 84 seconds
  if (difftime( time(0), start) < 84){
    glLoadIdentity();
    glTranslatef(-4.0f, -4.0f, -10.0f);
    glRotatef(yRotationAngle * 10, 1.0f, 2.0f, 1.0f);
    glutWireTetrahedron();
    glutSolidSphere(0.2f, 20, 20);
  }

  // Rotates the camera on the z-axis
  glMatrixMode(GL_PROJECTION);
  glRotatef(5.0f, 0.0f, 0.0f, 1.0f);
  glMatrixMode(GL_MODELVIEW);

  yRotationAngle += 1.0f; // Increases the rotation angle

  // As soon as all the smaller triangles vanish, shrinks the core and then make it explode
  // until it fills up the whole screen
  if(difftime( time(0), start) < 84){
  if (coreScale > 2.0f)
    shrinking = true;
  else if(coreScale < 1.5f)
    shrinking = false;

  if (shrinking)
    coreScale -= 0.015;
  else
    coreScale += 0.015;
  } else
    explode = true;
    coreScale -= 0.015;

  glutSwapBuffers();
}


void torusTunnel(){
  glColor3f((float)(rand() % 100)/300, (float)(rand() % 100)/300, (float)(rand() % 100)/300);
  glClear(GL_COLOR_BUFFER_BIT);

  for(int i = 0; i < 90; i ++){
    // Draws a tunnel composed by several toruses
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f - i * 3); // Translates the object on the z-axis
    glutSolidTorus(0.1f, 3.0f, 40, 40); // Draws a torus
  }

  glLoadIdentity();
  glTranslatef(0.0f, -2.0f + planeX, -15.0f - planeZ);
  glRotatef(255.0f, 1.0f , planeY, 0.0f);

  // Draws a paper plane
  glBegin(GL_TRIANGLE_STRIP);

  // Left wing
  glVertex3f(-7.0, 0.0, 2.0);
  glVertex3f(-1.0, 0.0, 3.0);
  glColor3f(1.0f, 1.0f,1.0f);
  glVertex3f(-1.0, 7.0, 3.0);

  // Left side
  glColor3f(0.6 * 0.0f, 0.6 * 1.0f, 0.6 * 1.0f);;
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(0.0, 8.0, 0.0);

  // Right side
  glVertex3f(1.0, 0.0, 3.0);
  glVertex3f(1.0, 7.0, 3.0);

  // Right wing
  glColor3f(0.9f, 0.9f, 0.9f);
  glVertex3f(7.0, 0.0, 2.0);
  glTranslatef(0.0f, 0.0f, planeZ);

  // Until the end of the tunnel, moves the airplane on the z-axis
  if (difftime( time(0), start) < 125)
  planeZ += 0.11f;
  glEnd();
  glutSwapBuffers();

  // Translates the object from one side to the other, giving the impression of movement
  if (planeY > 0.04f){
    movingLeft = false;
  } else if (planeY < -0.04f){
    movingLeft = true;
  }

  if (planeX > 0.05f){
    movingUp = false;
  } else if (planeY < -0.05f){
    movingUp = true;
  }

  if (movingLeft)
    planeY += 0.001;
  else
    planeY -= 0.001;

  if (movingUp)
    planeX += 0.001;
  else
    planeX -= 0.001;
}


void screenFlash(){
  // Makes the screen 'flash' quickly with various colors
  for(int i = 0; i < 100; i++)
    glClearColor((float)(rand() % 100)/100, (float)(rand() % 100)/100, (float)(rand() % 100)/100, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glFlush();
    glutSwapBuffers();
}


void intro(){
  // Shows the initial text of the demo
  // While the text position variable on the y-axis does not reach 2.80, the text rises
  while (yPos < 2.80f){
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0, 3000, 0, 3000);

  // Exibe o texto com a função que usa glutStrokeCharacter
  displayText(50, 1600 + yPos, "Music : The Algorithm - Boot ");
  displayText(50, 1400 + yPos, "Made by Joao Chervinski");
  displayText(50, 1200 + yPos, "2017");
  displayText(50, -1400 + yPos, "Coding is like magic");
  displayText(50, -1700 + yPos, "It gives us the ability to make things move");
  displayText(50, -2000 + yPos, "To give them life");
  displayText(50, -2800 + yPos, "But, unlike magic...");
  displayText(50, -3200 + yPos, "Coding is real");
  displayText(50, -3900 + yPos, "Don't you want to be a wizard?");


  glLoadIdentity();
  glTranslatef(0.0f, 0.0f, -5.0f);
  glColor3f(0.0f, 1.0f, 0.0f);
  glTranslatef(0.0f, yPos, 0.0f);
  yPos += 0.0006;
  glutSwapBuffers();
  }
}

void reshapeWindow(int width, int height) {
  glViewport (0, 0, (GLsizei)width, (GLsizei)height);
  glMatrixMode (GL_PROJECTION); // Switches to the projection matrix to manipulate the scene
  glLoadIdentity();

  // Defines the FOV, aspect ratio, and the planes
  gluPerspective (70, (GLfloat)width / (GLfloat)height, 1.0, 150.0); 
  glMatrixMode (GL_MODELVIEW); // Switches back to model view so we can draw the shapes
}


void torusCore(){
  glEnable(GL_DEPTH_TEST);
  glClearDepth(1.0);
  glColor3f((float)(rand() % 100)/100, (float)(rand() % 100)/100, (float)(rand() % 100)/100);
  glClear(GL_COLOR_BUFFER_BIT);

  GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 0.0};  // White light
  GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0}; // Position of the light source
  glEnable(GL_LIGHT0); // Creates a light source
  glEnable(GL_LIGHTING); // Enables lighting
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   // Enables colors in materials to avoid issues with lighting
  glEnable(GL_COLOR_MATERIAL);

  glLoadIdentity();
  glTranslatef(0.0f, 0.0f, -10.0f); // Moves to the position where the object will be created
  glRotatef(coreRotation, 1.0f, 0.0f, 0.0f);
  glScalef(coreScale, coreScale, coreScale); // Alternates the size of the center
  glutWireSphere(1.0f, 40, 40);

  glColor3f(0.1f + coreScale / 10, 0.1f + coreScale / 10, 0.8f + coreScale / 10);
  glLoadIdentity();
  glTranslatef(0.0f, 0.0f, -10.0f);
  glRotatef(coreRotation, 0.0f, 5.0f, 5.0f); // Rotates the torus on the y and z axes
  glutSolidTorus(0.3f, 6.0f, 40, 40);

  glColor3f(0.8f + coreScale / 10, 0.6f + coreScale / 10, 0.2f + coreScale / 10);
  glLoadIdentity();
  glTranslatef(0.0f, 0.0f, -10.0f);
  glRotatef(coreRotation, 5.0f, 5.0f, 0.0f); // Rotates the torus on the x and y axes
  glutSolidTorus(0.3f, 5.0f , 40, 40);

  glColor3f(0.5f + coreScale / 10, 0.1f + coreScale / 10, 0.5f + coreScale / 10);
  glLoadIdentity();
  glTranslatef(0.0f, 0.0f, -10.0f);
  glRotatef(coreRotation, 0.0f, 5.0f, 0.0f); // Rotates the torus on the y axis
  glutSolidTorus(0.3f, 5.5f, 40, 40);

  glColor3f(0.1f + coreScale / 10, 0.4f + coreScale / 10, 0.3f + coreScale / 10);
  glLoadIdentity();
  glTranslatef(0.0f, 0.0f, -10.0f);
  glRotatef(coreRotation, 5.0f, 0.0f, 0.0f); // Rotates the torus on the x axis
  glutSolidTorus(0.3f, 6.5f, 40, 40);

  if (coreScale > 2.0f) // If the central icosahedron grows too much
    shrinking = true; // Enables the shrinking variable
  else if(coreScale < 1.5f) // If the central icosahedron shrinks too much
    shrinking = false; // Disables the shrinking variable

  if (shrinking)
    coreScale -= 0.020;
  else
    coreScale += 0.020;

  coreRotation += 1;

  glutSwapBuffers();
}

void display(void) {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Sets the background color to black
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clears the color buffer

  if (difftime( time(0), start) < 42){
    // Starts the demo with the intro
    intro();
  }

  else if (difftime( time(0), start) >= 42 and difftime( time(0), start) < 44) {
    // Makes the screen flash to start the animations with geometry
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (80, (GLfloat)glutGet(GLUT_WINDOW_WIDTH) /(GLfloat)glutGet(GLUT_WINDOW_HEIGHT), 1.0, 150.0); // Define o FOV, AR, e os planos
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    screenFlash();

  }
  else if (difftime( time(0), start) >= 44 and difftime( time(0), start) < 50) {
    // Calls the rotating squares
    rainbowSquares(false);
  }
  else if (difftime( time(0), start) >= 50 and difftime( time(0), start) < 56){
    // Rotates the camera so the squares spin on the z-axis
    glMatrixMode(GL_PROJECTION);
    glRotatef(10.0, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    rainbowSquares(false);
  }
  else if (difftime( time(0), start) >= 56 and difftime( time(0), start) < 64){
    // Same function as the previous squares, but now with solid geometry
    rainbowSquares(true);
  }
  else if (difftime( time(0), start) >= 64 and difftime( time(0), start) < 72) {
    // Solid squares rotating while the camera rotates on the z-axis
    glMatrixMode(GL_PROJECTION);
    glRotatef(10.0, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    rainbowSquares(true);
  }
  else if (difftime( time(0), start) >= 72 and difftime( time(0), start) < 97){
    // Triangles with a sphere core that rotate around an icosahedron until
    // they all disappear and the icosahedron 'explodes'
    cores();
  }
   else if (difftime( time(0), start) >= 97 and difftime( time(0), start) < 132){
    // A tunnel composed of several tori that change color, with a paper airplane
    // traveling through the tunnel, following the camera
    glMatrixMode(GL_PROJECTION);
    glTranslatef(0.0f, 0.0f, 0.11f);
    glMatrixMode(GL_MODELVIEW);
    torusTunnel();
  }
   else if (difftime( time(0), start) >= 132 and difftime( time(0), start) < 167){
    // A set of tori with a central icosahedron
    // The tori rotate while the icosahedron expands and shrinks
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (80, (GLfloat)glutGet(GLUT_WINDOW_WIDTH) /(GLfloat)glutGet(GLUT_WINDOW_HEIGHT), 1.0, 150.0); // Define o FOV, AR, e os planos
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    torusCore();
  }
   else if (difftime( time(0), start) >= 167 and difftime( time(0), start) < 209){
    // A shape composed of several connected tori, which spin due to the camera rotation
    // After a certain time, the shapes shrink until they disappear and then expand until 
    //they fill the screen
    glDisable(GL_LIGHTING);
    glMatrixMode(GL_PROJECTION);
    glRotatef(10.0, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    torusRing();
  }
    else {
      exit(0);
    }
}


int main(int argc, char* argv[]){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); // Initiates the display buffer
  glutInitWindowSize (1200, 700); // Sets the initial window size
  glutInitWindowPosition (100, 100); // Sets the initial window position
  glutCreateWindow ("Demo - B00T"); // Creates the window with the title "Demo - B00T"
  glutDisplayFunc(display); // Registers the display callback function
  glutReshapeFunc(reshapeWindow); // Registers the reshape callback function
  glutIdleFunc(display); // Registers the idle callback function to continuously update the display
  glutMainLoop(); // Enters the GLUT event processing loop

  return 0;
}
