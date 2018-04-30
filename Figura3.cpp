#include <stdlib.h>
#include <windows.h>
#include <gl/glut.h>
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualização como preto
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    // Define a janela de visualização 2D
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-5.0,5.0,-5.0,5.0);

}
    // Função callback chamada para fazer o desenho
void Desenha(void)
{
    //Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);
    // Desenha um triângulo no centro da janela
    glBegin(GL_LINE_LOOP);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(-2.165, -1.25);
        glVertex2f(-0.79, 0.375);

        glColor3f(0.0,1.0,0.0);
        glVertex2f(0, 2.5);
        glVertex2f(0.645, 0.375);

        glColor3f(0.0,0.0,1.0);
        glVertex2f(2.165, -1.25);
        glVertex2f(0, -0.75);
    glEnd();
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
    //Chamada da Função de entrada de dados via teclado
    glutKeyboardFunc (Teclado);
}
