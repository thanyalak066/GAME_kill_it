#pragma warning(push,0)
#pragma warning(pop)
#pragma warning(disable : 26812)
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>
#include "Player.h"
#include "Collider.h"
#include <time.h>
#include "PLatform.h"
#include "hitboxComponent.h"
#include "Bullet.h"
#include "Enemy.h"
#include <string.h>
#include <sstream>
#include "bulletEnemy.h"
#include "menu.h"
#include "Pause.h"
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "KILL IT!!!", sf::Style::Close );//| sf::Style::Resize

    //texture
    sf::Texture playerTexture; // texture is type mean int,float , playerTexture is name of varible
    sf::Texture bullet;
    sf::Texture enemyBull;
    sf::Texture enemyTexture;
    sf::Texture playHP;
    sf::Texture indexMenu;

    playerTexture.loadFromFile("charactor/charactor16.png");
    Player player(&playerTexture, sf::Vector2u(4, 3), 0.1f, 350.0f, 300.0f);
     
    //bullet player
    sf::Vector2f pos;
    bullet.loadFromFile("bullets/bullet1.png");
    Bullet bulletPlayer(&bullet, sf::Vector2u(4,1), 0.1f, 1500.f, pos, sf::Vector2f(30.0f,8.75f), 1.0f);

    int bul = 0;
    int bul1 = 0;
    int ammunition = 5;
    int score = 0;

    // bullet enemy
    enemyBull.loadFromFile("bullets/bullet2");
    sf::RectangleShape bulletE(sf::Vector2f(10.0f,6.2f));
    bulletE.setTexture(&enemyBull);

    //playerHP
    playHP.loadFromFile("hp/playerHP.png");
    sf::RectangleShape HPbar(sf::Vector2f(262.0f, 94.0f));
    HPbar.setTexture(&playHP);

    int HP = 10;
    sf::RectangleShape playerHP(sf::Vector2f(HP * 20, 32));
    playerHP.setFillColor(sf::Color::Red);
    

    //enemy
    enemyTexture.loadFromFile("enemy/enemy12.png");
    //Enemy enemy(&enemyTexture, sf::Vector2u(4, 3), 0.3f, 300.0f, 300.0f);

    
    //hitbox
    HitboxComponent hitboxPlayer(0, 0, sf::Vector2f(46.f, 88.f), player.GetPosition());

    //HitboxComponent hitboxEnemy(0, 0, sf::Vector2f(50.0f, 75.0f), enemy.GetPosition());

    std::vector<PLatform> platforms;
    std::vector<Enemy> enemys;
    std::vector<bulletEnemy> enemyBullet;
    
    srand(time(NULL));
    for (int i = 0; i < 40; i++)
    {
        float r = ((rand() % 5900) + 800); // value > 1000 but < 13400
        enemys.push_back(Enemy(&enemyTexture, sf::Vector2u(4, 1), 0.3f, 300.0f, 300.0f, sf::Vector2f((float)r, 50.0f)));
        printf("%.2f\n", r);
    } 

    /*platforms.push_back(PLatform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f)));*/
    // enemy vector
    enemys.push_back(Enemy(&enemyTexture, sf::Vector2u(4, 3), 0.3f, 300.0f, 300.0f, sf::Vector2f(3014.0f,200.0f)));
    enemys.push_back(Enemy(&enemyTexture, sf::Vector2u(4, 3), 0.3f, 300.0f, 300.0f, sf::Vector2f(3099.0f,200.0f)));
    /*enemys.push_back(Enemy(&enemyTexture, sf::Vector2u(4, 3), 0.3f, 300.0f, 300.0f, sf::Vector2f(3014.0f,200.0f)));
    enemys.push_back(Enemy(&enemyTexture, sf::Vector2u(4, 3), 0.3f, 300.0f, 300.0f, sf::Vector2f(3014.0f,200.0f)));
    enemys.push_back(Enemy(&enemyTexture, sf::Vector2u(4, 3), 0.3f, 300.0f, 300.0f, sf::Vector2f(3014.0f,200.0f)));
    enemys.push_back(Enemy(&enemyTexture, sf::Vector2u(4, 3), 0.3f, 300.0f, 300.0f, sf::Vector2f(3014.0f,200.0f)));
    enemys.push_back(Enemy(&enemyTexture, sf::Vector2u(4, 3), 0.3f, 300.0f, 300.0f, sf::Vector2f(3014.0f,200.0f)));
    enemys.push_back(Enemy(&enemyTexture, sf::Vector2u(4, 3), 0.3f, 300.0f, 300.0f, sf::Vector2f(3014.0f,200.0f)));
    enemys.push_back(Enemy(&enemyTexture, sf::Vector2u(4, 3), 0.3f, 300.0f, 300.0f, sf::Vector2f(3014.0f,200.0f)));
    enemys.push_back(Enemy(&enemyTexture, sf::Vector2u(4, 3), 0.3f, 300.0f, 300.0f, sf::Vector2f(3014.0f,200.0f)));*/

    //frame1
    platforms.push_back(PLatform(nullptr, sf::Vector2f(6630.0f, 1.0f), sf::Vector2f(6630.0f, 0.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(6630.0f, 1.0f), sf::Vector2f(6630.0f, 720.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(1.0f, 800.0f), sf::Vector2f(1.0f, 360.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(1.0f, 800.0f), sf::Vector2f(6630.0f, 360.0f)));

    // platform for map1 ---------------------------------------------------------------------------------------------------------------------------------------------------
    platforms.push_back(PLatform(nullptr, sf::Vector2f(924.0f, 87.0f), sf::Vector2f(462.0f, 678.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(201.0f, 30.0f), sf::Vector2f(1027.0f, 705.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(5479.0f, 87.0f), sf::Vector2f(3892.0f, 677.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(472.0f, 120.0f), sf::Vector2f(2021.0f, 579.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(.0f, .0f), sf::Vector2f(.0f, .0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(.0f, .0f), sf::Vector2f(.0f, .0f)));

   
    // frame2
   /* platforms.push_back(PLatform(nullptr, sf::Vector2f(30030.0f, 1.0f), sf::Vector2f(1.0f, 0.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(30030.0f, 2.0f), sf::Vector2f(1.0f, 720.0f)));*/
    platforms.push_back(PLatform(nullptr, sf::Vector2f(1.0f, 800.0f), sf::Vector2f(14031.0f, 360.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(1.0f, 800.0f), sf::Vector2f(28061.5f, 360.0f)));
    
    //platform for map2 -----------------------------------------------------------------------------------------------------------------------------------------------------
    platforms.push_back(PLatform(nullptr, sf::Vector2f(6011.0f, 51.0f), sf::Vector2f(17036.0f, 497.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(97.0f, 184.0f), sf::Vector2f(20064.0f, 420.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(2284.0f, 184.0f), sf::Vector2f(21157.0f, 420.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(47.0f, 165.0f), sf::Vector2f(22276.0f, 410.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(748.0f, 33.0f), sf::Vector2f(22650.0f, 481.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(49.0f, 183.0f), sf::Vector2f(23037.0f, 413.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(715.0f, 39.0f), sf::Vector2f(23370.0f, 341.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(37.0f, 316.0f), sf::Vector2f(23709.0f, 479.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(627.0f, 28.0f), sf::Vector2f(24004.0f, 623.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(155.0f, 81.0f), sf::Vector2f(24380.0f, 597.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(283.0f, 104.0f), sf::Vector2f(24586.0f, 520.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(31.0f, 166.0f), sf::Vector2f(24712.0f, 551.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(765.0f, 29.0f), sf::Vector2f(25079.0f, 625.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(29.0f, 180.0f), sf::Vector2f(25459.0f, 552.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(164.0f, 28.0f), sf::Vector2f(25526.0f, 476.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(37.0f, 167.0f), sf::Vector2f(25606.0f, 407.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(282.0f, 167.0f), sf::Vector2f(25728.0f, 407.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(438.0f, 37.0f), sf::Vector2f(26078.0f, 481.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(36.0f, 172.0f), sf::Vector2f(26279.0f, 548.0f)));
    platforms.push_back(PLatform(nullptr, sf::Vector2f(1801.0f, 31.0f), sf::Vector2f(27162.0f, 624.0f)));

    //map1
    sf::Texture mapTexture1;
    mapTexture1.loadFromFile("maps/bgvenia.png");
    sf::RectangleShape map1(sf::Vector2f(6630.0f, 720.0f));
    map1.setPosition(0.0f, 0.0f);
    map1.setTexture(&mapTexture1);

    //map2
    sf::Texture mapTexture22;
    mapTexture22.loadFromFile("maps/map2.png");
    sf::RectangleShape map2(sf::Vector2f(14030.5f, 720.0f));
    map2.setPosition(14031.0f, 0.0f);
    map2.setTexture(&mapTexture22);

    //warp point
    sf::RectangleShape warpPoint(sf::Vector2f(200.0f, 200.0f));
    warpPoint.setFillColor(sf::Color::Red);
    warpPoint.setPosition(sf::Vector2f(13350.0f, 300.0f));

    //state
    int state = 1;

    //Index Menu
    Menu menu(window.getSize().x, window.getSize().y);
    indexMenu.loadFromFile("index_menu/Untitled-1.png");
    sf::RectangleShape menuIndex(sf::Vector2f(1080.0f, 720.0f));
    menuIndex.setTexture(&indexMenu);
    menuIndex.setPosition(sf::Vector2f(0.0f ,0.0f));
    int cheeckongame = 0;
    int howToPlay = 0;
    int highScore = 0;

    //View
    sf::View view;

    //Show time
    sf::Clock clocks;
    sf::Time time;
    std::ostringstream showtime;
    sf::Font font;
    font.loadFromFile("font/PressStart2P-vaV7.ttf");
    sf::Text lbltime;
    lbltime.setString(showtime.str());
    lbltime.setCharacterSize(40);
    lbltime.setFont(font);
    lbltime.setFillColor(sf::Color::Yellow);
    lbltime.setString(showtime.str());

    showtime.str(" ");
    showtime << "Time : ";
    lbltime.setPosition(view.getCenter().x + 240, view.getCenter().y - 360);

    // Pause menu
    Pause pause(window.getSize().x, window.getSize().y);

   bool faceright = true;
   //bool drawEnemy[10];
   int botHP[10] = { 3,3,3,3,3,3,3,3,3,3 };
   /*for (int i = 0; i < enemys.size(); i++)
   {
       sf::RectangleShape botHPBar[i](sf::Vector2f(botHP[i] * 10, 5));
       botHPBar[i].setFillColor(sf::Color::Red);
       botHPBar[i].setPosition(enemys[i].GetPosition().x, enemys[i].GetPosition().y);
   }*/
    float deltaTime = 0.0f;                  
    sf::Clock clock;

    //bool isFiring = false;

    while (window.isOpen()) 
    { 
        pos = player.GetPosition();
        if (cheeckongame == 1) {
            time = clocks.getElapsedTime();
            //time = sf::seconds((int)time.asSeconds() % 60);
            showtime << (int)time.asSeconds() / 60 << " : " << (int)time.asSeconds() % 60;
        }

        //std::cout << bulletPlayer.cooldown(deltaTime, bul) << std::endl;
        std::cout << ammunition << std::endl;

        deltaTime = clock.restart().asSeconds();
        if (deltaTime > 1.0f / 20.0f)
            deltaTime = 1.0f / 20.0f;

        sf::Event evnt;
        while (window.pollEvent(evnt)) {
            switch (evnt.type)
            {

            // Menu
            case sf::Event::KeyReleased:
                switch (evnt.key.code) {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;
                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;
                case sf::Keyboard::Return:
                    switch (menu.GetPressedItem())
                    {
                    case 0:
                        cheeckongame = 1; // check for into game
                        clocks = sf::Clock();
                        break;
                    case 1:
                        //std::cout << "2" << std::endl;
                        howToPlay = 1;
                        break;
                    case 2:
                        highScore = 1;
                        break;
                    case 3:
                        window.close();
                        break;
                    }
                }
                break;

            case sf::Event::Closed:
                window.close();
                break;
            /*case sf::Event::Resized:
                ResizeView(window, view);
                break;*/

            case sf::Event::TextEntered:
                if (evnt.text.unicode < 128)
                {
                    char show = evnt.text.unicode;
                    //std::cout << show << std::endl;  // Show input Keyboards
                }
            }

        } 
        //hitbox
        hitboxPlayer.Update(player.GetPosition(), -25.f, -45.f);

        sf::Vector2f direction;
        player.Update(deltaTime, direction); // player = class name ,Update = function name , (deltaTime) = parameter  
        for (int i = 0; i < enemys.size(); i++)
        {
            enemys[i].Update(deltaTime, direction);
        }
        

        for (PLatform& platform : platforms)
            //player
            if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
                player.OnCollision(direction);
        
        //enemy map 1
        for (int i = 0; i < enemys.size(); i++)
        {
            for (PLatform& platform : platforms)
            {   //enemy
                if (platform.GetCollider().CheckCollision(enemys[i].GetCollider1(), direction, 1.0f))
                    enemys[i].OnCollision1(direction);
            }
            if (bulletPlayer.GetCollider().CheckCollision(enemys[i].GetCollider1(), direction, 1.0f))
            {
                bul = 0;
                bulletPlayer.ready();
                bulletPlayer.setPosition(pos);
                enemys[i].updateHP(1);
            }
            if (enemys[i].getHP() <= 0 && enemys[i].GetPosition().x < 29000)
            {
                enemys[i].setPos(32000.0f, 100.0f);
                score += 5;
            }

        }
        
        // check intersect bullets
        /*for (int i = 0; i < enemys.size(); i++)
        {
            if(bulletPlayer.checkIntersect(enemys[i]);
        }*/

        
        view.setCenter(sf::Vector2f(player.GetPosition()));
        view.setSize(sf::Vector2f(1080.0f, 720.0f));

        // state 1
        if (player.GetPosition().x >= 0 && player.GetPosition().x < 6630.0f)
        {
            state = 1;

            if (view.getCenter().x - 540.0f <= 0.0f)
            {
                if (view.getCenter().y - 360.0f <= 0.0f)
                {
                    view.setCenter(sf::Vector2f(540.0f, 360.0f));
                }
                if (view.getCenter().y + 360.0f >= 720.0f)
                {
                    view.setCenter(sf::Vector2f(540.0f, 360.0f));
                }
            }
            if (view.getCenter().x + 540.0f >= 6630.0f)
            {
                if (view.getCenter().y - 360.0f <= 0.0f)
                {
                    view.setCenter(sf::Vector2f(6090.0f, 360.0f));
                }
                if (view.getCenter().y + 360.0f >= 720.0f)
                {
                    view.setCenter(sf::Vector2f(6090.0f, 360.0f));
                }
            }
            if (view.getCenter().x - 540.0f > 0.0f && view.getCenter().x + 540.0f < 6630.0f)
            {
                if (view.getCenter().y - 360.0f <= 0.0f)
                {
                    view.setCenter(sf::Vector2f(player.GetPosition().x, 360.0f));
                }
                if (view.getCenter().y + 360.0f >= 720.0f)
                {
                    view.setCenter(sf::Vector2f(player.GetPosition().x, 360.0f));
                }
            }
        }
        //state 2
        if (player.GetPosition().x >= 14031.0f)
        {
            state = 2;

            if (view.getCenter().x - 540.0f <= 14031.0f)
            {
                if (view.getCenter().y - 360.0f <= 0.0f)
                {
                    view.setCenter(sf::Vector2f(14571.0f, 360.0f));
                }
                if (view.getCenter().y + 360.0f >= 720.0f)
                {
                    view.setCenter(sf::Vector2f(14571.0f, 360.0f));
                }
            }
            if (view.getCenter().x + 540.0f >= 28061.5f)
            {
                if (view.getCenter().y - 360.0f <= 0.0f)
                {
                    view.setCenter(sf::Vector2f(27521.5f, 360.0f));
                }
                if (view.getCenter().y + 360.0f >= 720.0f)
                {
                    view.setCenter(sf::Vector2f(27521.5f, 360.0f));
                }
            }
            if (view.getCenter().x - 540.0f > 14031.0f && view.getCenter().x + 540.0f < 28061.5f)
            {
                if (view.getCenter().y - 360.0f <= 0.0f)
                {
                    view.setCenter(sf::Vector2f(player.GetPosition().x, 360.0f));
                }
                if (view.getCenter().y + 360.0f >= 720.0f)
                {
                    view.setCenter(sf::Vector2f(player.GetPosition().x, 360.0f));
                }
            }

        }

        playerHP.setPosition(view.getCenter().x - 468, view.getCenter().y - 322);//(sf::Vector2f(72.0f, 38.0f)
        HPbar.setPosition(view.getCenter().x - 516, view.getCenter().y - 342);  //(sf::Vector2f(24.0f, 18.0f));
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
             faceright = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
             faceright = false;
        }
        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && bul == 0 && bulletPlayer.cooldown(deltaTime, bul) >= 5.0f)
        {
            if ( faceright == true)
            {
                bul = 1;
                bulletPlayer.attackR(pos);
            }
            if ( faceright == false)
            {
                bul = -1;
                bulletPlayer.attackL(pos);
            }
        }*/
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if (ammunition > 0)
            {
                if (faceright == true)
                {
                    bul = 1;
                    bulletPlayer.attackR(pos);
                }
                if (faceright == false)
                {
                    bul = -1;
                    bulletPlayer.attackL(pos);
                }
                ammunition -= 1;
                
            }
            else
            {
                bulletPlayer.cooldown(deltaTime, bul); // >= 5.0f;
                  
                ammunition = 5;
            }
        }

        //Show time
        lbltime.setString(showtime.str());

        showtime.str(" ");
        showtime << " Time  :  ";
        lbltime.setPosition(view.getCenter().x + 200, view.getCenter().y - 340);

        window.clear();
        
        if (cheeckongame == 0)
        {
            // Menu
            window.draw(menuIndex);
            menu.draw(window);
            //Stop.draw(window);
        }
        if (cheeckongame == 1)
        {
            for (PLatform& platform : platforms)
                platform.Draw(window);

            //map1
            window.draw(map1);

            //map2
            window.draw(map2);

            //hp player
            window.draw(playerHP);
            window.draw(HPbar);

            window.setView(view);

            //(player.GetCollider().CheckCollision(Collider(warpPoint)))

            window.draw(warpPoint);
            // state 1
            if (hitboxPlayer.checkIntersect(warpPoint.getGlobalBounds()))
            {
                player.stateChange(window);
            }

            player.Draw(window);
            //enemy.draw(window);   

            //hitbox
            //hitboxPlayer.Draw(window);

            for (int i = 0; i < enemys.size(); i++)
            {
                if (botHP[i] > 0)
                {
                    enemys[i].Draw(window);
                    //window.draw();
                }
            }

            if (bul == 1)
            {
                bulletPlayer.updateR(deltaTime);
                bulletPlayer.draw(window);
            }
            if (bul == -1)
            {
                bulletPlayer.updateL(deltaTime);
                bulletPlayer.draw(window);
            }
            if (abs(bulletPlayer.GetPosition().x - player.GetPosition().x) >= 1000.0f)
            {
                bul = 0;
                bulletPlayer.ready();
                bulletPlayer.setPosition(pos);
            }
        }
        if (howToPlay == 1)
        {
            
        }
        if (highScore == 1)
        {

        }

        window.display();
    }
}

//window.draw(bulletPlayer);
        /*if (isFiring == true)
        {
            BulletP newBullet(sf::Vector2f(50, 5));
            newBullet.setPos(sf::Vector2f(player.getX(), player.getY()));
            bulletVector.push_back(newBullet);
        }

        for (int i = 0; i < bulletVector.size(); i++)
        {
            bulletVector[i].Draw(window);
            bulletVector[i].Fire(3);
        }*/
