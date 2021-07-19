//!  * Section 13 Challenge
//!  * Movies.h
//!  * 
//!  * Models a collection of Movie as a std::vector
//!  * implement these methods in Movies.cpp
//!  *


#ifndef _MOVIES_H_

#include <vector>
#include "movie.h"
#include <iostream>

class Movies {
    // attributes
    // vector of type Movie - stores objects of Movie class
    std::vector<Movie> myMovieList;

public:

    // No-argumemt constructor
    Movies();

    // destructor
    ~Movies();

    // methods
    // to add new movie object to myMovieList vector
    bool addMovie(std::string name, std::string rating, unsigned int watched);

    // to increase the watched count
    bool incrementWatched(std::string name);

    // to display vector - myMovieList 
    void display();
};

#endif
