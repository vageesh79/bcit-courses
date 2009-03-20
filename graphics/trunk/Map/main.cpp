#include "user_map.h"

void genRandomMap(int[][] map);

SDL_Surface *load_image( std::string filename )
{
	SDL_RWops *rwop;
	rwop=SDL_RWFromFile(filename.c_str(), "rb");
	
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;
	
	if(IMG_isGIF(rwop))
		loadedImage = IMG_LoadGIF_RW(rwop);
    else
        //Load the image
    	loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );

        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }

    //Return the optimized surface
    return optimizedImage;
}

int main()
{
	int map[17][18];/*={{00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00,00},
			{00, 01, 01, 02, 02, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 00,00},
			{00, 01, 00, 01, 00, 01, 00, 01, 00, 01, 00, 01, 00, 01, 00, 01, 00,00},
			{00,01, 01, 01, 01, 02, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 00, 00},
			{00, 01 ,00, 01, 00, 02 ,00, 01, 00 ,01, 00, 01, 00, 01 ,00 ,01, 00,00},
			{00, 01, 01, 01, 01, 02, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 00,00},
			{00, 01, 00, 01, 00, 02, 00, 01, 00, 02, 00, 02, 00, 02, 00, 01, 00,00}
			} ;*/
			
	genRandomMap(map);		
	SDL_Surface *image_set = load_image( "empty.xcf" );;
	int numImages = 3;
	int width = 18;
	int height = 7;
	for( int i = 0 , j = 0 ; i < 306; i++)
		{
			if (i %18 == 0 )
			{
				printf("\n");
				j++;
			}
			printf("%d",map[j][i%18]);
		}
		 
	//user_map::user_map *uMap = new user_map(map,image_set,numImages,width,height);
}


