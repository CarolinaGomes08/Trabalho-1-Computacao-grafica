#include <stdlib.h>
#include <windows.h>
#include <gl/glut.h>
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualização como amarelo
    glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
    // Define a janela de visualização 2D
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-5.0,5.0,-5.0,5.0);

}
    // Função callback chamada para fazer o desenho
void Desenha(void)
{
    //Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);
    // Define a cor de desenho: vermelho
    glColor3f(1.0,0.0,0.0);
    glLineWidth(10);
    // Desenha o quadrado:
    glBegin(GL_LINE_LOOP);
        glVertex2i(-2.0, -2.0);
        glVertex2i(-2.0, 2.0);
        glVertex2i(2.0, 2.0);
        glVertex2i(2.0, -2.0);
    glEnd();
    // Desenhando as linhas:
    glBegin(GL_LINES);
        glVertex2f(-5.0, 0.0);
        glVertex2f(-0.2, 0.0);
        glVertex2f(0.2, 0.0);
        glVertex2f(5.0, 0.0);
        glVertex2f(0.0, -5.0);
        glVertex2f(0.0, -0.2);
        glVertex2f(0.0, 0.2);
        glVertex2f(0.0, 5.0);
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
