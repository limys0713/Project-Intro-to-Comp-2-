#include"mainwindow.h"
#include<iostream>
#include<string>
using namespace std;
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    setFixedSize(2500,1200);
    setMouseTracking(true);
    timerID=startTimer(10);
    timee=0;
    voice=0;
    drawcard=0;
    startingplayer=1;
    srand(time(NULL));
    
    img_uno_start.load("./data/uno_start");
    img_uno.load("./data/uno");
    img_start_button.load("./data/start_button");
    img_arror.load("./data/redarror"); 
    img_card[1][0].load("./data/Yellow0");
    img_card[1][1].load("./data/Yellow1");
    img_card[1][2].load("./data/Yellow2");
    img_card[1][3].load("./data/Yellow3");
    img_card[1][4].load("./data/Yellow4");
    img_card[1][5].load("./data/Yellow5");
    img_card[1][6].load("./data/Yellow6");
    img_card[1][7].load("./data/Yellow7");
    img_card[1][8].load("./data/Yellow8");
    img_card[1][9].load("./data/Yellow9");
    img_card[1][10].load("./data/YellowDrawtwo");
    img_card[1][11].load("./data/YellowReverse");
    img_card[1][12].load("./data/YellowSkip");
    img_card[2][0].load("./data/Blue0");
    img_card[2][1].load("./data/Blue1");
    img_card[2][2].load("./data/Blue2");
    img_card[2][3].load("./data/Blue3");
    img_card[2][4].load("./data/Blue4");
    img_card[2][5].load("./data/Blue5");
    img_card[2][6].load("./data/Blue6");
    img_card[2][7].load("./data/Blue7");
    img_card[2][8].load("./data/Blue8");
    img_card[2][9].load("./data/Blue9");
    img_card[2][10].load("./data/BlueDrawtwo");
    img_card[2][11].load("./data/BlueReverse");
    img_card[2][12].load("./data/BlueSkip");
    img_card[3][0].load("./data/Red0");
    img_card[3][1].load("./data/Red1");
    img_card[3][2].load("./data/Red2");
    img_card[3][3].load("./data/Red3");
    img_card[3][4].load("./data/Red4");
    img_card[3][5].load("./data/Red5");
    img_card[3][6].load("./data/Red6");
    img_card[3][7].load("./data/Red7");
    img_card[3][8].load("./data/Red8");
    img_card[3][9].load("./data/Red9");
    img_card[3][10].load("./data/RedDrawtwo");
    img_card[3][11].load("./data/RedReverse");
    img_card[3][12].load("./data/RedSkip");
    img_card[4][0].load("./data/Green0");
    img_card[4][1].load("./data/Green1");
    img_card[4][2].load("./data/Green2");
    img_card[4][3].load("./data/Green3");
    img_card[4][4].load("./data/Green4");
    img_card[4][5].load("./data/Green5");
    img_card[4][6].load("./data/Green6");
    img_card[4][7].load("./data/Green7");
    img_card[4][8].load("./data/Green8");
    img_card[4][9].load("./data/Green9");
    img_card[4][10].load("./data/GreenDrawtwo");
    img_card[4][11].load("./data/GreenReverse");
    img_card[4][12].load("./data/GreenSkip");
    img_card[0][0].load("./data/DrawFour");
    img_card[0][1].load("./data/DrawFour");
    img_card[0][2].load("./data/Wild");
    img_card[0][3].load("./data/Wild");
    img_cardback.load("./data/Cardback");
    img_player[1].load("./data/1P");
    img_player[2].load("./data/2P");
    img_player[3].load("./data/3P");
    img_endturn.load("./data/endturn");
    img_endturnyes.load("./data/endturnyes");
    img_forbidden.load("./data/forbidden");
    img_clockwise.load("./data/clockwise");
    img_counterclockwise.load("./data/counterclockwise");
    img_color[1].load("./data/yellow");
    img_color[2].load("./data/blue");
    img_color[3].load("./data/red");
    img_color[4].load("./data/green");
    img_youwin.load("./data/win");
    img_show.load("./data/show");
    img_background.load("./data/background");
    isarror=true;
    passedcard=false;
    isclockwise=true;
    forbidnext=false;
    ChangeColor=false;
    win=false;
    Show=false;
    state=0;
    nextcolor=0;
    lock=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<13;j++){
            for(int k=0;k<2;k++){
                card[i][j][k]=0;
            }
        }
    }
    for(int j=4;j<13;j++){
        for(int k=0;k<2;k++){
            card[0][j][k]=-1;
        }
    }
    for(int i=1;i<5;i++){
        for(int k=0;k<2;k++){
            card[i][0][k]=-1;
        }
    }
    for(int i=1;i<=7;i++){
        changeCard(0,1);
        changeCard(0,2);
        changeCard(0,3);
    }
        changeCard(0,6);
    while((FindLastCard()/100)==5 || (FindLastCard()%100)==10 || (FindLastCard()%100)==11 || (FindLastCard()%100)==12){
        changeCard(6,0);
        changeCard(0,6);
    }
}
void MainWindow::keyPressEvent(QKeyEvent *event){

    if(state==0){
    if(event->key() == Qt:: Key_1){		
		startingplayer=1;
	}
	if(event->key() == Qt:: Key_2){		 	
		startingplayer=2;
	}
	if(event->key() == Qt:: Key_3){				
		startingplayer=3;
    }	
    }
}
void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QFont font;
    QPen pen;
    painter.drawImage(0,0,img_background);
    painter.setRenderHint(QPainter::Antialiasing,true);
    font.setPointSize(20);
    painter.setFont(font);
    pen.setColor(Qt::black);
    painter.setPen(pen);
    painter.drawImage(10,700,img_show);      

    
    if(state==0){
        painter.drawImage(200,100,img_uno_start);
        painter.drawImage(250,491,img_start_button);
        painter.drawText(800,800, QString("X: %1 Y: %2").arg(mouse_x).arg(mouse_y));
	    painter.drawText(800,850,QString("Press numberpad1 or default is: Start from player1"));
        painter.drawText(800,880,QString("Press numberpad2 is: Start from player2"));
        painter.drawText(800,910,QString("Press numberpad3 is: Start from player3"));
        painter.drawText(800,940,QString("Press it before press the start button"));
    }
    if(state!=0){ 
        painter.drawImage(400,100,img_cardback);       
        painter.drawImage(0,0,img_player[state]);
        if(passedcard&&(nextcolor!=0||!ChangeColor)){
            painter.drawImage(1500,500,img_endturnyes);
        }
        if(isclockwise){
            painter.drawImage(645,109,img_clockwise);
        }
        if(!isclockwise){
            painter.drawImage(645,109,img_counterclockwise);
        }
        if(isarror){
            painter.drawImage(120+75*mousecard,670,img_arror);
        }
        if(!isarror){
            painter.drawImage(120+75*mousecard,670,img_forbidden);
        }
        if(passedcard){
            painter.drawImage(120+75*mousecard,670,img_forbidden);
        }
        for(int i=0;i<5;i++){
            for(int j=0;j<13;j++){
                for(int k=0;k<2;k++){
                    if(card[i][j][k]==6){
                        if(ChangeColor){
                            painter.drawImage(883,313,img_color[nextcolor]);
                        }
                        else{
                            painter.drawImage(900,300,img_card[i][j]);
                        }
                    }
                }
            }
        }
        int print_counter=0;
        for(int i=0;i<5;i++){
            for(int j=0;j<13;j++){
                for(int k=0;k<2;k++){
                    if(card[i][j][k]==state){
                        if(Show){
                            painter.drawImage(90+print_counter*75,700,img_card[i][j]);
                            print_counter++;
                        }
                        else{
                            painter.drawImage(90+print_counter*75,700,img_cardback);
                            print_counter++;
                        } 
                    }
                }
            }
        }
        if(ChangeColor){
            if(lock==0){
                painter.drawImage(795,225,img_color[1]);
                painter.drawImage(795,375,img_color[3]);
                painter.drawImage(945,225,img_color[2]);
                painter.drawImage(945,375,img_color[4]);
            }
        }
        for(int i=0;i<3;i++){
            if(FindCardAmount(i+1)==1){
                painter.drawImage(1400,20+50*i,img_uno);
            }
        }
        painter.drawText(1500,50,QString("1P remaining cards: %1").arg(FindCardAmount(1)));
        painter.drawText(1500,100,QString("2P remaining cards: %1").arg(FindCardAmount(2)));
        painter.drawText(1500,150,QString("3P remaining cards: %1").arg(FindCardAmount(3)));
        painter.drawText(1500,200,QString(" %1").arg(FindLastCard()));
        painter.drawText(1500,250,QString(" %1").arg(FindYourCard()));
        painter.drawText(1500,300,QString(" %1").arg(ChangeColor));
        if(win){
           painter.drawImage(0,0,img_youwin);
           for(int i=1;i<=3;i++){
                if(FindCardAmount(i)==0){
                    painter.drawImage(1200,300,img_player[i]); 
                }
            } 
            voice=1;
        }
    }   
}
void MainWindow::timerEvent(QTimerEvent *event){
    if(event->timerId()==timerID&&timerID!=0){
        if(timee%300==0){
            if(win){    
                if(voice==1){
                    QSound::play("./data/victory.wav");
                }
            }
        }
        timee++;
        update();

    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *event){
    mouse_x=event->x();
    mouse_y=event->y();
    if(mouse_y>=700&&mouse_y<=850){
        if(FindCardAmount(state)>(mouse_x-90)/75){
            mousecard=(mouse_x-90)/75;
        }           
    }
    if(isFallowSuit(FindLastCard()/100,FindLastCard()%100,FindYourCard()/100,FindYourCard()%100)){
        isarror=true;//能不能出那張牌
    }
    if(!isFallowSuit(FindLastCard()/100,FindLastCard()%100,FindYourCard()/100,FindYourCard()%100)){
        isarror=false;
    }
    update();
}
void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        if(mouse_x>=250&&mouse_x<=750&&mouse_y>=491&&mouse_y<=700&&state==0){
           state=startingplayer;
           if(startingplayer==1 || startingplayer==2){
                nextstate=startingplayer+1;
           }
           if(startingplayer==3){
                nextstate=1;
           }
        }
        if(mouse_x>=10&&mouse_x<=70&&mouse_y>=700&&mouse_y<=760){
            Show=true;
        }
        if(mouse_x>=90+75*mousecard&&mouse_x<=90+75*(mousecard+1)&&mouse_y>=700&&mouse_y<=850&&state!=0&&!win&&!passedcard){
            if(isarror){          
                for(int k=0;k<2;k++){
                    if(card[FindYourCard()/100][FindYourCard()%100][k]==state&&FindYourCard()!=-1){
                        if(FindCardAmount(6)!=0){
                            changeCard(6,0);
                            QSound::play("./data/card.wav");
                        }
                        card[FindYourCard()/100][FindYourCard()%100][k]=6;
                        if(ChangeColor){
                            ChangeColor=false;
                        }
                        passedcard=true;
                        if(FindLastCard()%100==11){
                            if(isclockwise){
                                isclockwise=false;
                            }
                            else{
                                isclockwise=true;
                            }                          
                        }
                        if(FindLastCard()%100==10){
                            changeCard(0,nextstate);
                            changeCard(0,nextstate);
                            forbidnext=true;
                        }
                        if(FindLastCard()%100==12){
                            forbidnext=true;
                        }
                        if(FindLastCard()/100==0&&(FindLastCard()%100==0||FindLastCard()%100==1)){
                            for(int i=1;i<=4;i++){
                                changeCard(0,nextstate);
                            }
                            forbidnext=true;
                            nextcolor=0;
                            ChangeColor=true;
                            lock=0;
                        }
                        if(FindLastCard()/100==0&&(FindLastCard()%100==2||FindLastCard()%100==3)){
                            nextcolor=0;
                            ChangeColor=true;
                            lock=0;
                        }
                        break;
                    }
                }      
            }
        }
        if(mouse_x>=1500&&mouse_x<=1600&&mouse_y>=500&&mouse_y<=600&&state!=0&&!win&&passedcard==true&&(!ChangeColor||nextcolor!=0)){
            if(FindCardAmount(state)==0){
                win=true;
            }
            if(isclockwise){
                state++;             
                if(state==4){
                    state=1;            
                }
                nextstate=state+1;
                if(nextstate==4){
                    nextstate=1;
                }
            }
            if(!isclockwise){
                state--;             
                if(state==0){
                    state=3;            
                }
                nextstate=state-1;
                if(nextstate==0){
                    nextstate=3;
                }
            }
            passedcard=false;
            Show=false;
            drawcard=0;
            if(forbidnext){
                passedcard=true;
                forbidnext=false;
            }
            if(lock<1){
                lock=1;
            }   
        }
        if(mouse_x>=400&&mouse_x<=490&&mouse_y>=100&&mouse_y<=250&&state!=0&&!win&&drawcard==0){
            changeCard(0,state);
            drawcard=1;
            passedcard=true;
        }
        if(ChangeColor){
            if(lock==0){
                if(mouse_x>=795&&mouse_x<=945&&mouse_y>=225&&mouse_y<=375&&state!=0&&!win){
                    nextcolor=1;
                }
                if(mouse_x>=945&&mouse_x<=1095&&mouse_y>=225&&mouse_y<=375&&state!=0&&!win){
                    nextcolor=2;
                }
                if(mouse_x>=795&&mouse_x<=945&&mouse_y>=375&&mouse_y<=525&&state!=0&&!win){
                    nextcolor=3;
                }
                if(mouse_x>=945&&mouse_x<=1095&&mouse_y>=375&&mouse_y<=525&&state!=0&&!win){
                    nextcolor=4;
                }
            }
        }        
        update(); 
    }
}
int MainWindow::FindCardAmount(int s){
    int cAmount=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<13;j++){
            for(int k=0;k<2;k++){
                if(card[i][j][k]==s){
                    cAmount++;
                }
            }
        }
    }
    return cAmount;
}
int MainWindow::FindLastCard(){
    for(int i=0;i<5;i++){
        for(int j=0;j<13;j++){
            for(int k=0;k<2;k++){
                if(card[i][j][k]==6){
                    return i*100+j;
                }
            }
        }
    }
    return -1;
}
int MainWindow::FindYourCard(){
    int cAmount=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<13;j++){
            for(int k=0;k<2;k++){
                if(card[i][j][k]==state&&cAmount!=mousecard+1){
                    cAmount++;
                }
                if(card[i][j][k]==state&&cAmount==mousecard+1){
                    return i*100+j;
                }
            }
        }
    }
    return -1;
}
void MainWindow::changeCard(int s,int f){   
        int Chance=rand()%FindCardAmount(s);
        int Change=0;
        for(int i=0;i<5;i++){
            for(int j=0;j<13;j++){
                for(int k=0;k<2;k++){
                    if(card[i][j][k]==s&&Change!=Chance){
                        Change++;
                    }
                    if(card[i][j][k]==s&&Change==Chance){
                        card[i][j][k]=f;
                        Change++;
                    }
                }
            }
        }    
}
bool MainWindow::isFallowSuit(int bc,int bn,int ac,int an){  
    if(ChangeColor){
        if(nextcolor==ac||ac==0){
            return true;
        }
    }
    else if(bc==ac||bn==an||ac==0||bn==-1||bc==0){
        return true;
    }
    return false;
}
MainWindow::~MainWindow(){

}