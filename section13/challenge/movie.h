//!  * Section 13 Challenge
//!  * Movie.h
//!  * 
//!  * Models a Movie with the following atttributes
//!  * 
//!  * std::string name - the name of the movie 
//!  * std::string rating - G, PG, PG-13, R
//!  * int watched - the number of times you've watched the movie


#ifndef _MOVIE_H_

#define _MOVIE_H_

#include <string>

class Movie {
    //attributes

    std::string name;           // movie's name
    std::string rating;         // movie's rating - (G, PG, PG-13, R) 
    unsigned int watched;             // the number of times the movie has been watched

public:
    // default constructor expecting all 3 arguments
    Movie (std::string name = "none", std::string rating = "none", unsigned int watched = 0);

    // copy constructor
    Movie (const Movie &);

    // destructor
    ~Movie();

    // methords
    // getter functions
    std::string getName() const;
    std::string getRating() const;
    unsigned int getWatch() const;

    // setter methods
    // increase weatched count by 1
    void setWatched();
};

#endif
