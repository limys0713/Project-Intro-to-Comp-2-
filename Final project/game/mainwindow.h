#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLabel>
#include <fstream>
#include <QPushButton>
#include <string>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>
#include <QSound>
#include <QPropertyAnimation>
#include <iostream>
#include <cstdlib>
#include <QTimer>
#include <ctime>
#include <unistd.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
private:
    int FindCardAmount(int s);
    int FindLastCard();
    int FindYourCard();
    void changeCard(int s,int f);
    bool isFallowSuit(int bc,int bn,int ac,int an);
    bool isNextTurn();
    bool isarror;
    bool passedcard;
    bool isclockwise;
    bool forbidnext;
    bool ChangeColor;
    bool win;
    bool Show;
    int nextcolor;
    int lock;
    int state;
    int nextstate;
    int timee;
    int mouse_x;
    int mouse_y;
    int mousecard;
    int timerID;
    int voice;
    int drawcard;
    int startingplayer;
    int card[5][13][2]; //卡牌陣列，第一個中括號表示顏色，0:黑色，1:黃色，2:藍色，3:紅色，4:綠色
                        //第二個括號表示數字，10表示+2，11表示反轉，12表示skip;黑色0、1表示+4，2、3表示選顏色
                        //第三個括號為第幾張
    QImage img_card[5][13];
    QImage img_cardback;
    QImage img_arror;
    QImage img_forbidden;
    QImage img_endturn;
    QImage img_endturnyes;
    QImage img_player[4];
    QImage img_clockwise;
    QImage img_counterclockwise;
    QImage img_color[5];
    QImage img_uno;
    QImage img_uno_start;
    QImage img_start_button;
    QImage img_youwin;
    QImage img_show;
    QImage img_background;
};


#endif