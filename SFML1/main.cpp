#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <sstream>
#include <ctime>
#include <iostream>
#include<time.h>
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600
using namespace sf;
using namespace std;
int menustage=0;
int mouse_button=0;
bool sfx_sound=true;
bool oprit=false;
int n=0;
int size=32;
int iepurici=0;
int vulpici=0;
int sepoatemuta=0;
int mutaig=0,mutaim=0,mutaia=0,mutavp=0;

int main()
{
    //srand(time(0));
    Clock clock, clock2,clock3,clock4,clock5,clock7,clock8,clock10,clock11; //clock titlu clock2 play clock3 instructiuni clock4 sunet clock5 exitbm


    ///Window aplicatie
    RenderWindow window(VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT),"JumpIN"); ///FEREASTRA JOC
    ///Muzica si sunete
    sf::SoundBuffer buffer_mleft, buffer_gameOver, buffer_gameWin, buffer_wrong;
    sf::Sound sound_mleft, sound_flag, sound_unflag, sound_gameOver, sound_gameWin, sound_wrong;  ///SUNETE SI MUZICA///
    sf::Music music, mainmenu;

    if (!buffer_mleft.loadFromFile("sounds/click.wav") ||
            !buffer_gameOver.loadFromFile("sounds/gameOver.wav") ||
            !buffer_gameWin.loadFromFile("sounds/gameWin.wav") ||
            !buffer_wrong.loadFromFile("sounds/wrong.wav") ||
            !music.openFromFile("sounds/music.ogg") ||
            !mainmenu.openFromFile("sounds/mainmenu.ogg"))
    {
        std::cout << "can't find something in sounds :(" << std::endl;
    } /// SUNETE FISERE LOAD ///
    /// MUZICA REGLATA ///
    music.setPitch(1);
    music.setVolume(35);
    music.setLoop(true);

    mainmenu.setPitch(1);
    mainmenu.setVolume(30);
    mainmenu.setLoop(true);
    sound_mleft.setBuffer(buffer_mleft);
    sound_gameOver.setBuffer(buffer_gameOver);
    sound_gameWin.setBuffer(buffer_gameWin);
    sound_wrong.setBuffer(buffer_wrong);


