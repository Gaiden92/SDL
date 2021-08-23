#include <exception>
#include <string>
#include <iostream>
#include <SDL.h>


int main( int argc, char * argv[] )
{
    if(SDL_Init(SDL_INIT_VIDEO)== -1 ){                                                                 // Démarrage de la SDL (ici : chargement du système vidéo)

    fprintf(stderr, "La SDL a rencontre l\'erreur suivante: %s ", SDL_GetError());                      //la fonction SDL_GetError() renvoie l'erreur qui a été généré.

    return EXIT_FAILURE;                                                                                //on quitte le programme

    }

    //Création de notre fenetre
    SDL_Window* window;
    window = SDL_CreateWindow("ma fenetre", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, SDL_WINDOW_RESIZABLE);


    if(window == NULL){
     fprintf(stderr, "L\'ouverture de la fenetre a echoue: %s", SDL_GetError());                        //Test de la création de la fenetre
        return EXIT_FAILURE;

    }

    //Création du renderer
    SDL_Renderer* monrenderer;
    monrenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(monrenderer == NULL){
        fprintf(stderr, "Erreur lors de la creation du renderer : %s", SDL_GetError());               //Test de la création du renderer
        return EXIT_FAILURE;
    }

    SDL_RenderPresent(monrenderer);                                                                   //On applique le rendu a ma fenetre

    //On décide des couleurs puis on test
    Uint8 r = 255;
    Uint8 g = 160;
    Uint8 b = 160;
    Uint8 a = 255;
    if(SDL_SetRenderDrawColor(monrenderer, r, g, b, a) < 0){
         fprintf(stderr, "Erreur lors de la creation des couleurs : %s", SDL_GetError());
            return EXIT_FAILURE;
    }

                                                               //On applique le rendu a ma fenetre

    //Dessiner des points



    /*Dessiner une droite avec des points
    SDL_Point points[27];
    for(int i = 0; i != 27;i++){
        points[i].x = i+4;
        points[i].y = i + 27;
    }
    SDL_RenderDrawPoints(monrenderer, points, 27);
    SDL_RenderPresent(monrenderer);



     //Dessiner une droite
   SDL_RenderDrawLine(monrenderer, 100, 250,300,350);
   SDL_RenderPresent(monrenderer);
*/
    //Dessiner un triangle

    /*SDL_Point triangle[4];
    triangle[0].x = triangle[0].y = 100;
    triangle[1].x = triangle[1].y = 200;
    triangle[2].x = 300;
    triangle[2].y = 50;
    triangle[3] = triangle[0];




    SDL_RenderDrawLines(monrenderer, triangle, 4);
    SDL_RenderPresent(monrenderer);
    */
/*
    //Dessiner rectangle manuellement
    SDL_Point rectangle[5];
    rectangle[0].x = rectangle[0].y = 100;
    rectangle[1].x = rectangle[0].x;
    rectangle[1].y = rectangle[0].y + 100;
    rectangle[2].x = rectangle[1].x + 200;
    rectangle[2].y = rectangle[0].y + 100;
    rectangle[3].x = rectangle[2].x;
    rectangle[3].y = rectangle[2].y - 100;
    rectangle[4] = rectangle[0];

    SDL_RenderDrawLines(monrenderer, rectangle, 5);
    SDL_RenderPresent(monrenderer);


    //Dessiner un rectangle avec fonction prete

    SDL_Rect rectangle = {100,100,200,100};

    SDL_RenderDrawRect(monrenderer, &rectangle);
    SDL_RenderPresent(monrenderer);


    //dessiner plusieurs rectangle
    SDL_Rect rectangle1 = {0,0,400,400};
    SDL_Rect rectangle2 = {100,100,300,50};
    SDL_Rect rectangle3 = {20,20,50,120};
    SDL_Rect rectangle4 = {40,40,100,50};
    SDL_Rect rectangle5 = {300,300,100,50};

    SDL_RenderDrawRects(monrenderer, &rectangle5, 5);
    SDL_RenderPresent(monrenderer);

    //Remplir un rectangle
    SDL_Rect rectangle = {200,200,40,10};
    SDL_RenderFillRect(monrenderer, &rectangle);
    SDL_RenderPresent(monrenderer);


    //Remplir plusieurs rectangle
    SDL_Rect rectangle = {0,0,100,50};

    SDL_Rect rectangle2 = {0,350,100,50};

    SDL_RenderFillRects(monrenderer, &rectangle2, 2);
    SDL_RenderPresent(monrenderer);
         */

    //Créer une zone de travail
    SDL_Rect rectangledetravail = {150,150,100,50};



    SDL_RenderDrawLine(monrenderer, 0,0,150,150);
    SDL_RenderPresent(monrenderer);
    SDL_RenderSetViewport(monrenderer, &rectangledetravail);

    SDL_RenderPresent(monrenderer);
    SDL_Delay(10000);

    SDL_DestroyRenderer(monrenderer);                                                                   //destruction du renderer

    SDL_DestroyWindow(window);                                                                          //destruction de la fenetre


    SDL_VideoQuit();                                                                                    // Arrêt de la SDL (libération de la mémoire).

    return EXIT_SUCCESS;
}
