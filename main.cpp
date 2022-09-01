#include <Math.h>                   //conjunto de fun��es para opera��es matem�ticas
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
// variaveis para a transform�ao e uso com keyborads
static float tamanho = 2; // tamanho defenido incialemnte para multiplicar 2x
static float rotacao = 35; // defenmido inicialmente 35 graus
static float moverx = -5; //posi�ao inicial x
static float movery = -1; //posi�ao inicial y
//Fun��o que adiciona linhas para montar um plano cartesiano
void cartesiano(){
    glLineWidth(1);               //adiciona espessura a linha desenhada
    glColor3f(0,0,0);             //adiciona cor �s linhas
    glBegin(GL_LINES);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(-20.0, 0.0);   //desenha uma linha no eixo -50x at� o ponto do eixo 50x
        glVertex2f(20, 0.0);
        glVertex2f(0.0, -20.0);   //desenha uma linha no eixo -50y at� o ponto do eixo 50y
        glVertex2f(0, 20);
    glEnd();
}


void objeto1(){
    glColor3f(0.0, 0.81, 0.0);  //adiciona cor ao nosso quadrado
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(2, 7);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(2, 11);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-2, 11);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-2, 7);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
}

void objeto2(){
    glColor3f(0.0, 0.81, 0.0);  //adiciona cor ao nosso quadrado
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(1, 7);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(1, 2);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-1, 2);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-1, 7);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
}

void objeto3(){
    glColor3f(0.0, 0.81, 0.0);  //adiciona cor ao nosso quadrado
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(-2.5, 1.5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(2.5, 1.5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(2.5, 2);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-2.5, 2);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
}

void objeto4(){
    glColor3f(0.0, 0.81, 0.0);  //adiciona cor ao nosso quadrado
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(-2.5, 0.5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-1.5, 0.5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-1.5, 1.5);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-2.5, 1.5);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
}

void objeto5(){
    glColor3f(0.0, 0.81, 0.0);  //adiciona cor ao nosso quadrado
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(1.5, 0.5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(2.5, 0.5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(2.5, 1.5);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(1.5, 1.5);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
}
void DesenhaTexto(void *font, char *string)
{
	// Exibe caractere a caractere
	while(*string)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,*string++);
}
void DesenhaTexto2(void *font, char *string)
{
	// Exibe caractere a caractere
	while(*string)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,*string++);
}

void transformacao(){
    glColor3f(1, 0.84, 0);   //adiciona cor
    glRotatef(rotacao,0,0,1);     // Gira o objeto 35 graus ao redor do eixo z
    glScalef(tamanho, tamanho, tamanho);      // aumenta a escala em 2x
    glTranslatef(moverx, movery, 0); //move o objeto -5 no x e -1 no y

    glColor3f(0.0, 0.81, 0.0);

    objeto1();
    objeto2();
    objeto3();
    objeto4();
    objeto5();
}



//Fun��o de desenho
void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);  //buffer padr�o (limpa a tela toda vez que a fun��o � chamada)
	glMatrixMode(GL_PROJECTION);   //proje��o dos pontos definidos no plano cartesiano
    glLoadIdentity();              //carrega a proje��o
    gluOrtho2D(-40,40,-40,40);     // define o tamanho do plano cartesiano
	glMatrixMode(GL_MODELVIEW);    // proje��o do tipo modelo
    glLoadIdentity();              // carrega a identidade de proje��o de modelo

    glPushMatrix();       //insere a matriz de transforma��o corrente na pilha
        cartesiano();     //chama a fun��o que desenha o plano cartesiano
    glPopMatrix();        //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente


    glPushMatrix();      //insere a matriz de transforma��o corrente na pilha
        objeto1();      //chama a fun��o que desenha o quadrado da casa
    glPopMatrix();       //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente

    glPushMatrix();      //insere a matriz de transforma��o corrente na pilha
        objeto2();      //chama a fun��o que desenha o quadrado da casa
    glPopMatrix();       //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente

    glPushMatrix();      //insere a matriz de transforma��o corrente na pilha
        objeto3();      //chama a fun��o que desenha o quadrado da casa
    glPopMatrix();       //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente

    glPushMatrix();      //insere a matriz de transforma��o corrente na pilha
        objeto4();      //chama a fun��o que desenha o quadrado da casa
    glPopMatrix();       //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente


    glPushMatrix();      //insere a matriz de transforma��o corrente na pilha
        objeto5();      //chama a fun��o que desenha o quadrado da casa
    glPopMatrix();       //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente

    glPushMatrix();
    transformacao();
    glPopMatrix();


	glPopMatrix();

	glColor3f(0,0,1);
    glRasterPos2f(-20,-23);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"Use teclas 'w s a d' para mover ");
	glRasterPos2f(-30,-26);
	DesenhaTexto2(GLUT_BITMAP_9_BY_15,"e '1 2' para aumentar e diminuir tamanho e ' 3 4 ' para rotacionar o objeto ");


	glFlush();          //carrega os comandos OpenGL (envia para o hardware os comandos, permitindo assim que os drivers GL iniciem o render)

}
static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case '1':
            tamanho=tamanho+0.1;
            break;
        case '2':
            tamanho=tamanho-0.1;
            break;
        case '3':
            rotacao=rotacao+0.5;
            break;
        case '4':
            rotacao=rotacao-0.5;
            break;
        case 'a':
            moverx=moverx-0.2;
            break;
        case 'd':
            moverx=moverx+0.2;
            break;
        case 'w':
            movery=movery+0.2;
            break;
        case 's':
            movery=movery-0.2;
            break;


    }

    glutPostRedisplay();
}

int main(void){

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);                                                      //somente um buffer | sistema de cores RGB
    glutInitWindowSize(800,600);                                                                      //define o tamanho da janela
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,(glutGet(GLUT_SCREEN_HEIGHT)-540)/2);   //medidas usadas para posicionar a janela no meio da tela - isso depende da resolu��o do monitor
    glutCreateWindow("Introdu��o ao OpenGL");                                                         //permite a cria��o de uma janela
    glutDisplayFunc(desenhaObjetos);                                                                  //fun��o de callback - chama a fun��o desenhaObjetos
    glClearColor(1,1,1,0);
    glutKeyboardFunc(key);                                                                          //informa a cor de fundo da tela (branco)
    glutMainLoop();
                                                                                 //loop infinito - escuta as informa��es do sistema at� encerrar a aplica��o
    return 0;                                                                                         //retorna zero
}


