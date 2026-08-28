#include "include/Station.hpp"
#include "include/Step.hpp"

// Constructor voor het initialiseren van een station met een naam
Station::Station(std::string name) : name(name) {}

// Methode om de naam van het station te verkrijgen
std::string Station::getName() {
    return name;
}

// Methode om een stap toe te voegen aan de lijst van stappen
void Station::addStep(Step* step) {
    steps.push_back(step);
}

// Methode om de lijst van stappen te verkrijgen
std::vector<Step*> Station::getSteps() {
    return steps;
}