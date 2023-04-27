//
//  Customer_Curation_Sale_Gallery.cpp
//  ArtGallerySimplified
//
//  implement/define the member functions of the following classes:
//     1. class Customer; 2. class Curation; 3. class Sale; 4. class ArtGallery
//
//created by: Saul Cervantes-Hernandez
//date:  

#include "Customer_Curation_Sale_Gallery.h"

namespace NS_ARTGALLERY{
   
 //  implement/define the member functions of the following classes:
//     1. class Customer; 2. class Curation; 3. class Sale; 4. class ArtGallery
// Begin class Customer
Customer::Customer() {
    ID = -1;
    name = "na";
    email = "na";
    address = "na";
}

Customer::Customer(int theID, std::string theName, std::string theEmail,
  const std::string theAddr) {
  ID = theID;
  name = theName;
  email = theEmail;
  address = theAddr;
}

// Customer getters
int Customer::getID() const { return ID; }
std::string Customer::getName() const { return name; }
std::string Customer::getEmail() const { return email; }
std::string Customer::getAddress() const { return address; }

// Customer setters
void Customer::setID(int theID) { ID = theID; }
void Customer::setName(std::string theName) { name = theName; }
void Customer::setEmail(std::string theEmail) { email = theEmail; }
void Customer::setAddress(std::string theAddress) { address = theAddress; }
// End class Customer

// Begin class Curation
Curation::Curation() {
  artworkID = -1;
  artistID = -1;
  curationDate = {1, 1, 2022};
}

Curation::Curation(int theArtworkID, int theArtistID, Date theDate) {
  artworkID = theArtworkID;
  artistID = theArtistID;
  curationDate = theDate;
}

// Curation getters
int Curation::getArtworkID() const { return artworkID; }
int Curation::getArtistID() const { return artistID; }
Date Curation::getCurationDate() const { return curationDate; }

// Curation setters
void Curation::setArtworkID(int theID) { artworkID = theID; }
void Curation::setArtistID(int theID) { artistID = theID; }
void Curation::setCurationDate(Date theDate) { curationDate = theDate; }
// End class Curation

// Begin class Sale
Sale::Sale() {
  customerID = -1;
  artworkID = -1;
  saleDate = {1, 1, 2022};
}

Sale::Sale(int theCustomerID, int theArtworkID, Date theDate) {
  customerID = theCustomerID;
  artworkID = theArtworkID;
  saleDate = theDate;
}

// Sale getters
int Sale::getCustomerID() const { return customerID; }
int Sale::getArtworkID() const { return artworkID; }
Date Sale::getSaleDate() const { return saleDate; }

// Sale setters
void Sale::setCustomerID(int theID) { customerID = theID; }
void Sale::setArtworkID(int theID) { artworkID = theID; }
void Sale::setSaleDate(Date theDate) { saleDate = theDate; }
// End class Sale

// Begin class Gallery
Gallery::Gallery() {
  ID = -1;
  name = "na";
  address = "na";
  webURL = "na";
}

// Gallery getters
int Gallery::getID() const { return ID; }
std::string Gallery::getName() const { return name; }
std::string Gallery::getAddress() const { return address; }
std::string Gallery::getWebURL() const { return webURL; }
unsigned long Gallery::num_artists() const { return artistsList.size(); }
unsigned long Gallery::num_artworksCurated() const { return artworksCurated.size(); }
unsigned long Gallery::num_artworksForSale() const { return artworksForSale.size(); }
unsigned long Gallery::num_customers() const { return customersList.size(); }
unsigned long Gallery::num_curations() const { return curationsRecords.size(); }
unsigned long Gallery::num_sales() const { return salesRecords.size(); }

int Gallery::getArtistID(std::string name, std::string email) const {
  int foundID = -1;

  for (const auto &a : artistsList) {
    if (a.getName() == name && a.getEmail() == email) {
      foundID = a.getID();
    }
  }

  return foundID;
}

int Gallery::getCustomerID(std::string name, std::string email) const {}

std::vector<int> Gallery::getIDsOfArtworksForSale() const {}

std::vector<int> Gallery::getIDsOfArtistsForSale() const {}


std::vector<std::pair<std::string, int>> Gallery::genArtworksReport(ReportType reportType) {}

// Gallery setters
void Gallery::setID(int theID) { ID = theID; }
void Gallery::setName(std::string theName) { name = theName; }
void Gallery::setAddress(std::string theAddr) { address = theAddr; }
void Gallery::setWebURL(std::string theURL) { webURL = theURL; }


int Gallery::addArtist(Artist artist) {}


int Gallery::addCustomer(Customer customer) {}


void Gallery::curateArtwork(Artwork newItem, Artist artist) {}


void Gallery::sellArtwork(int artworkID, Customer customer) {}


void Gallery::addCuration(Curation curation) {}


void Gallery::addSale(Sale sale) {}
// End class Gallery
}//end of NS_ARTGALLERY
