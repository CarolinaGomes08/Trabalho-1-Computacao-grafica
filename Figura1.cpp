#include <stdlib.h>
#include <windows.h>
#include <gl/glut.h>
#include <math.h>


void desenhaCirculo(float raio, float cx, float cy)
{
    float ang, x, y;
    glBegin( GL_POLYGON );
        for(int i = 0; i<360; i++ )
        {
            ang = (i * 3.14) / 180;
            x = cx + (cos(ang) * raio);
            y = cy + (sin(ang) * raio);
            glVertex2f(x, y);
        }
    glEnd();
}

void desenhaRetangulo(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
        glVertex2f(x4, y4);
        glVertex2f(x1, y1);
    glEnd();
}

void Inicializa (void)
{
    // Define a cor de fundo da janela de visualização como verde
    glClearColor(0.000, 0.000, 0.000, 1.0f);
    // Define a janela de visualização 2D
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-30.0,30.0,-30.0,30.0);

}

void desenhaPacMan(float raio, float cx, float cy)
{
    float ang;
    float pi=3.1417;

    glBegin(GL_POLYGON);
        glColor4f(1,1,0.3,0);
        glVertex2d(cx,cy);
        //for(ang=(2*pi/3);ang<=((7*pi)/3);ang+=0.03) Pra cima
        //for(ang=(pi/6);ang<=((11*pi)/6);ang+=0.03) Pra frente
        //for(ang=(7*pi/6);ang<=((17*pi)/6);ang+=0.03) Pra trás
        // for(ang=(5*pi/3);ang<=((10*pi)/3);ang+=0.03) Pra baixo
        //pi/6, 11*pi/6
        for(ang=(pi/6);ang<=((11*pi)/6);ang+=0.03)
        {
            glColor4f(1,1,0.3,0);
            glVertex2f((cx+(raio*cos(ang))),(cy+ raio*sin(ang)));
        }
    glEnd();
}

// Função callback chamada para fazer o desenho
void Desenha(void)
{
    //Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);

    desenhaPacMan(10, 0, 0);

    /*
    Desenho do fantasma:
    //Define a cor do fantasma(rosa):
    glColor3f(1,0,0.5);

    desenhaCirculo(2, 0, 0);

    glBegin(GL_POLYGON);
        glVertex2f(-2.0, 0);
        glVertex2f(2.0, 0);
        glVertex2f(2.0, -2.0);
        glVertex2f(-2.0, -2.0);
    glEnd();

    desenhaCirculo(1, -1, -2);
    desenhaCirculo(1, 0, -2);
    desenhaCirculo(1, 1, -2);

    glColor3f(1,1,1);
    desenhaCirculo(0.5, -0.75, 0.75);
    desenhaCirculo(0.5, 0.75, 0.75);

    glColor3f(0,0,1);
    desenhaCirculo(0.25, -0.75, 0.75);
    desenhaCirculo(0.25, 0.75, 0.75);

    */

    /*
    // Define a cor de desenho: amarelo
    glColor3f(1.0,1.0,0.0);
    // Desenhar um losango
    glBegin(GL_POLYGON);
        glVertex2f(-3.0, 0.0);
        glVertex2f(-2.0, 1.0);
        glVertex2f(-1.0, 0.0);
        glVertex2f(-2.0, -1.0);
    glEnd();

    // Define a cor de desenho: azul
    glColor3f(0.0,0.0,1.0);
    // Desenhar um losango
    glBegin(GL_POLYGON);
        glVertex2f(-1.0, 2.0);
        glVertex2f(0.0, 3.0);
        glVertex2f(1.0, 2.0);
        glVertex2f(0.0, 1.0);
    glEnd();

    // Define a cor de desenho: vermelho
    glColor3f(1.0,0.0,0.0);
    // Desenhar um losango
    glBegin(GL_POLYGON);
        glVertex2f(1.0, 0.0);
        glVertex2f(2.0, 1.0);
        glVertex2f(3.0, 0.0);
        glVertex2f(2.0, -1.0);
    glEnd();

    // Define a cor de desenho: preto
    glColor3f(0.0,0.0,0.0);
    // Desenhar um losango
    glBegin(GL_POLYGON);
        glVertex2f(-1.0, -2.0);
        glVertex2f(0.0, -1.0);
        glVertex2f(1.0, -2.0);
        glVertex2f(0.0, -3.0);
    glEnd();
*/


    //Executa os comandos OpenGL para renderização.
    glFlush();
}

// Função callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y)
{
    if (key == 27)
    exit(0);
}

int main(void)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Primeiro Programa");
    glutDisplayFunc(Desenha);
    Inicializa();
    glutMainLoop();
    glutKeyboardFunc (Teclado);
}
