#include <windows.h>
#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h


void display()
{


    glClear(GL_COLOR_BUFFER_BIT);
    int flag = 0;  // Start with black color for the first square

    for (int y=0;y<800; y += 100)
        {
        for (int x =0; x<800; x += 100)
         {
                   // White color
            if (flag == 0)
            {
                glColor3f(1.0f, 1.0f, 1.0f);
            }
                   // Black color
            else
            {
                glColor3f(0.0f, 0.0f, 0.0f);  // White color
            }

            glBegin(GL_QUADS);  // Draw a square
                glVertex2f(x, y);
                glVertex2f(x + 100, y);
                glVertex2f(x + 100, y +100);
                glVertex2f(x, y +100);
            glEnd();

           flag = 1 - flag;  // Toggle the color for the next square
        }
        flag = 1 - flag;  // Toggle starting color for the next row
    }

    glFlush();  }


void init()
 {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,800,800,0);
}


/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv)
 {
    glutInit(&argc, argv);
    glutInitWindowSize(800,800); // Set the window's initial width & height
    glutInitWindowPosition(0,0);  // Set the window's initial position according to the monitor
    glutCreateWindow("Chessboard"); // Create a window with the given title
    init();
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
