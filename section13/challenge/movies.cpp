//!  * Section 13 Challenge
//!  * Movies.h - implimentation movies.h
//!  * 
//!  * Models a collection of Movies as a std::vector
//!  * 

#include "movies.h"

// No-argumemt constructor
Movies::Movies () {}

// destructor
Movies::~Movies () {}

// to add new movie object to myMovieList vector
bool Movies::addMovie(std::string nameL, std::string ratingL, unsigned int watchedL) {
    // searching the movie in the myMovieList vector
    // const refecence to each Movie object of Movies vector myMovieList
    for(const auto &movie: myMovieList) {
        if(movie.getName() == nameL) {
            return false;   // if already exists
        }
    }
    // new element is not exist in vector
    //then a new Movie object is created and added to vector myMovieList
    // 1 - Movie constructor is called
    // 2 - push_back Movie obj in Movies vector 
    myMovieList.push_back(Movie(nameL, ratingL, watchedL));
    return true;
}

// to increase the watched count
bool Movies::incrementWatched(std::string nameL) {
    // searching the movie in the myMovieList vector
    // const refecence to each Movie object of Movies vector myMovieList
    for(auto &movie: myMovieList) {
        if(movie.getName() == nameL) {
            // increase watched count of found Movie object
            movie.setWatched();
            return true;    // successfully incremented watched
        }
    }
    // if movie is not found
    return false;
}

void Movies::display() {
    // checks whether Movies vector - myMovieList is empty
    if (myMovieList.size()) {
        std::cout << "\n===============================================================" << std::endl;
        // itterate though Movies vector and print each Movie object attribute 
        for (const auto &movieObj:myMovieList) {
            std::cout << movieObj.getName() << ", " << movieObj.getRating() << ", " << movieObj.getWatch() << std::endl;
        }
        std::cout << "===============================================================\n" << std::endl;
    }
    else {
        std::cout << "Sorry, no movies to display" << std::endl;
    }
}
