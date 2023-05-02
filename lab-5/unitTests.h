
//
//  unitTests.h
//  ArtGallerySimplified
//
//unit-test a few member functions for each class
//
//  Created by Hui Yang on 3/23/22.
//

#ifndef unitTests_h
#define unitTests_h

#include "Artwork_Artist.h"
#include "Customer_Curation_Sale_Gallery.h"

namespace NS_UTESTS{

using namespace NS_ARTGALLERY;

//class Artwork; a partial unit testing.
//write one unit test each for the following member functions of the Artwork class
//  . default constructor and accessors --->bool test_Artwork();
//  . setStyle() and getStyle()    --->bool test_set_getStyle_Artwork();
//  . setDimension(), getWidth(), getHeight() and getDepth() --->bool test_setDimension_Artwork();
bool test_Artwork() {
  bool result = true;

  Artwork art;

  if (art.getID() != -1) { result = false; }
  if (art.getArtistID() != -1) { result = false; }
  if (art.getType() != ArtType::painting) { result = false; }
  if (art.getStyle() != ArtStyle::fineArt) { result = false; }
  if (art.getYearMade() != 2022) { result = false; }
  if (art.getWidth() != 0.00) { result = false; }
  if (art.getHeight() != 0.00) { result = false; }
  if (art.getDepth() != 0.00) { result = false; }
  if (art.getPrice() != 0.00) { result = false; }

  return result;
}

bool test_set_getStyle_Artwork() {
  bool result = true;

  Artwork art;
  art.setStyle(ArtStyle::abstract);
  if (art.getStyle() != ArtStyle::abstract) { result = false; }

  return result;
}

bool test_setDimension_Artwork() {
  bool result = true;

  Artwork art;
  art.setDimension(1.00, 2.00, 3.00);
  if (art.getWidth() != 1.00) { result = false; }
  if (art.getHeight() != 2.00) { result = false; }
  if (art.getDepth() != 3.00) { result = false; }

  return result;
}

//class Artist; a partial unit testing.
//write one unit test each for the following member functions of the Artist class
// .default constructor and accessors -->bool test_Artist();
// .setID() and getID()--->bool test_set_getID_Artist();

bool test_Artist() {
  bool result = true;

  Artist artist;

  if (artist.getID() != -1) { result = false; }
  if (artist.getName() != "na") { result = false; }
  if (artist.getEmail() != "na") { result = false; }
  if (artist.getBirthYear() != 1900) { result = false; }
  if (artist.getBirthPlace() != "na") { result = false; }
  if (artist.getPrimaryArtType() != ArtType::painting) { result = false; }

  return result;
}

bool test_set_getID_Artist() {
  bool result = true;

  Artist artist;
  artist.setID(123);
  if (artist.getID() != 123) { result = false; }

  return result;
}

//class Customer; a partial unit testing.
//write one unit test each for the following member functions of the Customer class
// .the parameterized constructor and accessors -->bool test_Customer2();
// .setName() and getName()--->bool test_set_getName_Customer();

bool test_Customer2() {
  bool result = true;

  Customer customer = Customer(123, "John", "john@mail.com", "123 Street");
  if (customer.getID() != 123) { result = false; }
  if (customer.getName() != "John") { result = false; }
  if (customer.getEmail() != "john@mail.com") { result = false; }
  if (customer.getAddress() != "123 Street") { result = false; }

  return result;
}

bool test_set_getName_Customer() {
  bool result = true;

  Customer customer;
  customer.setName("John");
  if (customer.getName() != "John") { result = false; }

  return result;
}

//class Curation; a partial unit testing.
//write one unit test each for the following member functions of the Curation class
// .the parameterized constructor and accessors -->bool test_Curation2();
// .setCurationDate() and getCurationDate()--->bool test_set_getDate_Curation();

bool test_Curation2() {
  bool result = true;
  
  Curation curation = Curation(123, 321, getTodaysDate());

  if (curation.getArtworkID() != 123) { result = false; }
  if (curation.getArtistID() != 321) { result = false; }
  if (!(curation.getCurationDate() == getTodaysDate())) { result = false; }

  return result;
}

bool test_set_getDate_Curation() {
  bool result = true;

  Curation curation;
  curation.setCurationDate(getTodaysDate());
  if (!(curation.getCurationDate() == getTodaysDate())) { result = false; }

  return result;
}

//class Sale; a partial unit testing.
//write one unit test each for the following member functions of the Sale class
// .the parameterized constructor and accessors -->bool test_Sale2();
// .setCustomerID() and getCustomerID()--->bool test_set_getCustomerID_Sale();

bool test_Sale2() {
  bool result = true;

  Sale sale = Sale(123, 321, getTodaysDate());

  if (sale.getCustomerID() != 123) { result = false; }
  if (sale.getArtworkID() != 321) { result = false; }
  if (!(sale.getSaleDate() == getTodaysDate())) { result = false; }

  return result;
}

bool test_set_getCustomerID_Sale() {
  bool result = true;

  Sale sale;
  sale.setCustomerID(123);
  if (sale.getCustomerID() != 123) { result = false; }

  return result;
}

//class Gallery; a partial unit testing.
//write one unit test for the Gallery::getArtistID() function correspoinding to either of the two
//scenarios: exist/doesn't exist
//  bool test_getArtistID_Gallery();

bool test_getArtistID_Gallery() {
  bool result = true;

  Gallery gal;
  if (gal.getArtistID("John", "john@mail.com") != -1) { result = false; }

  return result;
}

//write one unit test for the Gallery::getCustomerID() function, correspoinding to either of the two
//scenarios: exist/doesn't exist
//  bool test_getCustomerID_Gallery();

bool test_getCustomerID_Gallery() {
  bool result = true;

  Gallery gal;
  if (gal.getCustomerID("John", "john@mail.com") != -1) { result = false; }

  return result;
}

//write one unit test for the Gallery::getIDsOfArtworksForSale() function. Make sure your
//artworksForSale is not empty.
// bool test_getIDsOfArtistsForSale_Gallery();

bool test_getIDsOfArtistsForSale_Gallery() {
  bool result = true;

  Gallery gal;
  Artwork artwork;
  Artist artist;
  gal.curateArtwork(artwork, artist);
  std::vector<int> id_list = gal.getIDsOfArtworksForSale();

  if (id_list.size() <= 0) { result = false; }

  return result;
}

//write one unit test for the Gallery::getIDsOfArtworksForSale() function. Make sure your
//artworksForSale is not empty. This test will call the curateArtwork() function.
// bool test_getIDsOfArtworksForSale_Gallery();

bool test_getIDsOfArtworksForSale_Gallery() {
  bool result = true;

  Gallery gal;
  Artwork artwork;
  Artist artist;
  gal.curateArtwork(artwork, artist);
  std::vector<int> id_list = gal.getIDsOfArtworksForSale();

  if (id_list.size() <= 0) { result = false; }

  return result;
}

//write one unit test for the genArtworksReport() based on ArtType
//   bool test_genArtworksReport_artType_Gallery();


// Write one unit test for Gallery::curateArtwork().
//  bool test_curateArtwork_Gallery();

//write one unit test for the Gallery::sellArtwork() function
//  bool test_sellArtwork_Gallery();

}//end-of namespace NS_UTESTS
#endif