///
/// Load the textures
///
    Texture butoninstr,butonplay,butonsunet,anivel1,anivel2,iepuremarotransparent,iepurealb,iepurealbtransparent,vulpetoataorizontal,vulpetoataorizontaltransparent,iepuregritransparent,vulpetoata,playmeniu,playresume,iepuregri, iepuremaro,ciuperca,meniubutoane,meniuculoare,tabla,titlutext,vulpe,instructiuni,exitbuton,vulpetransparenta;///TEXTURI//
    if (!iepuregri.loadFromFile("imagini/iepuregri.png") ||
            !iepuremaro.loadFromFile("imagini/iepuremaro.png") ||
            !ciuperca.loadFromFile("imagini/ciuperca.png") ||
            !meniuculoare.loadFromFile("imagini/meniuculoare.png") ||
            !tabla.loadFromFile("imagini/tabla.png") ||
            !butoninstr.loadFromFile("imagini/instrbuton.png") ||
            !titlutext.loadFromFile("imagini/titlutext.png")||
            !instructiuni.loadFromFile("imagini/instructiuni.png")||
            !exitbuton.loadFromFile("imagini/meniubutoane.png")||
            !vulpetransparenta.loadFromFile("imagini/vulpetoatatransparent.png")||
            !playmeniu.loadFromFile("imagini/meniuresume.png")||
            !playresume.loadFromFile("imagini/meniuresume.png")||
            !vulpetoata.loadFromFile("imagini/vulpetoata.png")||
            !iepuregritransparent.loadFromFile("imagini/iepuregritransparent.png")||
            !iepuremarotransparent.loadFromFile("imagini/iepuremarotransparent.png")||
            !vulpetoataorizontal.loadFromFile("imagini/vulpetoataorizontal.png")||
            !vulpetoataorizontaltransparent.loadFromFile("imagini/vulpetoatatransparent.png")||
            !iepurealb.loadFromFile("imagini/iepurealb.png")||
            !iepurealbtransparent.loadFromFile("imagini/iepurealbtransparent.png")||
            !anivel1.loadFromFile("imagini/1.png")||
            !anivel2.loadFromFile("imagini/2.png")||
            !meniubutoane.loadFromFile("imagini/meniubutoane.png")||
            !butonplay.loadFromFile("imagini/playbuton.png")||
            !butonsunet.loadFromFile("imagini/sunetbuton.png"))
    {
        std::cout << "can't find all images :(" << std::endl;
    }
    IntRect dimensiune1(0,0,200,200),dimensiune2(0,0,200,200),dimensiuneResume(0,0,400,100),dimensiuneMeniu(0,100,400,100),dimensiuneTitlu(0,0,400,100),dimensiunePlay(0,0,93,79),dimensiuneInstr(0,0,93,79),dimensiuneSunet(0,0,93,59), dimensiuneExitB(61,238,31,31);///PENTRU ANIMATII///
    sf::Sprite alegnivel1(anivel1),alegnivel2(anivel2),ia(iepurealb),iat(iepurealbtransparent),imt(iepuremarotransparent),vo(vulpetoataorizontal),vot(vulpetoataorizontaltransparent),igt(iepuregritransparent),playm(playmeniu),playr(playresume),vt(vulpetransparenta),vp(vulpetoata),exitb(exitbuton),ig(iepuregri), im(iepuremaro), c1(ciuperca),c2(ciuperca),c3(ciuperca), meniup(butonplay),meniui(butoninstr),menius(butonsunet), meniuc(meniuculoare), t(tabla), v(vulpe),title(titlutext),instr(instructiuni);
    title.setPosition(100.f,50.f);
    meniup.setPosition(250.f,240.f);
    meniui.setPosition(250.f,319.f);
    menius.setPosition(250.f,398.f);
    exitb.setPosition(569.f,0.f);
    ///POZITII "BUTOANE SI PIESE"
    playm.setPosition(100.f,150.f);
    playr.setPosition(100.f,350.f);


    bool isMove=false;
    float dx=0, dy=0;
    mainmenu.play();  ///DAI DRUMUL LA MUZICA
    while(window.isOpen())
    {
        sf::Vector2i pos = sf::Mouse::getPosition(window);
        int mouseX = pos.x;
        int mouseY = pos.y;

        switch(menustage)
        {
        case 0:

            sf::Event main_menu;

            if(window.isOpen())
            {
                if(clock.getElapsedTime().asSeconds()>1.0f)
                {
                    if(dimensiuneTitlu.left==800)
                    {
                        dimensiuneTitlu.left=0;
                    }
                    else
                    {
                        dimensiuneTitlu.left+=400;
                    }
                    title.setTextureRect(dimensiuneTitlu);
                    clock.restart();
                }//animatie titlu

                if(clock2.getElapsedTime().asSeconds()>1.0f)
                {
                    if(dimensiunePlay.left==93)
                        dimensiunePlay.left=0;
                    else
                        dimensiunePlay.left+=93;
                    meniup.setTextureRect(dimensiunePlay);
                    clock2.restart();
                }//animatie play

                if(clock3.getElapsedTime().asSeconds()>1.0f)
                {
                    if(dimensiuneInstr.left==93)
                        dimensiuneInstr.left=0;
                    else
                        dimensiuneInstr.left+=93;
                    meniui.setTextureRect(dimensiuneInstr);
                    clock3.restart();
                }//animaite instructiuni

                if(clock4.getElapsedTime().asSeconds()>1.0f)
                {
                    if(dimensiuneSunet.left==93)
                        dimensiuneSunet.left=0;
                    else
                        dimensiuneSunet.left+=93;
                    menius.setTextureRect(dimensiuneSunet);
                    clock4.restart();
                }//animatie sunet

                //window.clear();
                window.draw(meniuc);
                window.draw(title);
                window.draw(meniup);
                window.draw(meniui);
                window.draw(menius);

            }
            while(window.pollEvent(main_menu))
            {
                if(main_menu.type==Event::Closed)
                    window.close();
                if(main_menu.type==Event::MouseButtonPressed)
                {
                    if(main_menu.key.code==Mouse::Left)
                    {
                        if(meniup.getGlobalBounds().contains(pos.x,pos.y))
                        {
                            menustage=3;
                            if(sfx_sound)
                                sound_mleft.play();
                        }
                        if(meniui.getGlobalBounds().contains(pos.x,pos.y))
                        {
                            menustage=2;
                            if(sfx_sound)
                                sound_mleft.play();
                        }
                        if(menius.getGlobalBounds().contains(pos.x,pos.y))
                        {
                            if(oprit==false)
                            {
                                mainmenu.stop();
                                oprit=true;
                            }
                            else
                            {
                                mainmenu.play();
                                oprit=false;
                            }
                            if (sfx_sound)
                                sound_mleft.play();
                        }
                    }
                }
            }

            window.display();
            break;


        case 3:
            sf::Event alegenivel;
            if(window.isOpen())
            {
                if(clock10.getElapsedTime().asSeconds()>1.0f)
                {
                    if(dimensiune1.left==200)
                    {
                        dimensiune1.left=0;
                    }
                    else
                    {
                        dimensiune1.left+=200;
                    }
                    alegnivel1.setTextureRect(dimensiune1);
                    clock10.restart();
                }//animatie 1

                if(clock11.getElapsedTime().asSeconds()>1.0f)
                {
                    if(dimensiune2.left==200)
                        dimensiune2.left=0;
                    else
                        dimensiune2.left+=200;
                    alegnivel2.setTextureRect(dimensiune2);
                    clock11.restart();
                }//animatie 2
                window.draw(meniuc);
                window.draw(alegnivel1);
                window.draw(alegnivel2);
            }
            alegnivel1.setPosition(200,70);
            alegnivel2.setPosition(200,330);

            while(window.pollEvent(alegenivel))
            {
                if(alegenivel.type==Event::Closed)
                    window.close();
                if(alegenivel.type==Event::MouseButtonPressed)
                {
                    if(alegnivel1.getGlobalBounds().contains(pos.x,pos.y))
                    {
                        menustage=9;
                        if (sfx_sound)
                            sound_mleft.play();
                        ig.setPosition(256,136);
                        c1.setPosition(256,16);
                        c2.setPosition(256,376);
                        c3.setPosition(496,256);
                        vp.setPosition(360,120);
                        igt.setPosition(496,16);
                        vt.setPosition(360,0);
                                            cout<<"ALEGETI PIESE PENTRU A MUTA ASTFEL INCAT SA AJUNGETI LA POZITIA LOR (MARCATA DE PIESELE TRANSPARENTE)";
                    cout<<endl;
                    cout<<"PENTRU A VA INTOARCE LA MENIU APASATI TASTA ESC";
                    cout<<endl;
                    cout<<endl;
                    }
                    if(alegnivel2.getGlobalBounds().contains(pos.x,pos.y))
                    {
                        menustage=8;
                        if (sfx_sound)
                            sound_mleft.play();
                        ig.setPosition(376,16);
                        c1.setPosition(376,136);
                        c2.setPosition(256,496);
                        im.setPosition(496,256);
                        vo.setPosition(360,360);
                        ia.setPosition(136,496);
                        vp.setPosition(120,0);


                        vt.setPosition(120,360);
                        igt.setPosition(16,496);
                        vot.setPosition(360,360);
                        imt.setPosition(256,256);
                        iat.setPosition(496,496);
                                            cout<<"ALEGETI PIESE PENTRU A MUTA ASTFEL INCAT SA AJUNGETI LA POZITIA LOR (MARCATA DE PIESELE TRANSPARENTE)";
                    cout<<endl;
                    cout<<"PENTRU A VA INTOARCE LA MENIU APASATI TASTA ESC";
                    cout<<endl;
                    cout<<endl;
                    }
                }
            }
                        if(sf::Keyboard::isKeyPressed(Keyboard::Escape))
            {
                menustage=0;


            }
            window.display();
            break;









        case 9:



            sf::Event play;


            if(window.isOpen())
            {


                //window.clear();
                window.draw(t);
                window.draw(igt);
                window.draw(vt);
                window.draw(vp);
                window.draw(ig);
                window.draw(c1);
                window.draw(c2);
                window.draw(c3);
                ///window.draw(ig);
                //window.display();
            }



            while(window.pollEvent(play)==true)
            {
                if(play.type==Event::Closed)
                    window.close();

                if(iepurici==0)
                {


                    if(play.type == Event::MouseButtonPressed)
                    {
                        if(play.key.code== Mouse::Left)
                        {

                            if(ig.getGlobalBounds().contains(pos.x,pos.y) )
                            {
                                ig.setPosition(496,136);
                                iepurici++;
                                cout<<"Mutare corecta"<<'\n';
                                cout<<endl;
                                cout<<endl;
                                if(sfx_sound)
                                    sound_mleft.play();
                            }
                            else
                            {
                                cout<<"Piesa gresita,incearca iepurele gri"<<'\n';
                                cout<<endl;
                                if(sfx_sound)
                                    sound_mleft.play();
                            }

                        }

                    }
                }

                if(iepurici==1)
                {
                    if(play.type == Event::MouseButtonPressed)
                    {
                        if(play.key.code== Mouse::Left)
                        {
                            if(ig.getGlobalBounds().contains(pos.x,pos.y) )
                            {
                                ig.setPosition(496,376);
                                iepurici++;
                                cout<<"Mutare corecta";
                                cout<<endl;
                                cout<<endl;
                                if(sfx_sound)
                                    sound_mleft.play();
                            }
                            else
                            {
                                cout<<"Piesa gresita,incearca iepurele gri";
                                cout<<endl;
                                cout<<endl;
                                if(sfx_sound)
                                    sound_mleft.play();
                            }
                        }
                    }
                }

                if(vulpici==0&&iepurici==2)
                {
                    if(play.type == Event::MouseButtonPressed)
                    {
                        if(play.key.code== Mouse::Left)
                        {
                            if(vp.getGlobalBounds().contains(pos.x,pos.y) )
                            {
                                vp.setPosition(360,240);
                                vulpici++;
                                cout<<"Mutare corecta";
                                cout<<endl;
                                cout<<endl;
                                if(sfx_sound)
                                    sound_mleft.play();
                            }
                            else
                            {
                                cout<<"Piesa gresita, incearca vulpea";
                                cout<<endl;
                                cout<<endl;
                                if(sfx_sound)
                                    sound_mleft.play();
                            }
                        }
                    }
                }
                if(iepurici==2&&vulpici==1)
                {
                    if(play.type == Event::MouseButtonPressed)
                    {
                        if(play.key.code== Mouse::Left)
                        {
                            if(ig.getGlobalBounds().contains(pos.x,pos.y) )
                            {
                                ig.setPosition(136,376);
                                iepurici++;
                                cout<<"Mutare corecta"<<endl;
                                cout<<endl;
                                if(sfx_sound)
                                    sound_mleft.play();
                            }
                            else
                            {
                                cout<<"Piesa gresita, incearca iepurele gri";
                                cout<<endl;
                                cout<<endl;
                                if(sfx_sound)
                                    sound_mleft.play();
                            }
                        }
                    }
                }
                if(vulpici==1&&iepurici==3)
                {
                    if(play.type == Event::MouseButtonPressed)
                    {
                        if(play.key.code== Mouse::Left)
                        {
                            if(vp.getGlobalBounds().contains(pos.x,pos.y) )
                            {
                                vp.setPosition(360,120);
                                vulpici++;
                                cout<<"Mutare corecta";
                                cout<<endl;
                                cout<<endl;
                                if(sfx_sound)
                                    sound_mleft.play();
                            }
                            else
                            {
                                cout<<"Piesa gresita, incearca vulpea";
                                cout<<endl;
                                cout<<endl;
                                if(sfx_sound)
                                    sound_mleft.play();
                            }

                        }
                    }
                }
                if(iepurici==3&&vulpici==2)
                {
                    if(play.type == Event::MouseButtonPressed)
                    {
                        if(play.key.code== Mouse::Left)
                        {
                            if(ig.getGlobalBounds().contains(pos.x,pos.y) )
                            {
                                ig.setPosition(376,376);
                                iepurici++;
                                cout<<"Mutare corecta";
                                cout<<endl;
                                cout<<endl;
                                if(sfx_sound)
                                    sound_mleft.play();
                            }
                            else
                            {
                                cout<<"Piesa gresita incearca iepurele gri";
                                cout<<endl;
                                cout<<endl;
                                if(sfx_sound)
                                    sound_mleft.play();
                            }
                        }
                    }
                }
                if(iepurici==4&&vulpici==2)
                {
                    if(play.type == Event::MouseButtonPressed)
                    {
                        if(play.key.code== Mouse::Left)
                        {

                            if(ig.getGlobalBounds().contains(pos.x,pos.y) )
                            {
                                ig.setPosition(376,16);
                                iepurici++;
                                cout<<"Mutare corecta";
                                cout<<endl;
                                cout<<endl;
                                if(sfx_sound)
                                    sound_mleft.play();
                            }
                            else
                            {
                                cout<<"Piesa gresita, incearca iepurele gri";
                                cout<<endl;
                                cout<<endl;
                                if(sfx_sound)
                                    sound_mleft.play();
                            }
                        }
                    }
                }
                if(iepurici==5&&vulpici==2)
                {
                    if(play.type == Event::MouseButtonPressed)
                    {
                        if(play.key.code== Mouse::Left)
                        {
                            if(ig.getGlobalBounds().contains(pos.x,pos.y) )
                            {

                                ig.setPosition(136,16);
                                iepurici++;
                                cout<<"Mutare corecta";
                                cout<<endl;
                                cout<<endl;
                                if(sfx_sound)
                                    sound_mleft.play();

                            }
                            else
                            {
                                cout<<"Piesa gresita, incearca iepurele gri";
                                cout<<endl;
                                cout<<endl;
                                if(sfx_sound)
                                    sound_mleft.play();
                            }
                        }
                    }
                }


                if(vulpici==2&&iepurici==6)
                {
                    if(play.type == Event::MouseButtonPressed)
                    {
                        if(play.key.code== Mouse::Left)
                        {
                            if(vp.getGlobalBounds().contains(pos.x,pos.y) )
                            {
                                vp.setPosition(360,0);
                                vulpici++;
                                cout<<"Mutare corecta";
                                cout<<endl;
                                cout<<endl;
                                if(sfx_sound)
                                    sound_mleft.play();
                            }
                            else
                            {
                                cout<<"Piesa gresita, incearca vulpea";
                                cout<<endl;
                                cout<<endl;
                                if(sfx_sound)
                                    sound_mleft.play();
                            }
                        }
                    }
                }
                if(iepurici==6&&vulpici==3)
                {
                    if(play.type == Event::MouseButtonPressed)
                    {
                        if(play.key.code== Mouse::Left)
                        {
                            if(ig.getGlobalBounds().contains(pos.x,pos.y) )
                            {
                                ig.setPosition(496,16);
                                iepurici++;
                                cout<<"Game Over.You won!";
                                cout<<endl;
                                cout<<endl;
                                menustage=0;
                                if(sfx_sound)
                                    sound_mleft.play();
                            }
                            else
                            {
                                cout<<"Piesa gresita,incearca iepurele gri";
                                cout<<endl;
                                cout<<endl;
                                if(sfx_sound)
                                    sound_mleft.play();
                            }
                        }
                    }
                }



            }

            if(sf::Keyboard::isKeyPressed(Keyboard::Escape))
            {
                menustage=0;
                iepurici=0;
                vulpici=0;

            }




            window.display();
            break;


        case 8:
            sf::Event nivel2;

            if(window.isOpen())
            {


                //window.clear();
                window.draw(t);
                window.draw(im);
                window.draw(imt);
                window.draw(igt);
                window.draw(vt);
                window.draw(vp);
                window.draw(vot);
                window.draw(vo);
                window.draw(ig);
                window.draw(c1);
                window.draw(c2);
                window.draw(ia);
                window.draw(iat);

                ///window.draw(ig);
                //window.display();
            }


            while(window.pollEvent(nivel2)==true)
            {
                if(nivel2.type==Event::Closed)
                    window.close();
                if(mutaig==0)
                {


                    if(nivel2.type==Event::MouseButtonPressed)
                    {
                        if(ig.getGlobalBounds().contains(pos.x,pos.y))
                        {
                            ig.setPosition(376,256);
                            mutaig++;
                            cout<<"Mutare corecta";
                            cout<<endl;
                            cout<<endl;
                            if(sfx_sound)
                                sound_mleft.play();
                        }
                        else
                        {
                            cout<<"Piesa gresita, incearca iepurele gri";
                            cout<<endl;
                            cout<<endl;
                            if(sfx_sound)
                                sound_mleft.play();
                        }
                    }
                }

                if(mutaig==1&&mutaim==0)
                {
                    if(nivel2.type==Event::MouseButtonPressed)
                    {
                        if(im.getGlobalBounds().contains(pos.x,pos.y))
                        {
                            im.setPosition(256,256);
                            mutaim++;
                            cout<<"Mutare corecta";
                            cout<<endl;
                            cout<<endl;
                            if(sfx_sound)
                                sound_mleft.play();
                        }
                        else
                        {
                            cout<<"Piesa gresita, incearca iepurele maro";
                            cout<<endl;
                            cout<<endl;
                            if(sfx_sound)
                                sound_mleft.play();
                        }
                    }
                }

                if(mutaig==1&&mutaim==1)
                {
                    if(nivel2.type==Event::MouseButtonPressed)
                    {
                        if(ig.getGlobalBounds().contains(pos.x,pos.y))
                        {
                            ig.setPosition(376,496);
                            mutaig++;
                            cout<<"Mutare corecta";
                            cout<<endl;
                            cout<<endl;
                            if(sfx_sound)
                                sound_mleft.play();
                        }
                        else
                        {
                            cout<<"Piesa gresita, incearca iepurele gri";
                            cout<<endl;
                            cout<<endl;
                            if(sfx_sound)
                                sound_mleft.play();
                        }
                    }
                }

                if(mutaig==2&&mutaim==1&&mutaia==0)
                {
                    if(nivel2.type==Event::MouseButtonPressed)
                    {
                        if(ia.getGlobalBounds().contains(pos.x,pos.y))
                        {
                            ia.setPosition(496,496);
                            mutaia++;
                            cout<<"Mutare corecta";
                            cout<<endl;
                            cout<<endl;
                            if(sfx_sound)
                                sound_mleft.play();
                        }
                        else
                        {
                            cout<<"Piesa gresita, incearca iepurele alb";
                            cout<<endl;
                            cout<<endl;
                            if(sfx_sound)
                                sound_mleft.play();
                        }
                    }
                }

                if(mutaig==2&&mutaim==1&&mutaia==1&&mutavp==0)
                {
                    if(nivel2.type==Event::MouseButtonPressed)
                    {
                        if(vp.getGlobalBounds().contains(pos.x,pos.y))
                        {
                            vp.setPosition(120,360);
                            mutavp++;
                            cout<<"Mutare corecta";
                            cout<<endl;
                            cout<<endl;
                            if(sfx_sound)
                                sound_mleft.play();
                        }
                        else
                        {
                            cout<<"Piesa gresita, incearca vulpea";
                            cout<<endl;
                            cout<<endl;
                            if(sfx_sound)
                                sound_mleft.play();
                        }
                    }
                }

                if(mutaig==2&&mutaim==1&&mutaia==1&&mutavp==1)
                {
                    if(nivel2.type==Event::MouseButtonPressed)
                    {
                        if(ig.getGlobalBounds().contains(pos.x,pos.y))
                        {
                            ig.setPosition(120,360);
                            mutaig++;
                            cout<<"Game over. You win!";
                            cout<<endl;
                            cout<<endl;
                            menustage=0;
                            if(sfx_sound)
                                sound_mleft.play();
                        }
                        else
                        {
                            cout<<"Piesa gresita, incearca iepurele alb";
                            cout<<endl;
                            cout<<endl;
                            if(sfx_sound)
                                sound_mleft.play();
                        }
                    }
                }


            }
            if(sf::Keyboard::isKeyPressed(Keyboard::Escape))
            {
                menustage=0;
                mutaig=0;
                mutaia=0;
                mutaim=0;
                mutavp=0;

            }
            window.display();
            break;












        case 2:
            sf::Event instructiuni;
            if(window.isOpen())
            {
                if(clock5.getElapsedTime().asMilliseconds()>1.0f)
                {
                    if(dimensiuneExitB.left==93)
                    {
                        dimensiuneExitB.left=61;
                    }
                    else
                    {
                        dimensiuneExitB.left+=32;
                    }
                    exitb.setTextureRect(dimensiuneExitB);
                    clock5.restart();
                }


                window.draw(instr);
                window.draw(exitb);
                //window.display();
            }


            while (window.pollEvent(instructiuni))
            {
                switch (instructiuni.type)
                {
                case sf::Event::MouseButtonPressed:
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        mouse_button = 1;
                case sf::Event::MouseButtonReleased:
                    if (mouse_button)
                    {
                        mouse_button = 0;
                        if (mouseY >=0 && mouseY<=31&&mouseX>=569&&mouseX<=600)
                        {
                            menustage = 0;
                            //display_size = true;
                            if (sfx_sound)
                                sound_mleft.play();
                            window.clear();
                        }
                    }
                    break;
                default:
                    break;
                }

                window.display();
                break;

            }
        }
    }
}


