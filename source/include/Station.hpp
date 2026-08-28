#pragma once
#include <string>
#include <vector>

class Step;

// De Station klasse vertegenwoordigt een station in een grafiek van stations en stappen (verbindingen)
class Station {
private:
    std::string name;           // Naam van het station
    std::vector<Step*> steps;   // Lijst van stappen (verbindingen) die vanuit dit station vertrekken

public:
    // Constructor voor het initialiseren van een station met een naam
    Station(std::string name);

    // Methode om de naam van het station te verkrijgen
    std::string getName();

    // Methode om een stap toe te voegen aan de lijst van stappen
    void addStep(Step* step);

    // Methode om de lijst van stappen te verkrijgen
    std::vector<Step*> getSteps();
};