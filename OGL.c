// header files
#include<GL/freeglut.h>
#include <math.h>
#define PI 3.14
#define ANIMATION_TIME 250

// global variable declarations
BOOL bFullScreen = FALSE;
int global_CurrentKeyframe = 1;
FLOAT LegXPosition = 2.0f;

// Entry-point function
int main(int argc, char* argv[])
{
	// local function declarations
	int initialize(void);
	void resize(int, int);
	void display(void);
	void keyboard(unsigned char, int, int);
	void mouse(int, int, int, int);
	void uninitialize(void);
	void UpdateLegTimer(int);
	void UpdateLegPosition(int);

	// code
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("VISHAL SAJJAN KAMBALE");

	initialize();

	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutCloseFunc(uninitialize);
	glutTimerFunc(ANIMATION_TIME, UpdateLegTimer, 0);
	glutTimerFunc(50, UpdateLegPosition, 0);

	glutMainLoop();

	return(0);
}

int initialize(void)
{
	// code
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	return(0);
}

void resize(int width, int height)
{
	// code
	glViewport(0, 0, width, height);
}

void display(void)
{
	//functon prototype
	void DrawLeg(int);
	
	// code
	glClear(GL_COLOR_BUFFER_BIT);

	//1st Traingle

	glBegin(GL_TRIANGLES);
	glColor3f(0.5f, 0.8f, 1.0f);
	glVertex3f(0.0f, 0.1f, 0.0f);
	glColor3f(0.5f, 0.8f, 1.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);
	glColor3f(0.5f, 0.8f, 1.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);

	//glEnd();

	//glutSwapBuffers();

	//second Triangle - Upside

	glBegin(GL_TRIANGLES);
	glColor3f(0.5f, 0.8f, 1.0f);
	glVertex3f(0.0f, 0.1f, 0.0f);
	glColor3f(0.5f, 0.8f, 1.0f);
	glVertex3f(-0.1f, 0.3f, 0.0f);
	glColor3f(0.5f, 0.8f, 1.0f);
	glVertex3f(0.1f, 0.3f, 0.0f);

	//3 Square :- Neck
	glBegin(GL_POLYGON);

	glColor3f(0.5f, 0.8f, 1.0f);
	glVertex3f(0.02f, 0.3f, 0.0f);

	glColor3f(0.5f, 0.8f, 1.0f);
	glVertex3f(0.02f, 0.36f, 0.0f);

	glColor3f(0.5f, 0.8f, 1.0f);
	glVertex3f(-0.02f, 0.36f, 0.0f);

	glColor3f(0.5f, 0.8f, 1.0f);
	glVertex3f(-0.02f, 0.3f, 0.0f);

	glEnd();

	//Circle
	glBegin(GL_LINES);

	float radius = 0.06f;

	float x = 0.0f;
	float y = 0.0f;

	float origin_x = 0.0f;
	float origin_y = 0.42f;

	for (float angle = 0.0f; angle <= 360.0f; angle = angle + 0.01f)
	{
		glColor3f(0.82f, 0.70f, 0.55f);
		glVertex3f(origin_x, origin_y, 0.0f); //Origin Point

		x = origin_x + radius * cos(angle * (PI / 180.0f));
		y = origin_y + radius * sin(angle * (PI / 180.0f));

		glColor3f(0.82f, 0.70f, 0.55f);
		glVertex3f(x, y, 0.0f); //Outher oint of circle

	}

	

	//5. Legs

	//code
	glBegin(GL_LINES); //Right Legs
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.05f, -0.1f, 0.0f);
	glVertex3f(0.1f, -0.2f, 0.0f);

	glVertex3f(0.1f, -0.2f, 0.0f);
	glVertex3f(0.0f, -0.3f, 0.0f);

	glBegin(GL_LINES); //Left Legs
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.05f, -0.1f, 0.0f);
	glVertex3f(0.0f, -0.2f, 0.0f);

	glVertex3f(0.0f, -0.2f, 0.0f);
	glVertex3f(-0.1f, -0.3f, 0.0f);

	glEnd();

	//code
	glBegin(GL_LINES); //Right Hand
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.1f, 0.3f, 0.0f);
	glVertex3f(0.25f, 0.36f, 0.0f);

	glVertex3f(0.25f, 0.36f, 0.0f);
	glVertex3f(0.15f, 0.45f, 0.0f);

	glBegin(GL_LINES); //Left Hand
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.1f, 0.3f, 0.0f);
	glVertex3f(-0.2f, 0.2f, 0.0f);

	glVertex3f(-0.2f, 0.2f, 0.0f);
	glVertex3f(-0.1f, 0.1f, 0.0f);

	glEnd();
	glutSwapBuffers();

	DrawLeg(global_CurrentKeyframe);
}

void UpdateLegPosition(int Value)
{
	LegXPosition = LegXPosition - 0.01f;
	if (LegXPosition < 0.0f)
	{
		LegXPosition = 0.0f;
	}
	else
	{
		glutTimerFunc(50, UpdateLegPosition, 0);
	}
}

void DrawLeg(int currentKeyframe)
{
	//code
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);

	switch (currentKeyframe)
	{
	case 1:

		glVertex3f(LegXPosition + 0.0f, 0.125f, 0.0f);
		glVertex3f(LegXPosition + 0.0f, -0.075f, 0.0f);

		glVertex3f(LegXPosition + 0.0f, -0.075f, 0.0f);
		glVertex3f(LegXPosition + 0.125f, -0.25f, 0.0f);
		break;
	case 2:
		glVertex3f(LegXPosition + 0.0f, 0.125f, 0.0f);
		glVertex3f(LegXPosition - 0.05f, -0.075f, 0.0f);

		glVertex3f(LegXPosition - 0.05f, -0.075f, 0.0f);
		glVertex3f(LegXPosition - 0.05f, -0.25f, 0.0f);
		break;
	case 3:
		glVertex3f(LegXPosition + 0.0f, 0.125f, 0.0f);
		glVertex3f(LegXPosition - 0.1f, -0.075f, 0.0f);

		glVertex3f(LegXPosition - 0.1f, -0.075f, 0.0f);
		glVertex3f(LegXPosition - 0.125f, -0.25f, 0.0f);
		break;
	case 4:
		glVertex3f(LegXPosition + 0.0f, 0.125f, 0.0f);
		glVertex3f(LegXPosition - 0.0f, -0.125f, 0.0f);

		glVertex3f(LegXPosition - 0.0f, -0.125f, 0.0f);
		glVertex3f(LegXPosition - 0.0f, -0.25f, 0.0f);
		break;



	}



	glEnd();
}



void UpdateLegTimer(int Value)
{
	//code
	global_CurrentKeyframe++;
	if (global_CurrentKeyframe > 3)
	{
		global_CurrentKeyframe = 1;
	}
	if (LegXPosition <= 0.0f)
	{
		global_CurrentKeyframe = 4;
	}
	else
	{
		glutTimerFunc(ANIMATION_TIME, UpdateLegTimer, 0);
	}

}

void keyboard(unsigned char key, int x, int y)
{
	// code
	switch(key)
	{
	case 27:
		glutLeaveMainLoop();
		break;
	case 'F':
	case 'f':
		if (bFullScreen == FALSE)
		{
			glutFullScreen();
			bFullScreen = TRUE;
		}
		else
		{
			glutLeaveFullScreen();
			bFullScreen = FALSE;
		}
		break;
	default:
		break;
	}
}

void mouse(int button, int state, int x, int y)
{
	// code
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		glutLeaveMainLoop();
		break;
	default:
		break;
	}
}

void uninitialize(void)
{
	// code
}
