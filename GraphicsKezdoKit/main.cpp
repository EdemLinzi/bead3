#include "graphics.hpp"
#include "statictext.hpp"
#include "textedit.hpp"
#include "widgets.hpp"
#include "examplecheckbox.hpp"
#include "pushbutton.hpp"
#include "kivalaszto.hpp"
#include "window.hpp"

#include <vector>
#include <fstream>
#include <iostream>

using namespace genv;

struct Par{
    std::string magyar;
    std::string angol;
};


std::vector<Par> beolvas(std::string filename){
    ifstream fbe(filename);
    std::vector<Par> data;
	if(fbe.fail()){
		std::cout<<"Hiba a fájl beolvasásánál"<<std::endl;
	}
	else{
		//std::cout<<"Elkezdõdött"<<std::endl;
		//std::string s;
		Par s;
		while(!fbe.eof()){
            fbe>>s.angol;
            fbe>>s.magyar;
            data.push_back(s);
		}
	}
	return data;
	//fbe fclose();
}

std::vector<std::string> Osszefesul(){
    std::vector<Par> parok=beolvas("Bemenet.txt");
    std::vector<std::string > kesz;
    //std::string s;
    for(unsigned int i=0;i<parok.size()-1;i++){
        //s=Par[i].magyar+" "+Par[i].angol;
        kesz.push_back(parok[i].magyar+"\t"+parok[i].angol);
    }
    return kesz;
}

class MySearch:public Window{
public:
    std::vector<std::string> val={"angol","magyar"};
    Kivalaszto *e_h;
    TextEdit *kszo;
    FunctorButton *ker;
    FunctorButton *ret;
    void talalat(){
    }
    void vissz(){
       // event_loop();
        //break ;
    }
    MySearch(){
        e_h = new Kivalaszto(10,40,100,25,50,val);
        kszo = new TextEdit(10,110,100,40,"Ide írj");
        ker = new FunctorButton(10,170,100,40,"Keresés",[this](){this->talalat();});
        ret = new FunctorButton(10,10,100,20,"<-",[this](){this->vissz();});
        widgets.push_back(e_h);
        widgets.push_back(kszo);
        widgets.push_back(ker);
        widgets.push_back(ret);
    }
};


class MyWindow:public Window{
public:
    MySearch *ker;
    Kivalaszto *kiv;
    StaticText *stx;
    StaticText *stxeng;
    StaticText *stxhun;
    TextEdit *eng;
    TextEdit *hun;
    //PushButton *button;
    FunctorButton *hadd;
    FunctorButton *kergomb;
    MyWindow();
    void keres(){
        ker = new MySearch;
        ker->event_loop_al();
    }
    void hozzaad(){
        //Innen folyt köv
    }
};

MyWindow::MyWindow(){

    hadd = new FunctorButton(10,40,100,40,"Új szó hozzádása",[this](){this->hozzaad();});
    kergomb = new FunctorButton(10,260,100,40,"Keresés",[this](){this->keres();});
    kiv = new Kivalaszto(300,40,200,25,400,Osszefesul());
    stx = new StaticText(300,20,0,0,"Angol és Magyar szavak");
    stxeng = new StaticText(10,180,0,0,"Angol szavak");
    stxhun = new StaticText(130,180,0,0,"Magyar szavak");
    eng = new TextEdit(10,200,100,40,"Ide írj");
    hun = new TextEdit(130,200,100,40,"Ide írj");
    widgets.push_back(eng);
    widgets.push_back(hun);
    widgets.push_back(stx);
    widgets.push_back(stxeng);
    widgets.push_back(stxhun);
    widgets.push_back(hadd);
    widgets.push_back(kergomb);
    widgets.push_back(kiv);
}










int main()
{
    gout.open(800,600);
    MyWindow *mywindow=new MyWindow;
    mywindow->event_loop();
    return 0;
}
