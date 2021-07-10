//!  * Section 13 Challenge
//!  * Movie.cpp - implimemtation of movie.h
//!  * 
//!  * Models a Movie with the following atttributes
//!  * 
//!  * std::string name - the name of the movie 
//!  * std::string rating - G, PG, PG-13, R
//!  * int watched - the number of times you've watched the movie


#include "Movie.h"

// default constructor expecting all 3 arguments
Movie::Movie (std::string name, std::string rating, unsigned int watched) 
    : name {name}, rating {rating}, watched {watched} { }

// copy constructor
Movie::Movie (const Movie &sourceObj) 
    : Movie {sourceObj.name, sourceObj.rating, sourceObj.watched} { }

// destructor
Movie::~Movie() { }

// methords
// name getter
std::string Movie::getName() const {
    return name;
}
std::string Movie::getRating() const {
    return rating;
} 
unsigned int Movie::getWatch() const {
    return watched;
}

// setter methods
// increase weatched count by 1
void Movie::setWatched() {
    ++watched;
}
