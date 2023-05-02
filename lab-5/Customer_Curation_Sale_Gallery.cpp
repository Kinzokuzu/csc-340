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

int Gallery::getCustomerID(std::string name, std::string email) const {
  int foundID = -1;

  for (const auto &c : customersList) {
    if (c.getName() == name && c.getEmail() == email) {
      foundID = c.getID();
    }
  }

  return foundID;
}

std::vector<int> Gallery::getIDsOfArtworksForSale() const {
  std::vector<int> listOfArtworkIDs;

  for (const auto &a : artworksForSale) {
    listOfArtworkIDs.push_back(a.getID());
  }

  return listOfArtworkIDs;
}

std::vector<int> Gallery::getIDsOfArtistsForSale() const {
  std::vector<int> listOfArtistIDs;

  for (const auto &a : artworksForSale) {
    listOfArtistIDs.push_back(a.getArtistID());
  }

  return listOfArtistIDs;
}


std::vector<std::pair<std::string, int>> Gallery::genArtworksReport(ReportType reportType) {
  std::vector<std::pair<std::string, int>> report;

  if (reportType == ReportType::artType) {
    std::pair<std::string, int> painting("painting", 0);
    std::pair<std::string, int> photography("photography", 0);
    std::pair<std::string, int> drawing("drawing", 0);
    std::pair<std::string, int> sculpture("sculpture", 0);
    std::pair<std::string, int> other("other", 0);

    for (const auto &a : artworksCurated) {
      if (toStr_ArtType(a.getType()) == "painting") {
        painting.second++;
      }
      else if (toStr_ArtType(a.getType()) == "photography") {
        photography.second++;
      }
      else if (toStr_ArtType(a.getType()) == "drawing") {
        drawing.second++;
      }
      else if (toStr_ArtType(a.getType()) == "sculpture") {
        sculpture.second++;
      }
      else if (toStr_ArtType(a.getType()) == "other") {
        other.second++;
      }
    }

    report.push_back(painting);
    report.push_back(photography);
    report.push_back(drawing);
    report.push_back(sculpture);
    report.push_back(other);
  }
  else if (reportType == ReportType::artStyle) {
    std::pair<std::string, int> fineArt("fineArt", 0);
    std::pair<std::string, int> abstract("abstract", 0);
    std::pair<std::string, int> modern("modern", 0);
    std::pair<std::string, int> popArt("popArt", 0);
    std::pair<std::string, int> other("other", 0);

    for (const auto &a : artworksCurated) {
      if (toStr_ArtStyle(a.getStyle()) == "fineArt") {
        fineArt.second++;
      }
      else if (toStr_ArtStyle(a.getStyle()) == "abstract") {
        abstract.second++;
      }
      else if (toStr_ArtStyle(a.getStyle()) == "modern") {
        modern.second++;
      }
      else if (toStr_ArtStyle(a.getStyle()) == "popArt") {
        popArt.second++;
      }
      else if (toStr_ArtStyle(a.getStyle()) == "other") {
        other.second++;
      }
    }

    report.push_back(fineArt);
    report.push_back(abstract);
    report.push_back(modern);
    report.push_back(popArt);
    report.push_back(other);
  }
  else if (reportType == ReportType::artSubject) {
    std::pair<std::string, int> nature("nature", 0);
    std::pair<std::string, int> portrait("portrait", 0);
    std::pair<std::string, int> animal("animal", 0);
    std::pair<std::string, int> cartoon("cartoon", 0);
    std::pair<std::string, int> other("other", 0);

    for (const auto &a : artworksCurated) {
      if (toStr_ArtSubject(a.getSubject()) == "nature") {
        nature.second++;
      }
      else if (toStr_ArtSubject(a.getSubject()) == "portrait") {
        portrait.second++;
      }
      else if (toStr_ArtSubject(a.getSubject()) == "animal") {
        animal.second++;
      }
      else if (toStr_ArtSubject(a.getSubject()) == "cartoon") {
        cartoon.second++;
      }
      else if (toStr_ArtSubject(a.getSubject()) == "other") {
        other.second++;
      }
    }

    report.push_back(nature);
    report.push_back(portrait);
    report.push_back(animal);
    report.push_back(cartoon);
    report.push_back(other);
  }

  return report;
}

// Gallery setters
void Gallery::setID(int theID) { ID = theID; }
void Gallery::setName(std::string theName) { name = theName; }
void Gallery::setAddress(std::string theAddr) { address = theAddr; }
void Gallery::setWebURL(std::string theURL) { webURL = theURL; }


int Gallery::addArtist(Artist artist) {
  int artistID = getArtistID(artist.getName(), artist.getEmail());
  // artistID = -1 if artist does not exist
  if (artistID < 0) {
    artist.setID(uniqueIDs::next_artistID());
    artistID = artist.getID();
    artistsList.push_back(artist);
  }

  return artistID;
}


int Gallery::addCustomer(Customer customer) {
  int customerID = getCustomerID(customer.getName(), customer.getEmail());

  if (customerID < 0) {
    customer.setID(uniqueIDs::next_customerID());
    customerID = customer.getID();
    customersList.push_back(customer);
  }

  return customerID;
}


void Gallery::curateArtwork(Artwork newItem, Artist artist) {
  // Return existing artist's ID or create a new one
  int artistID = getArtistID(artist.getName(), artist.getEmail());
  
  if (artistID < 0) {
    artist.setID(uniqueIDs::next_artistID());
    artistID = artist.getID();
    artistsList.push_back(artist);
  }

  newItem.setArtistID(artistID);
  artworksCurated.push_back(newItem);
  artworksForSale.push_back(newItem);

  Curation newCuration = Curation(newItem.getID(), artistID, getTodaysDate());
  addCuration(newCuration);
}


void Gallery::sellArtwork(int artworkID, Customer customer) {
  bool foundArtwork = false;
  int artworkPos;
  for (unsigned int i = 0; i < num_artworksForSale(); i++) {
    if (artworksForSale.at(i).getID() == artworkID) {
      foundArtwork = true;
      artworkPos = i;
      break;  
    } 
  }

  if (!foundArtwork) return;

  artworksForSale.erase(artworksForSale.begin() + artworkPos);

  int customerID = getCustomerID(customer.getName(), customer.getEmail());
  if (customerID < 0) {
    customer.setID(uniqueIDs::next_customerID());
    customerID = customer.getID();
    customersList.push_back(customer);
  }

  Sale newSale = Sale(customerID, artworkID, getTodaysDate());
  addSale(newSale);
}


void Gallery::addCuration(Curation curation) {
  if (curation.getArtworkID() > 0) {
    curationsRecords.push_back(curation);
  }

  return;
}


void Gallery::addSale(Sale sale) {
  if(sale.getCustomerID() > 0) {
    salesRecords.push_back(sale);
  }

  return;
}
// End class Gallery
}//end of NS_ARTGALLERY
