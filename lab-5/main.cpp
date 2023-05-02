//
//  main.cpp
//  ArtGallerySimplified
//
//created by Saul Cervantes-Hernandez
//date: 

#include <iostream>
#include "util_date_uniqueIDs.h"
#include "unitTests.h"

//please feel free to create a text-based user interface to manage an art gallery 

int main() {
    using namespace NS_ARTGALLERY;
    using namespace NS_UTESTS;
    
    //call your unit tests 
    std::cout << test_Artwork() << std::endl;
    std::cout << test_set_getStyle_Artwork() << std::endl;
    std::cout << test_setDimension_Artwork() << std::endl;

    std::cout << test_Artist() << std::endl;
    std::cout << test_set_getID_Artist() << std::endl;

    std::cout << test_Customer2() << std::endl;
    std::cout << test_set_getName_Customer() << std::endl;

    std::cout << test_Curation2() << std::endl;
    std::cout << test_set_getDate_Curation() << std::endl;

    std::cout << test_Sale2() << std::endl;
    std::cout << test_set_getCustomerID_Sale() << std::endl;

    std::cout << test_getArtistID_Gallery() << std::endl;

    std::cout << test_getCustomerID_Gallery() << std::endl;

    std::cout << test_getIDsOfArtistsForSale_Gallery() << std::endl;

    std::cout << test_getIDsOfArtworksForSale_Gallery() << std::endl;
    
    return 0;
}
  
